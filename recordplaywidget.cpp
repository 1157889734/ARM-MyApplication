#include "recordplaywidget.h"
#include "ui_recordplaywidget.h"
#include <QStyleFactory>
#include <QDateTime>
#include <event.h>
#include <QKeyEvent>
#include <QMouseEvent>
#include "state.h"
#include "log.h"
#include <QDebug>
#include "qplayer.h"
#include "myslider.h"
#include <QSlider>
#include <QMessageBox>
#include <QDebug>
#include <QLineEdit>
int g_iDateEditNo = 0;      //要显示时间的不同控件的编号
static int g_iRNum = 0;
#define PVMSPAGETYPE  2    //此页面类型，2表示受电弓监控页面
pthread_mutex_t g_sliderValueSetMutex;


recordPlayWidget *g_recordPlayThis = NULL;
#define FTP_SERVER_PORT  21   //FTP服务器默认通信端口
static char *parseFileName(char *pcSrcStr);


void PftpProc(PFTP_HANDLE PHandle, int iPos)     //回调函数处理接收到的进度条进度, iPos为进度百分比
{
    if (PHandle != g_recordPlayThis->m_tFtpHandle[g_recordPlayThis->m_iFtpServerIdex])
    {
        return;
    }

    g_recordPlayThis->triggerDownloadProcessBarDisplaySignal(1);   //显示进度条

    g_recordPlayThis->triggerSetDownloadProcessBarValueSignal(iPos);

    if ((100 == iPos) || (-1 == iPos) || (-2 == iPos) || (-3 == iPos))  //iPos=100,表示下载完毕。暂定iPos=-1表示被告知U盘已拔出, iPos=-2表示被告知U盘写入失败,iPos=-3表示被告知数据接收失败失败。 三种情况都隐藏进度条，并在信号处理函数中销毁FTP连接
    {
        g_recordPlayThis->triggerDownloadProcessBarDisplaySignal(0);
    }

    return ;
}

recordPlayWidget::recordPlayWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recordPlayWidget)
{
    int i = 0;
    QString string = "";
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);


    ui->fileDownloadProgressBar->hide();
    ui->fileDownloadProgressBar->setRange(0,100);

    ui->alarmPushButton->setFocusPolicy(Qt::NoFocus);


    m_playSlider = new mySlider(this);    //创建播放进度条
    m_playSlider->setOrientation(Qt::Horizontal);    //设置水平方向
    m_playSlider->setGeometry(290, 545, 650, 35);
    m_playSlider->show();
    /*定义播放进度条样式*/
    m_playSlider->setStyleSheet("QSlider::groove:horizontal{border: 1px solid #4A708B;background: #C0C0C0;height: 5px;border-radius: 1px;padding-left:-1px;padding-right:-1px;}"
                                "QSlider::sub-page:horizontal{background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #B1B1B1,stop:1 #c4c4c4);background:qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,stop: 0 #5DCCFF,stop: 1 #1874CD);border: 1px solid #4A708B;height: 10px;border-radius: 2px;}"
                                "QSlider::add-page:horizontal{background: #575757;border: 0px solid #777;height: 10px;border-radius: 2px;}"
                                "QSlider::handle:horizontal{background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5,stop:0.6 #45ADED, stop:0.778409 rgba(255, 255, 255, 255));width: 11px;margin-top: -3px;margin-bottom: -3px;border-radius: 5px;}"
                                "QSlider::handle:horizontal:hover{background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #2A8BDA,stop:0.778409 rgba(255, 255, 255, 255));width: 11px;margin-top: -3px;margin-bottom: -3px;border-radius: 5px;}"
                                "QSlider::sub-page:horizontal:disabled{background: #00009C;border-color: #999;}"
                                "QSlider::add-page:horizontal:disabled{background: #eee;border-color: #999;}"
                                "QSlider::handle:horizontal:disabled{background: #eee;border: 1px solid #aaa;border-radius: 4px;}");

    connect(m_playSlider, SIGNAL(presliderPressSianal(int)), this, SLOT(playSliderPressSlot(int)));   //点击进度条信号响应
    connect(m_playSlider, SIGNAL(presliderMoveSianal(int)), this, SLOT(playSliderMoveSlot(int)));   //拖动进度条信号响应



    m_tableWidgetStyle = QStyleFactory::create("windows");
    ui->recordFileTableWidget->setStyle(m_tableWidgetStyle);   //设置tablewidget显示风格为windows风格，否则里面的checkbox选中默认显示叉而不是勾
    ui->recordFileTableWidget->setFocusPolicy(Qt::NoFocus);
    ui->recordFileTableWidget->setShowGrid(true);



    ui->recordFileTableWidget->horizontalHeader()->setSectionsClickable(false); //设置表头不可点击
    ui->recordFileTableWidget->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
    ui->recordFileTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
    ui->recordFileTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置整行选中方式
    ui->recordFileTableWidget->setSelectionMode(QAbstractItemView::NoSelection); //设置只能选择一行，不能多行选中
//    ui->recordFileTableWidget->setAlternatingRowColors(true);                        //设置隔一行变一颜色，即：一灰一白
    ui->recordFileTableWidget->horizontalHeader()->resizeSection(0,46); //设置表头第一列的宽度为46
    ui->recordFileTableWidget->horizontalHeader()->resizeSection(1,46);
    ui->recordFileTableWidget->horizontalHeader()->resizeSection(2,280);
//    ui->recordFileTableWidget->resizeColumnToContents(2);
    ui->recordFileTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);


    ui->playPushButton->setFocusPolicy(Qt::NoFocus);
    ui->stopPushButton->setFocusPolicy(Qt::NoFocus);
    ui->playLastOnePushButton->setFocusPolicy(Qt::NoFocus);
    ui->playNextOnePushButton->setFocusPolicy(Qt::NoFocus);
    ui->fastForwardPushButton->setFocusPolicy(Qt::NoFocus);
    ui->slowForwardPushButton->setFocusPolicy(Qt::NoFocus);
    ui->plusStepPushButton->setFocusPolicy(Qt::NoFocus);
    ui->minusStepPushButton->setFocusPolicy(Qt::NoFocus);
//    ui->playSpeedLineEdit->setFocusPolicy(Qt::NoFocus);

    //参数初始化
    m_alarmHappenTimer = NULL;
    m_recorQueryTimer = NULL;
    m_recordTabelWidgetFillTimer = NULL;

    m_cmpHandle = NULL;

    m_iPlayRange = 0;

    m_iPlayFlag = 0;
    m_iRecordIdex = -1;
    m_iSliderValue = 0;
    m_threadId = 0;
    m_pcRecordFileBuf = (char *)malloc(MAX_RECORD_SEACH_NUM*MAX_RECFILE_PATH_LEN);

    for (i = 0; i < MAX_SERVER_NUM; i++)
    {
        m_Phandle[i] = 0;
        m_tFtpHandle[i] = 0;
    }


    setPlayButtonStyleSheet();
    getTrainConfig();

    m_playWin = new QWidget(this);
    m_playWin->setGeometry(290, 0, 734, 540);
    m_playWin->show();
    m_playWin->setStyleSheet("QWidget{background-color: rgb(0, 0, 0);}");

    ui->StartdateEdit->setCalendarPopup(true);
    ui->StartdateEdit->setDate(QDate::currentDate());

    ui->EnddateEdit->setCalendarPopup(true);
    ui->EnddateEdit->setDate(QDate::currentDate());


    ui->StartdateEdit->dumpObjectTree();
    QLineEdit* lEdit = ui->StartdateEdit->findChild<QLineEdit*>();
    if(lEdit)
        lEdit->setReadOnly(true);


    ui->EnddateEdit->dumpObjectTree();
    QLineEdit* lEdit2 = ui->EnddateEdit->findChild<QLineEdit*>();
    if(lEdit2)
        lEdit2->setReadOnly(true);


    int value = QTime::currentTime().hour();
    ui->EndcomboBox->setCurrentIndex(value);
    ui->StartcomboBox->setCurrentIndex(0);


    connect(ui->alarmPushButton, SIGNAL(clicked(bool)), this, SLOT(alarmPushButoonClickSlot()));   //报警按钮按键信号响应打开报警信息界面
    connect(ui->canselPushButton, SIGNAL(clicked()), this, SLOT(registOutButtonClick()));

    connect(ui->queryPushButton, SIGNAL(clicked(bool)), this, SLOT(recordQuerySlot()));    //录像查询按钮按键信号响应
    connect(ui->downLoadPushButton, SIGNAL(clicked(bool)), this, SLOT(recordDownloadSlot()));    //录像下载按钮按键信号响应
    connect(ui->playPushButton, SIGNAL(clicked(bool)), this, SLOT(recordPlayStartSlot()));	   //播放按钮按键信号响应
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(recordPauseSlot()));
    connect(ui->stopPushButton, SIGNAL(clicked(bool)), this, SLOT(recordPlayStopSlot()));		//停止按钮按键信号响应
    connect(ui->fastForwardPushButton, SIGNAL(clicked(bool)), this, SLOT(recordPlayFastForwardSlot()));    //快进按钮按键信号响应
    connect(ui->slowForwardPushButton, SIGNAL(clicked(bool)), this, SLOT(recordPlaySlowForwardSlot()));    //慢放按钮按键信号响应
    connect(ui->playLastOnePushButton, SIGNAL(clicked(bool)), this, SLOT(recordPlayLastOneSlot()));    //播放上一个按钮按键信号响应
    connect(ui->playNextOnePushButton, SIGNAL(clicked(bool)), this, SLOT(recordPlayNextOneSlot()));	 //播放下一个按钮按键信号响应
    connect(ui->plusStepPushButton, SIGNAL(pressed()), this, SLOT(playPlusStepSlot()));   //拖动进度条信号响应
    connect(ui->minusStepPushButton, SIGNAL(pressed()), this, SLOT(playMinusStepSlot()));   //拖动进度条信号响应


    connect(ui->recordFileTableWidget, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(recordSelectionSlot(QTableWidgetItem*)));  //单击录像文件列表某行触发信号连接相应槽函数
    connect(ui->recordFileTableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(recordPlaySlot(QTableWidgetItem*)));  //双击录像文件列表某行触发信号连接相应槽函数
    connect(ui->carSeletionComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(carNoChangeSlot()));  //车厢选择下拉框当前索引改变信号响应



    connect(this, SIGNAL(setSliderValueSignal(int)), this, SLOT(setPlaySliderValueSlot(int)));
    connect(this, SIGNAL(downloadProcessBarDisplaySignal(int)), this, SLOT(downloadProcessBarDisplaySlot(int)));
    connect(this, SIGNAL(setDownloadProcessBarValueSignal(int)), this, SLOT(setDownloadProcessBarValueSlot(int)));
    connect(this, SIGNAL(closeRecordPlaySignal()), this, SLOT(closeRecordPlaySlot()));

    connect(this, SIGNAL(recordTableWidgetFillSignal()), this, SLOT(recordTableWidgetFillSlot()));
    connect(this, SIGNAL(setRangeLabelSignal()), this, SLOT(setRangeLabelSlot()));
    connect(this, SIGNAL(recordSeletPlay(QTableWidgetItem *)), this, SLOT(recordPlaySlot(QTableWidgetItem*)));

    g_recordPlayThis = this;

}

recordPlayWidget::~recordPlayWidget()
{

    pthread_mutex_destroy(&g_sliderValueSetMutex);
    closePlayWin();

    if (m_tableWidgetStyle != NULL)
    {
        delete m_tableWidgetStyle;
        m_tableWidgetStyle = NULL;
    }
    for (int i = 0; i < MAX_SERVER_NUM; i++)
    {
        if (m_tFtpHandle[i] != 0)
        {
            FTP_DestoryConnect(m_tFtpHandle[i]);
            m_tFtpHandle[i] = 0;
        }
    }

    delete m_playSlider;
    m_playSlider = NULL;
    delete m_playWin;
    m_playWin = NULL;


    free(m_pcRecordFileBuf);
    m_pcRecordFileBuf = NULL;

    delete ui;
}

void recordPlayWidget::playSliderMoveSlot(int iPosTime)
{
    QString playSpeedStr = "";

//    DebugPrint(DEBUG_UI_OPTION_PRINT, "recordPlayWidget  press play slider!\n");

    if (iPosTime < 0)
    {
        return;
    }
    else if (iPosTime == m_playSlider->value())    //时间值没有变化不进行处理
    {
//        DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] value is not change, do not set!\n", __FUNCTION__);
        return;
    }
    else if (0 == iPosTime) //防止pos值为0而服务器不处理，所有值最小为1
    {
        iPosTime = 1;
    }

    if (m_cmpHandle != NULL)
    {
        if (QMediaPlayer::PausedState == CMP_GetPlayStatus(m_cmpHandle))
        {
            return;
        }

        m_iPlayFlag = 1;
        m_dPlaySpeed = 1.00;
        CMP_PauseMedia(m_cmpHandle);
        pthread_mutex_lock(&g_sliderValueSetMutex);
        m_playSlider->setValue(iPosTime);
        CMP_SetPosition(m_cmpHandle, iPosTime);
        playingTime = iPosTime;
        pthread_mutex_unlock(&g_sliderValueSetMutex);
        CMP_PlayMedia(m_cmpHandle);

   }

}

void recordPlayWidget::playSliderPressSlot(int iPosTime)
{
    QString playSpeedStr = "";

//    DebugPrint(DEBUG_UI_OPTION_PRINT, "recordPlayWidget  press play slider!\n");

    if (iPosTime < 0)
    {
        return;
    }
    else if (iPosTime == m_playSlider->value())    //时间值没有变化不进行处理
    {
//        DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] value is not change, do not set!\n", __FUNCTION__);
        return;
    }
    else if (0 == iPosTime) //防止pos值为0而服务器不处理，所有值最小为1
    {
        iPosTime = 1;
    }
    if (m_cmpHandle != NULL)
    {
        if (QMediaPlayer::PausedState == CMP_GetPlayStatus(m_cmpHandle))
        {
            return;
        }

        m_iPlayFlag = 1;
        m_dPlaySpeed = 1.00;
        CMP_PauseMedia(m_cmpHandle);
        pthread_mutex_lock(&g_sliderValueSetMutex);
        m_playSlider->setValue(iPosTime);
        playingTime = iPosTime;
        CMP_SetPosition(m_cmpHandle, iPosTime);
        pthread_mutex_unlock(&g_sliderValueSetMutex);
        CMP_PlayMedia(m_cmpHandle);

    }

}

void recordPlayWidget::playPlusStepSlot()
{
    qint64 iPosTime = 0;
    QString playSpeedStr;

    if (NULL == m_cmpHandle)
    {
        return;
    }

    if (QMediaPlayer::PausedState == CMP_GetPlayStatus(m_cmpHandle))
    {
        return;
    }

    m_iPlayFlag = 1;
    m_dPlaySpeed = 1.00;
    setPlayButtonStyleSheet();

    iPosTime = CMP_GetCurrentPlayTime(m_cmpHandle) + 60000;
    CMP_PauseMedia(m_cmpHandle);
    if (m_iPlayRange != 0)
    {
        if (iPosTime <= m_iPlayRange)
        {
            pthread_mutex_lock(&g_sliderValueSetMutex);
            m_playSlider->setValue(iPosTime);
            CMP_SetPosition(m_cmpHandle, iPosTime);
            pthread_mutex_unlock(&g_sliderValueSetMutex);
        }
    }
    else
    {
        closePlayWin();
        setPlayButtonStyleSheet();
    }
    CMP_PlayMedia(m_cmpHandle);


}

void recordPlayWidget::playMinusStepSlot()
{
    qint64 iPosTime = 0;
    QString playSpeedStr;

    if (QMediaPlayer::PausedState == CMP_GetPlayStatus(m_cmpHandle))
    {
        return;
    }

    m_iPlayFlag = 1;
    m_dPlaySpeed = 1.00;
    setPlayButtonStyleSheet();

    iPosTime = CMP_GetCurrentPlayTime(m_cmpHandle) - 60000;
    CMP_PauseMedia(m_cmpHandle);

    if (iPosTime > 0)
    {
        pthread_mutex_lock(&g_sliderValueSetMutex);
        m_playSlider->setValue(iPosTime);
        CMP_SetPosition(m_cmpHandle, iPosTime);
        pthread_mutex_unlock(&g_sliderValueSetMutex);

    }
    else
    {
        iPosTime = 1;
        pthread_mutex_lock(&g_sliderValueSetMutex);
        m_playSlider->setValue(iPosTime);
        CMP_SetPosition(m_cmpHandle, iPosTime);
        pthread_mutex_unlock(&g_sliderValueSetMutex);

    }
    CMP_PlayMedia(m_cmpHandle);


}

void recordPlayWidget::downloadProcessBarDisplaySlot(int iEnableFlag)   //是否显示文件下载进度条，iEnableFlag为1，显示，为0不显示
{
    if ((0 == iEnableFlag) && (0 == ui->fileDownloadProgressBar->isHidden()))
    {
        ui->fileDownloadProgressBar->hide();
        ui->queryPushButton->setEnabled(true);
        ui->downLoadPushButton->setEnabled(true);
    }
    else if ((1 == iEnableFlag) && (1 == ui->fileDownloadProgressBar->isHidden()))
    {
        ui->fileDownloadProgressBar->show();
        ui->queryPushButton->setEnabled(false);
        ui->downLoadPushButton->setEnabled(false);
    }

}

void recordPlayWidget::setDownloadProcessBarValueSlot(int iValue)   //设置文件下载进度条的值
{
    if (-1 == iValue) //iValue=-1时,表示被告知U盘已拔出,销毁FTP连接并弹框提示
        {
            FTP_DestoryConnect(m_tFtpHandle[m_iFtpServerIdex]);

//            DebugPrint(DEBUG_UI_ERROR_PRINT, "recordPlayWidget recordfile downLoad failed!USB device is out\n");
            m_tFtpHandle[m_iFtpServerIdex] = 0;

//            DebugPrint(DEBUG_UI_MESSAGE_PRINT, "recordfile downLoad failed!USB device is out\n");
            QMessageBox box(QMessageBox::Warning,QString::fromUtf8("错误"),QString::fromUtf8("下载失败，U盘已被拔出!"));
            box.setStandardButtons (QMessageBox::Ok);
            box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));
            box.exec();
            return;
        }

        if (-2 == iValue) //iValue=-2时,表示被告知U盘写入失败,销毁FTP连接并弹框提示
        {
            FTP_DestoryConnect(m_tFtpHandle[m_iFtpServerIdex]);

//            DebugPrint(DEBUG_UI_ERROR_PRINT, "recordPlayWidget recordfile downLoad failed!USB device write error\n");
            m_tFtpHandle[m_iFtpServerIdex] = 0;

//            DebugPrint(DEBUG_UI_MESSAGE_PRINT, "recordfile downLoad failed!USB device write error\n");
            QMessageBox box(QMessageBox::Warning,QString::fromUtf8("错误"),QString::fromUtf8("下载失败，U盘写入失败!"));
            box.setStandardButtons (QMessageBox::Ok);
            box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));
            box.exec();
            return;
        }

        if (-3 == iValue) //iValue=-3时,表示被告知数据接收失败,销毁FTP连接并弹框提示
        {
            FTP_DestoryConnect2(m_tFtpHandle[m_iFtpServerIdex]);

//            DebugPrint(DEBUG_UI_ERROR_PRINT, "recordPlayWidget recordfile downLoad failed!data recv\n");
            m_tFtpHandle[m_iFtpServerIdex] = 0;

//            DebugPrint(DEBUG_UI_MESSAGE_PRINT, "recordfile downLoad failed!data recv error\n");
            QMessageBox box(QMessageBox::Warning,QString::fromUtf8("错误"),QString::fromUtf8("下载失败，数据接收失败!"));
            box.setStandardButtons (QMessageBox::Ok);
            box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));
            box.exec();
            return;
        }

        ui->fileDownloadProgressBar->setValue(iValue);

        if (100 == iValue)   //iValue=100,下载结束，销毁ftp连接
        {
            FTP_DestoryConnect(m_tFtpHandle[m_iFtpServerIdex]);
//            DebugPrint(DEBUG_UI_NOMAL_PRINT, "recordPlayWidget recordfile downLoad end!Destory this ftp connect\n");
            m_tFtpHandle[m_iFtpServerIdex] = 0;
        }



}

void recordPlayWidget::closeRecordPlaySlot()
{
    closePlayWin();
    setPlayButtonStyleSheet();
}

void recordPlayWidget::recordTableWidgetFillFunc()
{
    char *pcfileName = NULL;
    char *pcToken = m_pcRecordFileBuf, *pcBufTmp = NULL;
    char acFilePath[MAX_RECFILE_PATH_LEN] = {0};
    int iParseIdex = 0;
    QString item = "";

    pcBufTmp = strstr(pcToken,".MP4");
    while (pcBufTmp != NULL)
    {
        memset(acFilePath, 0, MAX_RECFILE_PATH_LEN);
        memcpy(acFilePath, pcToken, pcBufTmp-pcToken);
        strcat(acFilePath, ".MP4");
        memcpy(m_acFilePath[iParseIdex], acFilePath, strlen(acFilePath));
        iParseIdex++;
        if (iParseIdex > MAX_RECORD_SEACH_NUM)
        {
            break;
        }

        ui->recordFileTableWidget->insertRow(iParseIdex-1);//添加新的一行

        QTableWidgetItem *checkBox = new QTableWidgetItem();
        checkBox->setCheckState(Qt::Unchecked);
        ui->recordFileTableWidget->setItem(iParseIdex-1, 0, checkBox);

        item = QString::number(iParseIdex);
        ui->recordFileTableWidget->setItem(iParseIdex-1, 1, new QTableWidgetItem(item));
        ui->recordFileTableWidget->item(iParseIdex-1, 1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        pcfileName = parseFileName(acFilePath);
        if (pcfileName != NULL)
        {
            item = QString(QLatin1String(pcfileName));
        }
        ui->recordFileTableWidget->setItem(iParseIdex-1, 2, new QTableWidgetItem(item));
        ui->recordFileTableWidget->item(iParseIdex-1, 2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        if (pcfileName != NULL && strstr(pcfileName, "_tmp") != NULL)
        {
            ui->recordFileTableWidget->item(iParseIdex-1, 1)->setForeground(Qt::red);
            ui->recordFileTableWidget->item(iParseIdex-1, 2)->setForeground(Qt::red);
        }

        pcToken = pcBufTmp + strlen(".MP4");
        pcBufTmp = strstr(pcToken,".MP4");
    }

    ui->queryPushButton->setEnabled(true);   //填充完恢复查询按钮可按
    ui->carSeletionComboBox->setEnabled(true);
    ui->cameraSelectionComboBox->setEnabled(true);
    if (m_recordTabelWidgetFillTimer != NULL)
    {
        if (m_recordTabelWidgetFillTimer->isActive())   //判断定时器是否正在运行，是则停止运行
        {
            m_recordTabelWidgetFillTimer->stop();
        }
        delete m_recordTabelWidgetFillTimer;
        m_recordTabelWidgetFillTimer = NULL;
    }
}

void recordPlayWidget::recordTableWidgetFillSlot()
{
    if (NULL == m_recordTabelWidgetFillTimer)
    {
        m_recordTabelWidgetFillTimer = new QTimer(this);
    }
    m_recordTabelWidgetFillTimer->start(1000);   //收到第一包后等待1秒，确保录像文件消息包能全部接收完再一起填充文件列表处理
    connect(m_recordTabelWidgetFillTimer,SIGNAL(timeout()), this, SLOT(recordTableWidgetFillFunc()));
}

void recordPlayWidget::setRangeLabelSlot()
{
#if 0
    char acStr[32] = {0};
    int iMin = 0, iSec = 0;

    iMin = m_iPlayRange / 60;
    iSec = m_iPlayRange % 60;

    snprintf(acStr, sizeof(acStr), "%02d", iMin);
    ui->rangeMinLabel->setText(QString(QLatin1String(acStr)));

    memset(acStr, 0, sizeof(acStr));
    snprintf(acStr, sizeof(acStr), "%02d", iSec);
    ui->rangeSecLabel->setText(QString(QLatin1String(acStr)));
#endif
}

void recordPlayWidget::setPlaySliderValueSlot(int iValue)    //实时刷新播放进度条的当前值
{
#if 0

    char acStr[32] = {0};
    int iMin = 0, iSec = 0;
    iMin = iValue / 60;
    iSec = iValue % 60;

    snprintf(acStr, sizeof(acStr), "%02d", iMin);
//    ui->playMinLabel->setText(QString(QLatin1String(acStr)));

    memset(acStr, 0, sizeof(acStr));
    snprintf(acStr, sizeof(acStr), "%02d", iSec);
//    ui->playSecLabel->setText(QString(QLatin1String(acStr)));
#endif

    m_playSlider->setValue(iValue);


}


void recordPlayWidget::setPosition(int position)
{
    if (m_cmpHandle != NULL)
    {
        CMP_SetPosition(m_cmpHandle,position);
    }

}


void recordPlayWidget::recordQuerySlot()
{
    int iRet = 0, row = 0, iServerIdex = 0, iCameraIdex = 0, i = 0;
    int year = 0, mon = 0, day = 0, hour = 0, min = 0, sec = 0;
    short yr = 0;
    T_TRAIN_CONFIG tTrainConfigInfo;
    T_LOG_INFO tLogInfo;

//        DebugPrint(DEBUG_UI_OPTION_PRINT, "recordPlayWidget record query PushButton pressed!\n");
    for (i = 0; i < MAX_RECORD_SEACH_NUM; i++)
    {
        memset(m_acFilePath[i], 0, MAX_RECFILE_PATH_LEN);
    }
    memset(m_pcRecordFileBuf, 0, MAX_RECORD_SEACH_NUM*MAX_RECFILE_PATH_LEN);
    m_iTotalLen = 0;

    row = ui->recordFileTableWidget->rowCount();//获取录像文件列表总行数
    for (i = 0; i < row; i++)
    {
        ui->recordFileTableWidget->removeRow(i);
    }
    ui->recordFileTableWidget->setRowCount(0);

    memset(&tTrainConfigInfo, 0, sizeof(T_TRAIN_CONFIG));
    STATE_GetCurrentTrainConfigInfo(&tTrainConfigInfo);

    iServerIdex = ui->carSeletionComboBox->currentIndex();
    iCameraIdex = ui->cameraSelectionComboBox->currentIndex();

    int start = ui->StartcomboBox->currentIndex();
    int end = ui->EndcomboBox->currentIndex();



    if (m_Phandle[iServerIdex])
    {
        T_NVR_SEARCH_RECORD tRecordSeach;
        memset(&tRecordSeach, 0, sizeof(T_NVR_SEARCH_RECORD));

        sscanf(ui->StartdateEdit->text().toLatin1().data(),"%4d-%2d-%2d", &year, &mon, &day);
        hour =  start;

        yr = year;
        tRecordSeach.tStartTime.i16Year = htons(yr);
        tRecordSeach.tStartTime.i8Mon = mon;
        tRecordSeach.tStartTime.i8day = day;
        tRecordSeach.tStartTime.i8Hour = hour;
        tRecordSeach.tStartTime.i8Min = min;
        tRecordSeach.tStartTime.i8Sec = sec;

        sscanf(ui->EnddateEdit->text().toLatin1().data(),"%4d-%2d-%2d", &year, &mon, &day);
        hour =  end;

        yr = year;
        tRecordSeach.tEndTime.i16Year = htons(yr);
        tRecordSeach.tEndTime.i8Mon = mon;
        tRecordSeach.tEndTime.i8day = day;
        tRecordSeach.tEndTime.i8Hour = hour;
        tRecordSeach.tEndTime.i8Min = min;
        tRecordSeach.tEndTime.i8Sec = sec;

        tRecordSeach.iCarriageNo = tTrainConfigInfo.tNvrServerInfo[iServerIdex].iCarriageNO;
        tRecordSeach.iIpcPos = 8+iCameraIdex;

        iRet = PMSG_SendPmsgData(m_Phandle[iServerIdex], CLI_SERV_MSG_TYPE_GET_RECORD_FILE, (char *)&tRecordSeach, sizeof(T_NVR_SEARCH_RECORD));
        if (iRet < 0)
        {
//                DebugPrint(DEBUG_UI_ERROR_PRINT, "[%s] PMSG_SendPmsgData CLI_SERV_MSG_TYPE_GET_RECORD_FILE error!iRet=%d\n",__FUNCTION__, iRet);
        }
        else
        {
            memset(&tLogInfo, 0, sizeof(T_LOG_INFO));
            tLogInfo.iLogType = 0;
            snprintf(tLogInfo.acLogDesc, sizeof(tLogInfo.acLogDesc), "Req camera %d.%d record in %s %2d:%2d%2d  to %s %2d:%2d%2d",
                  100+tTrainConfigInfo.tNvrServerInfo[iServerIdex].iCarriageNO, 200+iCameraIdex, ui->StartdateEdit->text().toLatin1().data(),tRecordSeach.tStartTime.i8Hour,min,sec,
                  ui->EnddateEdit->text().toLatin1().data(),tRecordSeach.tEndTime.i8Hour,min,sec);
            LOG_WriteLog(&tLogInfo);
        }

        /*启动定时器检测录像是否查完，未查完不让再次按查询键*/
        ui->queryPushButton->setEnabled(false);
        ui->carSeletionComboBox->setEnabled(false);
        ui->cameraSelectionComboBox->setEnabled(false);
        if (NULL == m_recorQueryTimer)
        {
            m_recorQueryTimer = new QTimer(this);
        }
        m_recorQueryTimer->start(500);
        connect(m_recorQueryTimer,SIGNAL(timeout()), this,SLOT(recordQueryEndSlot()));
    }

}
void recordPlayWidget::recordQueryEndSlot()
{
    static int iRecordNum = 0;

    iRecordNum++;

    if (m_iTotalLen> 0)  /*收到第一个包触发录像文件列表填充信号来填充列表*/
    {
        emit recordTableWidgetFillSignal();

        if (m_recorQueryTimer != NULL)
        {
            if (m_recorQueryTimer->isActive())   //判断定时器是否正在运行，是则停止运行
            {
                m_recorQueryTimer->stop();
            }
            delete m_recorQueryTimer;
            m_recorQueryTimer = NULL;
        }
    }
    else
    {
        if (iRecordNum > 10)    //5秒没查询即恢复查询按键可按*/
        {
            iRecordNum = 0;
            ui->queryPushButton->setEnabled(true);
            ui->carSeletionComboBox->setEnabled(true);
            ui->cameraSelectionComboBox->setEnabled(true);

            if (m_recorQueryTimer != NULL)
            {
                if (m_recorQueryTimer->isActive())   //判断定时器是否正在运行，是则停止运行
                {
                    m_recorQueryTimer->stop();
                }
                delete m_recorQueryTimer;
                m_recorQueryTimer = NULL;
            }

//            DebugPrint(DEBUG_UI_MESSAGE_PRINT, "[%s-%d] recordQuery fail!\n",__FUNCTION__, __LINE__);
            QMessageBox box(QMessageBox::Warning,QString::fromUtf8("错误"),QString::fromUtf8("未查询到录像数据!"));
            box.setStandardButtons (QMessageBox::Ok);
            box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));
            box.exec();
        }
    }



}
void recordPlayWidget::recordDownloadSlot()
{
    int iRet = 0, idex = 0, row = 0;
    QString filename = "";
    QString fileSavePath = "/media/usb0/";
    char acSaveFileName[128] = {0};
    char acIpAddr[32] = {0};
    T_TRAIN_CONFIG tTrainConfigInfo;
    char acUserType[16] = {0};

//    DebugPrint(DEBUG_UI_OPTION_PRINT, "recordPlayWidget record download PushButton pressed!\n");

    STATE_GetCurrentUserType(acUserType, sizeof(acUserType));

    if (!strcmp(acUserType, "operator"))   //操作员不能下载
    {
//        DebugPrint(DEBUG_UI_MESSAGE_PRINT, "recordPlayWidget this user type has no right to download record file!\n");
        QMessageBox box(QMessageBox::Warning,QString::fromUtf8("错误"),QString::fromUtf8("该用户没有下载权限!"));
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));
        box.exec();
        return;
    }

    if (ui->recordFileTableWidget->rowCount() > 0)
    {
        for (row = 0; row < ui->recordFileTableWidget->rowCount(); row++)    //先判断一次是否没有录像文件被选中，没有则弹框提示
        {
            if (ui->recordFileTableWidget->item(row, 0)->checkState() == Qt::Checked)
            {
                break;
            }
        }
        if (row == ui->recordFileTableWidget->rowCount())
        {
//            DebugPrint(DEBUG_UI_MESSAGE_PRINT, "recordPlayWidget not select record file to download!\n");
            QMessageBox msgBox(QMessageBox::Question,QString(tr("注意")),QString(tr("请选择您要下载的录像文件")));
            msgBox.setStandardButtons(QMessageBox::Yes);
            msgBox.button(QMessageBox::Yes)->setText("确 定");
            msgBox.exec();
            return;
        }
        if (access("/media/usb0/", F_OK) < 0)
        {
//            DebugPrint(DEBUG_UI_MESSAGE_PRINT, "recordPlayWidget not get USB device!\n");
            QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("未检测到U盘,请插入!")));
            msgBox.setStandardButtons(QMessageBox::Yes);
            msgBox.button(QMessageBox::Yes)->setText("确 定");
            msgBox.exec();
            return;
        }
        else
        {
            if (0 == STATE_FindUsbDev())   //这里处理一个特殊情况:U盘拔掉是umount失败，/mnt/usb/u/路径还存在，但是实际U盘是没有再插上的
            {
//                DebugPrint(DEBUG_UI_MESSAGE_PRINT, "recordPlayWidget not get USB device!\n");
                QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("未检测到U盘,请插入!")));
                msgBox.setStandardButtons(QMessageBox::Yes);
                msgBox.button(QMessageBox::Yes)->setText("确 定");
                msgBox.exec();
                return;
            }
        }
        idex = ui->carSeletionComboBox->currentIndex();

        if (idex < 0)
        {
            return;
        }
        m_iFtpServerIdex = idex;

        memset(&tTrainConfigInfo, 0, sizeof(T_TRAIN_CONFIG));
        STATE_GetCurrentTrainConfigInfo(&tTrainConfigInfo);
        snprintf(acIpAddr, sizeof(acIpAddr), "192.168.%d.81", 100+tTrainConfigInfo.tNvrServerInfo[idex].iCarriageNO);
        m_tFtpHandle[idex] = FTP_CreateConnect(acIpAddr, FTP_SERVER_PORT, PftpProc);
        if (0 == m_tFtpHandle[idex])
        {
//            DebugPrint(DEBUG_UI_ERROR_PRINT, "[%s] connect to ftp server:%s error!\n", __FUNCTION__, acIpAddr);
            return;
        }

        for (row = 0; row < ui->recordFileTableWidget->rowCount(); row++)
        {
            if (ui->recordFileTableWidget->item(row, 0)->checkState() == Qt::Checked)
            {
                if (parseFileName(m_acFilePath[row]) != NULL)
                {
                    snprintf(acSaveFileName, sizeof(acSaveFileName), "%s%s", "/mnt/usb/u/", parseFileName(m_acFilePath[row]));
                }

//                DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] add download file:%s!\n", __FUNCTION__, m_acFilePath[row]);
                iRet = FTP_AddDownLoadFile(m_tFtpHandle[idex], m_acFilePath[row], acSaveFileName);
                if (iRet < 0)
                {
                    FTP_DestoryConnect(m_tFtpHandle[m_iFtpServerIdex]);
                    m_tFtpHandle[m_iFtpServerIdex] = 0;
//                    DebugPrint(DEBUG_UI_MESSAGE_PRINT, "recordPlayWidget not get USB device!\n");
                    QMessageBox msgBox(QMessageBox::Warning,QString(tr("提示")),QString(tr("文件下载失败")));
                    msgBox.setStandardButtons(QMessageBox::Yes);
                    msgBox.button(QMessageBox::Yes)->setText("确 定");
                    msgBox.exec();
                    return;
                }
            }
        }

        iRet = FTP_FileDownLoad(m_tFtpHandle[idex]);
        if (iRet < 0)
        {
            FTP_DestoryConnect(m_tFtpHandle[m_iFtpServerIdex]);
            m_tFtpHandle[m_iFtpServerIdex] = 0;
//            DebugPrint(DEBUG_UI_MESSAGE_PRINT, "recordPlayWidget record file download failed!\n");
            QMessageBox msgBox(QMessageBox::Warning,QString(tr("提示")),QString(tr("文件下载失败")));
            msgBox.setStandardButtons(QMessageBox::Yes);
            msgBox.button(QMessageBox::Yes)->setText("确 定");
            msgBox.exec();
            return;
        }
    }

}

void recordPlayWidget::setPlayButtonStyleSheet()
{
    if (0 == m_iPlayFlag)
    {
        ui->pushButton->setStyleSheet("QPushButton{border-image: url(:/monres/pause.bmp);background-color: rgb(255, 255, 255);}");

    }
    else
    {
        ui->pushButton->setStyleSheet("QPushButton{border-image: url(:/monres/pause1.bmp);background-color: rgb(255, 255, 255);}");

    }
}

void recordPlayWidget::getTrainConfig()    	//获取车型配置文件，初始化车厢及摄像机下拉框
{
    int i = 0, j = 0;
    QString item = "";

    T_TRAIN_CONFIG tTrainConfigInfo;
    memset(&tTrainConfigInfo, 0, sizeof(T_TRAIN_CONFIG));
    STATE_GetCurrentTrainConfigInfo(&tTrainConfigInfo);

//    DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] GetCurrentTrainConfigInfo, nvr server num=%d\n",__FUNCTION__,tTrainConfigInfo.iNvrServerCount);
//    qDebug()<<"DEBUG_UI_NOMAL_PRINT GetCurrentTrainConfigInfo, nvr server num="<<tTrainConfigInfo.iNvrServerCount<<__FUNCTION__<<__LINE__<<endl;
    for (i = 0; i < tTrainConfigInfo.iNvrServerCount; i++)
    {
        item = "";
        item = QString::number(tTrainConfigInfo.tNvrServerInfo[i].iCarriageNO);
        item += tr("号车厢");
        ui->carSeletionComboBox->addItem(item);
        m_Phandle[i] = STATE_GetNvrServerPmsgHandle(i);
//        qDebug()<<"DEBUG_UI_NOMAL_PRINT  tTrainConfigInfo.tNvrServerInfo[i].iCarriageNO::="<<i<<":="<<tTrainConfigInfo.tNvrServerInfo[i].iCarriageNO;
        if (0 == i)
        {
//            DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] the first server has camera num=%d\n",__FUNCTION__,tTrainConfigInfo.tNvrServerInfo[i].iPvmsCameraNum);
//            qDebug()<<"DEBUG_UI_NOMAL_PRINT the first server has camera num="<<tTrainConfigInfo.tNvrServerInfo[i].iPvmsCameraNum<<__FUNCTION__<<__LINE__<<endl;

            for (j = 0; j < tTrainConfigInfo.tNvrServerInfo[i].iPvmsCameraNum; j++)
            {
                item = "";
                item = QString::number(8+j);
                item += tr("号摄像机");
                ui->cameraSelectionComboBox->addItem(item);
//                qDebug()<<"DEBUG_UI_NOMAL_PRINT tTrainConfigInfo.tNvrServerInfo[i].iPvmsCameraNum ="<<i<<"=:"<<tTrainConfigInfo.tNvrServerInfo[i].iPvmsCameraNum<<__FUNCTION__<<__LINE__<<endl;

            }
        }


    }
}


void recordPlayWidget::recordPlayStartSlot()
{
    if (m_cmpHandle != NULL)
    {
        if (0 == m_iPlayFlag)
        {
            m_iPlayFlag = 1;
            m_dPlaySpeed = 1.00;

            CMP_PlayMedia(m_cmpHandle);
            CMP_SetPlayRate(m_cmpHandle,m_dPlaySpeed);
        }
        else
        {
            m_iPlayFlag = 0;
            CMP_PauseMedia(m_cmpHandle);
        }
        setPlayButtonStyleSheet();
    }
    else
    {
        if(ui->recordFileTableWidget->currentItem() != NULL)
        {
            emit recordSeletPlay(ui->recordFileTableWidget->currentItem());
        }
    }

}

void recordPlayWidget::recordPauseSlot()
{
    m_iPlayFlag = 0;
    if (m_cmpHandle != NULL)    //如果播放窗口已经有打开了码流播放，关闭码流播放
    {
        CMP_PauseMedia(m_cmpHandle);
    }

}

void recordPlayWidget::recordPlayStopSlot()
{
    if (m_cmpHandle != NULL)    //如果播放窗口已经有打开了码流播放，关闭码流播放
    {
        closePlayWin();
        setPlayButtonStyleSheet();
    }
}

void recordPlayWidget::closePlayWin()
{
    if (m_threadId != 0)
    {
        m_iThreadRunFlag = 0;
        pthread_join(m_threadId, NULL);
        m_threadId = 0;
    }


    m_playSlider->setRange(0, 0);
    m_playSlider->setValue(0);

    if (m_cmpHandle != NULL)    //关闭已打开的回放
    {
        CMP_CloseMedia(m_cmpHandle);
        CMP_DestroyMedia(m_cmpHandle);
        m_cmpHandle= NULL;
        emit setRecordPlayFlagSignal(0);
    }

    if (m_iRecordIdex >= 0 && ui->recordFileTableWidget->item(m_iRecordIdex, 2) != NULL && 0 == ui->recordFileTableWidget->item(m_iRecordIdex, 2)->text().contains("tmp"))
    {
        ui->recordFileTableWidget->item(m_iRecordIdex, 1)->setForeground(Qt::black);
        ui->recordFileTableWidget->item(m_iRecordIdex, 2)->setForeground(Qt::black);
    }
    m_iRecordIdex = -1;
    m_iPlayFlag = 0;

}

void recordPlayWidget::triggerSetSliderValueSignal(int iValue)
{
    emit setSliderValueSignal(iValue);
}

void recordPlayWidget::triggerSetRangeLabelSignal()
{
    emit setRangeLabelSignal();
}
void recordPlayWidget::triggerCloseRecordPlaySignal()
{
    emit closeRecordPlaySignal();
}

void recordPlayWidget::triggerDownloadProcessBarDisplaySignal(int iEnableFlag)	//触发是否显示文件下载进度条的信号，iEnableFlag为1，显示，为0不显示
{
    emit downloadProcessBarDisplaySignal(iEnableFlag);
}
void recordPlayWidget::triggerSetDownloadProcessBarValueSignal(int iValue)	//触发设置文件下载进度条的值的信号
{
    emit setDownloadProcessBarValueSignal(iValue);
}
void recordPlayWidget::pageShowCtrl()  //每次切换到当前页面，则更新查询起始和结束时间控件显示
{
    QDateTime time = QDateTime::currentDateTime();

    ui->StartdateEdit->setDate(time.date());
    ui->EnddateEdit->setDate(time.date());
    int value = QTime::currentTime().hour();
     ui->EndcomboBox->setCurrentIndex(value);
//    ui->EndtimeEdit->setTime(time.time());

}

void recordPlayWidget::recordPlayFastForwardSlot()
{

    if (NULL == m_cmpHandle)
    {
        return;
    }

    if (QMediaPlayer::PlayingState != CMP_GetPlayStatus(m_cmpHandle))
    {
        return;
    }
    if (m_dPlaySpeed >= 4.00)
    {
        return;
    }
    m_iPlayFlag = 1;
    m_dPlaySpeed = m_dPlaySpeed*2;

    CMP_SetPlayRate(m_cmpHandle,m_dPlaySpeed);
    setPlayButtonStyleSheet();
    qDebug()<<"***********playstate="<<CMP_GetPlayState(m_cmpHandle)<<__LINE__<<endl;



}
void recordPlayWidget::recordPlaySlowForwardSlot()
{
    if (NULL == m_cmpHandle)
    {
        return;
    }

    if (QMediaPlayer::PlayingState != CMP_GetPlayStatus(m_cmpHandle))
    {
        return;
    }
    if (m_dPlaySpeed <= 0.25)
    {
        return;
    }
    m_iPlayFlag = 1;
    m_dPlaySpeed = m_dPlaySpeed/2;

    CMP_SetPlayRate(m_cmpHandle,m_dPlaySpeed);
    qDebug()<<"*********m_dPlaySpeed="<<m_dPlaySpeed<<"***********playstate="<<CMP_GetPlayState(m_cmpHandle)<<__LINE__<<endl;


    setPlayButtonStyleSheet();
}

void recordPlayWidget::manualSwitchVideoEndSlot()
{

    ui->playLastOnePushButton->setEnabled(true);
    ui->playNextOnePushButton->setEnabled(true);

    if (m_VideoSwitchTimer != NULL)
    {
        if (m_VideoSwitchTimer->isActive())
        {
            m_VideoSwitchTimer->stop();
        }
        delete m_VideoSwitchTimer;
        m_VideoSwitchTimer = NULL;
    }


}

void recordPlayWidget::recordPlayLastOneSlot()
{
    int iRow = 0, iDex = 0;

//    DebugPrint(DEBUG_UI_OPTION_PRINT, "recordPlayWidget lastOne play PushButton pressed!\n");

    if (ui->recordFileTableWidget->rowCount() <= 0 || NULL == m_cmpHandle)
    {
        return;
    }
    iDex = ui->carSeletionComboBox->currentIndex();
    if (iDex < 0)
    {
        return;
    }
    iRow = m_iRecordIdex - 1;
    if (iRow < 0)
    {
        return;
    }
    qDebug()<<"*********recordPlayLastOneSlot****m_iRecordIdex="<<m_iRecordIdex<<__LINE__<<endl;

    closePlayWin();   //先关闭之前的
    setPlayButtonStyleSheet();
    emit setRecordPlayFlagSignal(1);

    recordPlayCtrl(iRow, iDex);
    ui->playNextOnePushButton->setEnabled(false);
    ui->playLastOnePushButton->setEnabled(false);

    if(m_VideoSwitchTimer == NULL)
    {
        m_VideoSwitchTimer = new QTimer(this);
        m_VideoSwitchTimer->start(1*1000);
        connect(m_VideoSwitchTimer,SIGNAL(timeout()), this,SLOT(manualSwitchVideoEndSlot()));
    }


}
void recordPlayWidget::recordPlayNextOneSlot()
{

    int iDex = 0, iRow = 0;

//    DebugPrint(DEBUG_UI_OPTION_PRINT, "recordPlayWidget nextOne play PushButton pressed!\n");

    if (ui->recordFileTableWidget->rowCount() <= 0 || NULL == m_cmpHandle)
    {
        return;
    }

    iDex = ui->carSeletionComboBox->currentIndex();
    if (iDex < 0)
    {
        return;
    }

    iRow = m_iRecordIdex + 1;
    if (iRow > (ui->recordFileTableWidget->rowCount() - 1))
    {
        return;
    }

    qDebug()<<"*********recordPlayNextOneSlot****m_iRecordIdex="<<m_iRecordIdex<<__LINE__<<endl;

    closePlayWin();   //先关闭之前的
    setPlayButtonStyleSheet();
    emit setRecordPlayFlagSignal(1);
    recordPlayCtrl(iRow, iDex);

    ui->playNextOnePushButton->setEnabled(false);
    ui->playLastOnePushButton->setEnabled(false);

    if(m_VideoSwitchTimer == NULL)
    {
        m_VideoSwitchTimer = new QTimer(this);
        m_VideoSwitchTimer->start(1*1000);
        connect(m_VideoSwitchTimer,SIGNAL(timeout()), this,SLOT(manualSwitchVideoEndSlot()));
    }


}




void recordPlayWidget::registOutButtonClick()
{
    int record_page = 2;
    this->hide();
    emit registOutSignal(record_page);    //触发注销信号，带上当前设备类型
}

void recordPlayWidget::carNoChangeSlot()   //车厢号切换信号响应槽函数
{
    int i = 0, idex = ui->carSeletionComboBox->currentIndex();    //获取当前车厢选择下拉框的索引
    QString item = "";
    T_TRAIN_CONFIG tTrainConfigInfo;
//    DebugPrint(DEBUG_UI_OPTION_PRINT, "recordPlayWidget change server carriage No!\n");

    memset(&tTrainConfigInfo, 0, sizeof(T_TRAIN_CONFIG));
    STATE_GetCurrentTrainConfigInfo(&tTrainConfigInfo);
    ui->cameraSelectionComboBox->setCurrentIndex(-1);
    ui->cameraSelectionComboBox->clear();

    qDebug()<<"*****---carNoChangeSlot--=:"<<idex<<tTrainConfigInfo.tNvrServerInfo[idex].iPvmsCameraNum<<__FUNCTION__<<__LINE__<<endl;
    for (i = 0; i < tTrainConfigInfo.tNvrServerInfo[idex].iPvmsCameraNum; i++)        //根据不同车厢位置的NVR服务器的摄像机数量个数跟新摄像机选择下拉框
    {
        item = "";
        item = QString::number(8+i);
        item += tr("号摄像机");
        ui->cameraSelectionComboBox->addItem(item);
    }

}

void recordPlayWidget::recordSelectionSlot(QTableWidgetItem *item)
{
    int i = 0;
    for (i = 0; i < ui->recordFileTableWidget->rowCount(); i++)
    {
        if (0 == ui->recordFileTableWidget->item(i, 2)->text().contains("tmp") && i != m_iRecordIdex)
        {
            if (i == item->row())
            {
                ui->recordFileTableWidget->item(i, 1)->setTextColor(Qt::green);
                ui->recordFileTableWidget->item(i, 2)->setForeground(Qt::green);
            }
            else
            {
                ui->recordFileTableWidget->item(i, 1)->setTextColor(Qt::black);
                ui->recordFileTableWidget->item(i, 2)->setForeground(Qt::black);
            }
        }
    }

}

void recordPlayWidget::recordPlaySlot(QTableWidgetItem *item)    //录像文件双击信号响应槽函数，播放录像视频
{
    int iRow = 0, iDex = 0;
//    DebugPrint(DEBUG_UI_OPTION_PRINT, "recordPlayWidget record play pressed!\n");

    setPlayButtonStyleSheet();


    closePlayWin();   //先关闭之前的
    setPlayButtonStyleSheet();
    emit setRecordPlayFlagSignal(1);


    iRow = item->row();
    iDex = ui->carSeletionComboBox->currentIndex();

    recordPlayCtrl(iRow, iDex);
}


void recordPlayWidget::alarmPushButoonClickSlot()
{
    emit alarmPushButoonClickSignal();
    if (m_alarmHappenTimer != NULL)
    {
        delete m_alarmHappenTimer;
        m_alarmHappenTimer = NULL;
    }
    ui->alarmPushButton->setChecked(false);

    g_iRNum = 0;
}
void recordPlayWidget::alarmHappenCtrlSlot()
{
    if (this->isHidden() != 1)
    {
        if (0 == g_iRNum%2)
        {
            ui->alarmPushButton->setChecked(true);
            ui->alarmPushButton->setStyleSheet("QPushButton{border-image: url(:/monres/alerton.bmp);background-color: rgb(255, 255, 255);}");
        }
        else
        {
            ui->alarmPushButton->setChecked(false);
            ui->alarmPushButton->setStyleSheet("QPushButton{border-image: url(:/monres/alertoff.bmp);background-color: rgb(255, 255, 255);}");

        }
        g_iRNum++;
    }
}
void recordPlayWidget::alarmHappenSlot()
{
    if (NULL == m_alarmHappenTimer)
    {
        m_alarmHappenTimer = new QTimer(this);
        connect(m_alarmHappenTimer,SIGNAL(timeout()), this,SLOT(alarmHappenCtrlSlot()));
        m_alarmHappenTimer->start(500);
    }
}

void recordPlayWidget::alarmClearSlot()
{
    if (m_alarmHappenTimer != NULL)
    {
        delete m_alarmHappenTimer;
        m_alarmHappenTimer = NULL;
    }
    ui->alarmPushButton->setChecked(false);
    ui->alarmPushButton->setStyleSheet("QPushButton{border-image: url(:/monres/alertoff.bmp);background-color: rgb(255, 255, 255);}");

    g_iRNum = 0;
}

void recordPlayWidget::recordQueryCtrl(char *pcMsgData, int iMsgDataLen)
{
    if (m_iTotalLen > (MAX_RECORD_SEACH_NUM*MAX_RECFILE_PATH_LEN - 1))
    {
        return;
    }
    memcpy(m_pcRecordFileBuf+m_iTotalLen, pcMsgData, iMsgDataLen);
    m_iTotalLen += iMsgDataLen;

}


void *slideValueSetThread(void *param)    //播放进度条刷新线程
{
    int iDuration = 0, iTryGetPlayRangeNum = 5;
      recordPlayWidget *recordPlaypage = (recordPlayWidget *)param;
      if (NULL == recordPlaypage)
      {
          return NULL;
      }

      pthread_detach(pthread_self());

      while (1 == recordPlaypage->m_iThreadRunFlag)
      {
          if (0 == recordPlaypage->m_iPlayRange)
          {
              while (1 == recordPlaypage->m_iThreadRunFlag && iTryGetPlayRangeNum > 0)     //尝试5次获取播放时长，每次间隔1000MS
              {
                  iDuration = CMP_GetPlayRange(recordPlaypage->m_cmpHandle);
                  if (iDuration > 0)
                  {
                      break;
                  }
                  iTryGetPlayRangeNum--;
                  usleep(1000*1000);
              }
              if (iDuration > 0)
              {
                  recordPlaypage->m_iPlayRange = iDuration;
//                  DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s-%d] m_iPlayRange=%d!\n",__FUNCTION__, __LINE__, recordPlaypage->m_iPlayRange);
              }
              else
              {
                  recordPlaypage->m_iPlayRange = 600;
//                  DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s-%d] m_iPlayRange=%d!\n",__FUNCTION__, __LINE__, recordPlaypage->m_iPlayRange);
              }
              recordPlaypage->m_playSlider->setRange(0, recordPlaypage->m_iPlayRange);
              recordPlaypage->triggerSetRangeLabelSignal();
          }

          if ((recordPlaypage->m_iPlayRange > 0) && (recordPlaypage->m_iPlayFlag != 0))   //只有获取到了进度条范围值,并且不处于暂停状态才会刷新进度条，否则不做刷新处理
          {
              pthread_mutex_lock(&g_sliderValueSetMutex);
              recordPlaypage->m_iSliderValue = CMP_GetCurrentPlayTime(recordPlaypage->m_cmpHandle);
              recordPlaypage->triggerSetSliderValueSignal(recordPlaypage->m_iSliderValue);
              pthread_mutex_unlock(&g_sliderValueSetMutex);
              if (recordPlaypage->m_iSliderValue >= recordPlaypage->m_iPlayRange)   //进度到100%，表示该段录像回放完毕，关闭播放窗口
              {
//                  DebugPrint(DEBUG_UI_NOMAL_PRINT, "recordPlayWidget record play end!close play window\n");
                  recordPlaypage->triggerCloseRecordPlaySignal();
              }
          }
          usleep(500*1000);
      }
      return NULL;




}
void recordPlayWidget::recordPlayCtrl(int iRow, int iDex)
{
    int iRet = 0;
    char acRtspAddr[128] = {0};
    QString playSpeedStr = "";
    T_TRAIN_CONFIG tTrainConfigInfo;
    T_LOG_INFO tLogInfo;

    /*每次播放开始时播放时长清0，设置播放进度条范围值为0，使播放进度条复位*/
    m_iPlayRange = 0;
    m_playSlider->setRange(0, m_iPlayRange);
    m_iSliderValue = 0;

    memset(&tTrainConfigInfo, 0, sizeof(T_TRAIN_CONFIG));
    STATE_GetCurrentTrainConfigInfo(&tTrainConfigInfo);


    m_iPlayFlag = 1;
    m_dPlaySpeed = 1.00;
    playSpeedStr = "1.00x";
//    ui->playSpeedLineEdit->setText(playSpeedStr);
    setPlayButtonStyleSheet();

    snprintf(acRtspAddr, sizeof(acRtspAddr), "rtsp://192.168.%d.81:554%s",tTrainConfigInfo.tNvrServerInfo[iDex].iCarriageNO+100, m_acFilePath[iRow]);
    printf("************----recordPlayCtrl---%s\n",acRtspAddr);
    if (NULL == m_cmpHandle)
    {
        m_cmpHandle = CMP_CreateMedia(m_playWin);
        if(NULL == m_cmpHandle)
        {
            QMessageBox box(QMessageBox::Warning,QString::fromUtf8("错误"),QString::fromUtf8("录像窗口创建失败!"));
            box.setStandardButtons (QMessageBox::Ok);
            box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));
            box.exec();
            return;
        }
    }

    iRet = CMP_OpenMediaFile(m_cmpHandle, acRtspAddr, CMP_TCP);
    if(iRet < 0)
    {
        CMP_DestroyMedia(m_cmpHandle);
        QMessageBox box(QMessageBox::Warning,QString::fromUtf8("错误"),QString::fromUtf8("录像播放失败!"));
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));
        box.exec();
        return;

    }

    m_iRecordIdex = iRow;
    if (0 == ui->recordFileTableWidget->item(m_iRecordIdex, 2)->text().contains("tmp"))
    {
        ui->recordFileTableWidget->item(m_iRecordIdex, 1)->setTextColor(Qt::blue);
        ui->recordFileTableWidget->item(m_iRecordIdex, 2)->setForeground(Qt::blue);
    }

    usleep(200*1000);
    if (0 == m_threadId)    //保证播放进度条刷新线程只创建一次
    {
        m_iThreadRunFlag = 1;
//        DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] create slideValueSet thread begin!\n",__FUNCTION__);
        pthread_create(&m_threadId, NULL, slideValueSetThread, (void *)this);    //创建线程

        if (0 == m_threadId)
        {
//            DebugPrint(DEBUG_UI_ERROR_PRINT, "[%s] create slideValueSet thread error\n", __FUNCTION__);
        }
//        DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] create slideValueSet thread end!\n",__FUNCTION__);
    }

    memset(&tLogInfo, 0, sizeof(T_LOG_INFO));
    tLogInfo.iLogType = 0;
    snprintf(tLogInfo.acLogDesc, sizeof(tLogInfo.acLogDesc), "play %s of nvr server %d", m_acFilePath[iRow], tTrainConfigInfo.tNvrServerInfo[iDex].iCarriageNO+100);
    LOG_WriteLog(&tLogInfo);

}

int recordPlayWidget::pmsgCtrl(PMSG_HANDLE pHandle, unsigned char ucMsgCmd, char *pcMsgData, int iMsgDataLen)    //与服务器通信消息处理
{
    char *pcToken = NULL;

    if (0 == pHandle)
    {
        return 0;
    }

    switch(ucMsgCmd)
    {
        case SERV_CLI_MSG_TYPE_GET_RECORD_TIME_LEN_RESP:
        {
            if (pcMsgData == NULL || iMsgDataLen != 2)
            {
                break;
            }
            else
            {
                short *iDuration = (short *)pcMsgData;
//                DebugPrint(DEBUG_PMSG_DATA_PRINT, "recordPlay Widget get pmsg response cmd 0x%x data:%d\n", ucMsgCmd,*iDuration);
                m_iPlayRange = htons(*iDuration);
                break;
            }
        }
        case SERV_CLI_MSG_TYPE_GET_RECORD_FILE_RESP:
        {
            pcToken = &pcMsgData[2];
            iMsgDataLen = iMsgDataLen-2;  //先得到真正录像文件信息的内容长度，前两个字节表示分包序号
//            DebugPrint(DEBUG_PMSG_DATA_PRINT, "recordPlay Widget get pmsg response cmd 0x%x data:\n%s\n", ucMsgCmd,pcToken);

            if (NULL == pcToken || iMsgDataLen <= 0)
            {
                break;
            }
            recordQueryCtrl(pcToken, iMsgDataLen);    //触发录像查询处理信号，在UI主线程中处理，而不在这里直接处理
            break;
        }
        default:
            break;
    }

    return 0;
}

static char *parseFileName(char *pcSrcStr)     //根据录像文件路径全名解析得到单纯的录像文件名
{
    char *pcTmp = NULL;

    if (NULL == pcSrcStr)
    {
        return NULL;
    }

    pcTmp = strrchr(pcSrcStr, '/');
    if (NULL == pcTmp)
    {
        return NULL;
    }

    if (NULL == (pcTmp+1))
    {
        return NULL;
    }
    return pcTmp+1;
}


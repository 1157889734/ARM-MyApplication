/********************************************************************************
** Form generated from reading UI file 'devupdatewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVUPDATEWIDGET_H
#define UI_DEVUPDATEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_devUpdateWidget
{
public:
    QPushButton *permissonManagePushButton;
    QLabel *presetReturnTimeSetLabel;
    QLineEdit *pollingTimeSetLineEdit;
    QLabel *label_3;
    QPushButton *trainTypeSetPushButton;
    QRadioButton *pollingTimeSetRadioButton_3;
    QLabel *label_2;
    QRadioButton *pollingTimeSetRadioButton;
    QRadioButton *presetReturnTimeSetRadioButton_2;
    QRadioButton *pollingTimeSetRadioButton_4;
    QRadioButton *presetReturnTimeSetRadioButton_3;
    QLabel *pollingTimeSetLabel;
    QRadioButton *presetReturnTimeSetRadioButton;
    QRadioButton *presetReturnTimeSetRadioButton_4;
    QLabel *label_7;
    QRadioButton *pollingTimeSetRadioButton_2;
    QLabel *label;
    QComboBox *trainTypeSetComboBox;
    QLineEdit *presetReturnTimeSetLineEdit;
    QPushButton *alarmPushButton;
    QLabel *label_4;
    QPushButton *canselPushButton;
    QLabel *label_17;
    QWidget *deviceManagewidget;
    QLineEdit *configFileDisplayLineEdit;
    QLineEdit *brightnessLineEdit;
    QLabel *carriageLabel;
    QPushButton *configFilelookPushButton;
    QComboBox *carriageSelectionComboBox;
    QComboBox *cameraSelectionComboBox;
    QLineEdit *contrastLineEdit;
    QLabel *label_9;
    QPushButton *timeAdjustPushButton;
    QLabel *label_15;
    QComboBox *comboBox;
    QLineEdit *saturationLineEdit;
    QPushButton *imageParamSetPushButton;
    QLabel *systimeAdjustLabel;
    QLabel *saturationLabel;
    QLabel *brightnessLabel;
    QPushButton *clientRebootPushButton;
    QLabel *configFileSelectionLabel;
    QLabel *cameraLabel;
    QLabel *contrastLabel;
    QPushButton *configFileImportPushButton;
    QLabel *sysDataAdjustLabel;
    QLabel *devConfigLabel;
    QLabel *updateStatusLabel;
    QLabel *label_18;
    QLabel *label_5;
    QPushButton *updateBeginPushButton;
    QPushButton *clientRebootPushButton_2;
    QTextEdit *updateStatueTextEdit;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_6;

    void setupUi(QWidget *devUpdateWidget)
    {
        if (devUpdateWidget->objectName().isEmpty())
            devUpdateWidget->setObjectName(QString::fromUtf8("devUpdateWidget"));
        devUpdateWidget->resize(1024, 665);
        devUpdateWidget->setStyleSheet(QString::fromUtf8(""));
        permissonManagePushButton = new QPushButton(devUpdateWidget);
        permissonManagePushButton->setObjectName(QString::fromUtf8("permissonManagePushButton"));
        permissonManagePushButton->setGeometry(QRect(350, 520, 203, 102));
        QFont font;
        font.setPointSize(12);
        permissonManagePushButton->setFont(font);
        permissonManagePushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/monres/bitmap19.bmp);}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}"));
        presetReturnTimeSetLabel = new QLabel(devUpdateWidget);
        presetReturnTimeSetLabel->setObjectName(QString::fromUtf8("presetReturnTimeSetLabel"));
        presetReturnTimeSetLabel->setGeometry(QRect(50, 80, 211, 21));
        presetReturnTimeSetLabel->setFont(font);
        presetReturnTimeSetLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        pollingTimeSetLineEdit = new QLineEdit(devUpdateWidget);
        pollingTimeSetLineEdit->setObjectName(QString::fromUtf8("pollingTimeSetLineEdit"));
        pollingTimeSetLineEdit->setGeometry(QRect(780, 10, 151, 31));
        pollingTimeSetLineEdit->setFont(font);
        pollingTimeSetLineEdit->setReadOnly(false);
        label_3 = new QLabel(devUpdateWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 90, 944, 31));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8(" #label_3 { \n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_3 * { \n"
"     background-color:; \n"
" }"));
        trainTypeSetPushButton = new QPushButton(devUpdateWidget);
        trainTypeSetPushButton->setObjectName(QString::fromUtf8("trainTypeSetPushButton"));
        trainTypeSetPushButton->setGeometry(QRect(390, 45, 110, 30));
        trainTypeSetPushButton->setFont(font);
        trainTypeSetPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/monres/sure.bmp);}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}"));
        pollingTimeSetRadioButton_3 = new QRadioButton(devUpdateWidget);
        pollingTimeSetRadioButton_3->setObjectName(QString::fromUtf8("pollingTimeSetRadioButton_3"));
        pollingTimeSetRadioButton_3->setGeometry(QRect(440, 13, 61, 22));
        pollingTimeSetRadioButton_3->setFont(font);
        pollingTimeSetRadioButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pollingTimeSetRadioButton_3->setChecked(false);
        label_2 = new QLabel(devUpdateWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 8, 944, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8(" #label_2 { \n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_2 * { \n"
"     background-color:; \n"
" }"));
        pollingTimeSetRadioButton = new QRadioButton(devUpdateWidget);
        pollingTimeSetRadioButton->setObjectName(QString::fromUtf8("pollingTimeSetRadioButton"));
        pollingTimeSetRadioButton->setGeometry(QRect(270, 13, 61, 22));
        pollingTimeSetRadioButton->setFont(font);
        pollingTimeSetRadioButton->setAutoFillBackground(false);
        pollingTimeSetRadioButton->setStyleSheet(QString::fromUtf8(""));
        pollingTimeSetRadioButton->setIconSize(QSize(16, 16));
        presetReturnTimeSetRadioButton_2 = new QRadioButton(devUpdateWidget);
        presetReturnTimeSetRadioButton_2->setObjectName(QString::fromUtf8("presetReturnTimeSetRadioButton_2"));
        presetReturnTimeSetRadioButton_2->setGeometry(QRect(350, 80, 81, 22));
        presetReturnTimeSetRadioButton_2->setFont(font);
        presetReturnTimeSetRadioButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pollingTimeSetRadioButton_4 = new QRadioButton(devUpdateWidget);
        pollingTimeSetRadioButton_4->setObjectName(QString::fromUtf8("pollingTimeSetRadioButton_4"));
        pollingTimeSetRadioButton_4->setGeometry(QRect(700, 13, 81, 22));
        pollingTimeSetRadioButton_4->setFont(font);
        pollingTimeSetRadioButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pollingTimeSetRadioButton_4->setChecked(false);
        presetReturnTimeSetRadioButton_3 = new QRadioButton(devUpdateWidget);
        presetReturnTimeSetRadioButton_3->setObjectName(QString::fromUtf8("presetReturnTimeSetRadioButton_3"));
        presetReturnTimeSetRadioButton_3->setGeometry(QRect(440, 80, 81, 22));
        presetReturnTimeSetRadioButton_3->setFont(font);
        presetReturnTimeSetRadioButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        presetReturnTimeSetRadioButton_3->setChecked(false);
        pollingTimeSetLabel = new QLabel(devUpdateWidget);
        pollingTimeSetLabel->setObjectName(QString::fromUtf8("pollingTimeSetLabel"));
        pollingTimeSetLabel->setGeometry(QRect(50, 10, 211, 21));
        pollingTimeSetLabel->setFont(font);
        pollingTimeSetLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        presetReturnTimeSetRadioButton = new QRadioButton(devUpdateWidget);
        presetReturnTimeSetRadioButton->setObjectName(QString::fromUtf8("presetReturnTimeSetRadioButton"));
        presetReturnTimeSetRadioButton->setGeometry(QRect(270, 80, 71, 22));
        presetReturnTimeSetRadioButton->setFont(font);
        presetReturnTimeSetRadioButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        presetReturnTimeSetRadioButton_4 = new QRadioButton(devUpdateWidget);
        presetReturnTimeSetRadioButton_4->setObjectName(QString::fromUtf8("presetReturnTimeSetRadioButton_4"));
        presetReturnTimeSetRadioButton_4->setGeometry(QRect(700, 80, 81, 22));
        presetReturnTimeSetRadioButton_4->setFont(font);
        presetReturnTimeSetRadioButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_7 = new QLabel(devUpdateWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(940, 85, 31, 17));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pollingTimeSetRadioButton_2 = new QRadioButton(devUpdateWidget);
        pollingTimeSetRadioButton_2->setObjectName(QString::fromUtf8("pollingTimeSetRadioButton_2"));
        pollingTimeSetRadioButton_2->setGeometry(QRect(350, 13, 61, 22));
        pollingTimeSetRadioButton_2->setFont(font);
        pollingTimeSetRadioButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(devUpdateWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 944, 31));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(" #label { \n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label * { \n"
"     background-color:; \n"
" }"));
        trainTypeSetComboBox = new QComboBox(devUpdateWidget);
        trainTypeSetComboBox->setObjectName(QString::fromUtf8("trainTypeSetComboBox"));
        trainTypeSetComboBox->setGeometry(QRect(130, 45, 161, 27));
        trainTypeSetComboBox->setFont(font);
        presetReturnTimeSetLineEdit = new QLineEdit(devUpdateWidget);
        presetReturnTimeSetLineEdit->setObjectName(QString::fromUtf8("presetReturnTimeSetLineEdit"));
        presetReturnTimeSetLineEdit->setGeometry(QRect(790, 80, 141, 31));
        presetReturnTimeSetLineEdit->setFont(font);
        presetReturnTimeSetLineEdit->setReadOnly(false);
        alarmPushButton = new QPushButton(devUpdateWidget);
        alarmPushButton->setObjectName(QString::fromUtf8("alarmPushButton"));
        alarmPushButton->setGeometry(QRect(590, 570, 80, 34));
        alarmPushButton->setFont(font);
        alarmPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/monres/alertoff.bmp);}\n"
"\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}"));
        alarmPushButton->setCheckable(true);
        label_4 = new QLabel(devUpdateWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(940, 13, 31, 17));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        canselPushButton = new QPushButton(devUpdateWidget);
        canselPushButton->setObjectName(QString::fromUtf8("canselPushButton"));
        canselPushButton->setGeometry(QRect(760, 570, 80, 34));
        canselPushButton->setFont(font);
        canselPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/monres/cancel.bmp);}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}"));
        canselPushButton->setCheckable(true);
        label_17 = new QLabel(devUpdateWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(1100, 430, 16, 18));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        deviceManagewidget = new QWidget(devUpdateWidget);
        deviceManagewidget->setObjectName(QString::fromUtf8("deviceManagewidget"));
        deviceManagewidget->setGeometry(QRect(40, 115, 944, 401));
        configFileDisplayLineEdit = new QLineEdit(deviceManagewidget);
        configFileDisplayLineEdit->setObjectName(QString::fromUtf8("configFileDisplayLineEdit"));
        configFileDisplayLineEdit->setGeometry(QRect(20, 310, 311, 27));
        configFileDisplayLineEdit->setFont(font);
        brightnessLineEdit = new QLineEdit(deviceManagewidget);
        brightnessLineEdit->setObjectName(QString::fromUtf8("brightnessLineEdit"));
        brightnessLineEdit->setGeometry(QRect(540, 300, 81, 31));
        brightnessLineEdit->setFont(font);
        carriageLabel = new QLabel(deviceManagewidget);
        carriageLabel->setObjectName(QString::fromUtf8("carriageLabel"));
        carriageLabel->setGeometry(QRect(480, 264, 51, 17));
        carriageLabel->setFont(font);
        carriageLabel->setStyleSheet(QString::fromUtf8(""));
        configFilelookPushButton = new QPushButton(deviceManagewidget);
        configFilelookPushButton->setObjectName(QString::fromUtf8("configFilelookPushButton"));
        configFilelookPushButton->setGeometry(QRect(350, 310, 110, 30));
        configFilelookPushButton->setFont(font);
        configFilelookPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/monres/browse.bmp);}\n"
"\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}"));
        carriageSelectionComboBox = new QComboBox(deviceManagewidget);
        carriageSelectionComboBox->addItem(QString());
        carriageSelectionComboBox->addItem(QString());
        carriageSelectionComboBox->setObjectName(QString::fromUtf8("carriageSelectionComboBox"));
        carriageSelectionComboBox->setEnabled(true);
        carriageSelectionComboBox->setGeometry(QRect(540, 260, 121, 24));
        carriageSelectionComboBox->setFont(font);
        carriageSelectionComboBox->setMinimumContentsLength(0);
        cameraSelectionComboBox = new QComboBox(deviceManagewidget);
        cameraSelectionComboBox->addItem(QString());
        cameraSelectionComboBox->addItem(QString());
        cameraSelectionComboBox->setObjectName(QString::fromUtf8("cameraSelectionComboBox"));
        cameraSelectionComboBox->setEnabled(true);
        cameraSelectionComboBox->setGeometry(QRect(800, 260, 121, 24));
        cameraSelectionComboBox->setFont(font);
        contrastLineEdit = new QLineEdit(deviceManagewidget);
        contrastLineEdit->setObjectName(QString::fromUtf8("contrastLineEdit"));
        contrastLineEdit->setGeometry(QRect(840, 300, 81, 31));
        contrastLineEdit->setFont(font);
        label_9 = new QLabel(deviceManagewidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(200, 10, 67, 17));
        label_9->setFont(font);
        timeAdjustPushButton = new QPushButton(deviceManagewidget);
        timeAdjustPushButton->setObjectName(QString::fromUtf8("timeAdjustPushButton"));
        timeAdjustPushButton->setGeometry(QRect(190, 140, 135, 37));
        timeAdjustPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/monres/timing.bmp);}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}"));
        label_15 = new QLabel(deviceManagewidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(650, 210, 101, 17));
        label_15->setFont(font);
        comboBox = new QComboBox(deviceManagewidget);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(220, 250, 86, 25));
        saturationLineEdit = new QLineEdit(deviceManagewidget);
        saturationLineEdit->setObjectName(QString::fromUtf8("saturationLineEdit"));
        saturationLineEdit->setGeometry(QRect(690, 300, 81, 31));
        saturationLineEdit->setFont(font);
        imageParamSetPushButton = new QPushButton(deviceManagewidget);
        imageParamSetPushButton->setObjectName(QString::fromUtf8("imageParamSetPushButton"));
        imageParamSetPushButton->setGeometry(QRect(640, 340, 159, 40));
        imageParamSetPushButton->setFont(font);
        imageParamSetPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/monres/settingconfig.bmp);}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}"));
        systimeAdjustLabel = new QLabel(deviceManagewidget);
        systimeAdjustLabel->setObjectName(QString::fromUtf8("systimeAdjustLabel"));
        systimeAdjustLabel->setGeometry(QRect(330, 100, 91, 21));
        saturationLabel = new QLabel(deviceManagewidget);
        saturationLabel->setObjectName(QString::fromUtf8("saturationLabel"));
        saturationLabel->setGeometry(QRect(630, 300, 52, 24));
        saturationLabel->setFont(font);
        saturationLabel->setStyleSheet(QString::fromUtf8(""));
        brightnessLabel = new QLabel(deviceManagewidget);
        brightnessLabel->setObjectName(QString::fromUtf8("brightnessLabel"));
        brightnessLabel->setGeometry(QRect(480, 300, 51, 24));
        brightnessLabel->setFont(font);
        brightnessLabel->setStyleSheet(QString::fromUtf8(""));
        clientRebootPushButton = new QPushButton(deviceManagewidget);
        clientRebootPushButton->setObjectName(QString::fromUtf8("clientRebootPushButton"));
        clientRebootPushButton->setGeometry(QRect(810, 150, 80, 35));
        clientRebootPushButton->setFont(font);
        clientRebootPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/monres/restat.bmp);}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}"));
        configFileSelectionLabel = new QLabel(deviceManagewidget);
        configFileSelectionLabel->setObjectName(QString::fromUtf8("configFileSelectionLabel"));
        configFileSelectionLabel->setGeometry(QRect(20, 280, 101, 17));
        configFileSelectionLabel->setFont(font);
        configFileSelectionLabel->setStyleSheet(QString::fromUtf8(""));
        cameraLabel = new QLabel(deviceManagewidget);
        cameraLabel->setObjectName(QString::fromUtf8("cameraLabel"));
        cameraLabel->setGeometry(QRect(736, 264, 61, 17));
        cameraLabel->setStyleSheet(QString::fromUtf8(""));
        contrastLabel = new QLabel(deviceManagewidget);
        contrastLabel->setObjectName(QString::fromUtf8("contrastLabel"));
        contrastLabel->setGeometry(QRect(780, 300, 52, 24));
        contrastLabel->setFont(font);
        contrastLabel->setStyleSheet(QString::fromUtf8(""));
        configFileImportPushButton = new QPushButton(deviceManagewidget);
        configFileImportPushButton->setObjectName(QString::fromUtf8("configFileImportPushButton"));
        configFileImportPushButton->setGeometry(QRect(50, 350, 80, 35));
        configFileImportPushButton->setFont(font);
        configFileImportPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/monres/in.bmp);}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}"));
        sysDataAdjustLabel = new QLabel(deviceManagewidget);
        sysDataAdjustLabel->setObjectName(QString::fromUtf8("sysDataAdjustLabel"));
        sysDataAdjustLabel->setGeometry(QRect(160, 100, 161, 21));
        QFont font1;
        font1.setPointSize(10);
        sysDataAdjustLabel->setFont(font1);
        sysDataAdjustLabel->setStyleSheet(QString::fromUtf8(""));
        devConfigLabel = new QLabel(deviceManagewidget);
        devConfigLabel->setObjectName(QString::fromUtf8("devConfigLabel"));
        devConfigLabel->setGeometry(QRect(40, 210, 351, 21));
        devConfigLabel->setFont(font);
        devConfigLabel->setStyleSheet(QString::fromUtf8(""));
        updateStatusLabel = new QLabel(deviceManagewidget);
        updateStatusLabel->setObjectName(QString::fromUtf8("updateStatusLabel"));
        updateStatusLabel->setGeometry(QRect(670, 10, 71, 17));
        updateStatusLabel->setFont(font);
        updateStatusLabel->setStyleSheet(QString::fromUtf8(""));
        label_18 = new QLabel(deviceManagewidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(140, 250, 67, 17));
        label_5 = new QLabel(deviceManagewidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 100, 67, 17));
        label_5->setFont(font);
        updateBeginPushButton = new QPushButton(deviceManagewidget);
        updateBeginPushButton->setObjectName(QString::fromUtf8("updateBeginPushButton"));
        updateBeginPushButton->setGeometry(QRect(550, 150, 110, 30));
        updateBeginPushButton->setFont(font);
        updateBeginPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/monres/kaishigegnxin.bmp);}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}"));
        clientRebootPushButton_2 = new QPushButton(deviceManagewidget);
        clientRebootPushButton_2->setObjectName(QString::fromUtf8("clientRebootPushButton_2"));
        clientRebootPushButton_2->setGeometry(QRect(300, 350, 80, 35));
        clientRebootPushButton_2->setFont(font);
        clientRebootPushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/monres/restat.bmp);\n"
"}\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}"));
        updateStatueTextEdit = new QTextEdit(deviceManagewidget);
        updateStatueTextEdit->setObjectName(QString::fromUtf8("updateStatueTextEdit"));
        updateStatueTextEdit->setEnabled(false);
        updateStatueTextEdit->setGeometry(QRect(511, 40, 401, 101));
        updateStatueTextEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(172, 209, 178);"));
        lineEdit = new QLineEdit(deviceManagewidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(0, 0, 461, 191));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_2 = new QLineEdit(deviceManagewidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(470, 0, 471, 191));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_3 = new QLineEdit(deviceManagewidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setGeometry(QRect(0, 195, 461, 201));
        lineEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_4 = new QLineEdit(deviceManagewidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setEnabled(false);
        lineEdit_4->setGeometry(QRect(470, 195, 471, 201));
        lineEdit_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_4->raise();
        lineEdit_3->raise();
        lineEdit_2->raise();
        lineEdit->raise();
        label_15->raise();
        saturationLineEdit->raise();
        imageParamSetPushButton->raise();
        saturationLabel->raise();
        brightnessLabel->raise();
        configFileSelectionLabel->raise();
        cameraLabel->raise();
        contrastLabel->raise();
        configFileImportPushButton->raise();
        devConfigLabel->raise();
        updateStatusLabel->raise();
        label_18->raise();
        label_5->raise();
        updateBeginPushButton->raise();
        brightnessLineEdit->raise();
        cameraSelectionComboBox->raise();
        carriageLabel->raise();
        carriageSelectionComboBox->raise();
        clientRebootPushButton->raise();
        comboBox->raise();
        configFileDisplayLineEdit->raise();
        configFilelookPushButton->raise();
        contrastLineEdit->raise();
        label_9->raise();
        sysDataAdjustLabel->raise();
        timeAdjustPushButton->raise();
        clientRebootPushButton_2->raise();
        systimeAdjustLabel->raise();
        updateStatueTextEdit->raise();
        label_6 = new QLabel(devUpdateWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 0, 1024, 630));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_6->raise();
        label_2->raise();
        label_3->raise();
        pollingTimeSetRadioButton->raise();
        presetReturnTimeSetRadioButton_2->raise();
        pollingTimeSetRadioButton_4->raise();
        presetReturnTimeSetRadioButton_3->raise();
        pollingTimeSetLabel->raise();
        presetReturnTimeSetRadioButton->raise();
        presetReturnTimeSetRadioButton_4->raise();
        label_7->raise();
        pollingTimeSetRadioButton_2->raise();
        label->raise();
        trainTypeSetComboBox->raise();
        presetReturnTimeSetLineEdit->raise();
        alarmPushButton->raise();
        label_4->raise();
        trainTypeSetPushButton->raise();
        pollingTimeSetRadioButton_3->raise();
        pollingTimeSetLineEdit->raise();
        presetReturnTimeSetLabel->raise();
        canselPushButton->raise();
        label_17->raise();
        permissonManagePushButton->raise();
        deviceManagewidget->raise();

        retranslateUi(devUpdateWidget);

        carriageSelectionComboBox->setCurrentIndex(0);
        cameraSelectionComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(devUpdateWidget);
    } // setupUi

    void retranslateUi(QWidget *devUpdateWidget)
    {
        devUpdateWidget->setWindowTitle(QCoreApplication::translate("devUpdateWidget", "Form", nullptr));
        permissonManagePushButton->setText(QString());
        presetReturnTimeSetLabel->setText(QCoreApplication::translate("devUpdateWidget", "\350\247\206\351\242\221\347\224\273\351\235\242\350\277\224\345\233\236\351\242\204\347\275\256\347\202\271\346\227\266\351\227\264\350\256\276\347\275\256", nullptr));
        pollingTimeSetLineEdit->setText(QCoreApplication::translate("devUpdateWidget", "30", nullptr));
        label_3->setText(QString());
        trainTypeSetPushButton->setText(QString());
        pollingTimeSetRadioButton_3->setText(QCoreApplication::translate("devUpdateWidget", "30\347\247\222", nullptr));
        label_2->setText(QString());
        pollingTimeSetRadioButton->setText(QCoreApplication::translate("devUpdateWidget", "10\347\247\222", nullptr));
        presetReturnTimeSetRadioButton_2->setText(QCoreApplication::translate("devUpdateWidget", "10\345\210\206\351\222\237", nullptr));
        pollingTimeSetRadioButton_4->setText(QCoreApplication::translate("devUpdateWidget", "\350\207\252\345\256\232\344\271\211", nullptr));
        presetReturnTimeSetRadioButton_3->setText(QCoreApplication::translate("devUpdateWidget", "15\345\210\206\351\222\237", nullptr));
        pollingTimeSetLabel->setText(QCoreApplication::translate("devUpdateWidget", "\345\217\227\347\224\265\345\274\223\347\233\221\346\216\247\350\275\256\350\257\242\345\210\207\346\215\242\346\227\266\351\227\264\350\256\276\347\275\256", nullptr));
        presetReturnTimeSetRadioButton->setText(QCoreApplication::translate("devUpdateWidget", "5\345\210\206\351\222\237", nullptr));
        presetReturnTimeSetRadioButton_4->setText(QCoreApplication::translate("devUpdateWidget", "\350\207\252\345\256\232\344\271\211", nullptr));
        label_7->setText(QCoreApplication::translate("devUpdateWidget", "\345\210\206\351\222\237", nullptr));
        pollingTimeSetRadioButton_2->setText(QCoreApplication::translate("devUpdateWidget", "20\347\247\222", nullptr));
        label->setText(QCoreApplication::translate("devUpdateWidget", "   \350\275\246\345\236\213\350\256\276\347\275\256:   ", nullptr));
        presetReturnTimeSetLineEdit->setText(QCoreApplication::translate("devUpdateWidget", "15", nullptr));
        alarmPushButton->setText(QString());
        label_4->setText(QCoreApplication::translate("devUpdateWidget", "\347\247\222", nullptr));
        canselPushButton->setText(QString());
        label_17->setText(QString());
        brightnessLineEdit->setText(QCoreApplication::translate("devUpdateWidget", "128", nullptr));
        carriageLabel->setText(QCoreApplication::translate("devUpdateWidget", "\350\275\246\345\216\242\345\217\267:", nullptr));
        configFilelookPushButton->setText(QString());
        carriageSelectionComboBox->setItemText(0, QCoreApplication::translate("devUpdateWidget", "1\345\217\267\350\275\246\345\216\242", nullptr));
        carriageSelectionComboBox->setItemText(1, QCoreApplication::translate("devUpdateWidget", "8\345\217\267\350\275\246\345\216\242", nullptr));

        cameraSelectionComboBox->setItemText(0, QCoreApplication::translate("devUpdateWidget", "8\345\217\267\346\221\204\345\203\217\346\234\272", nullptr));
        cameraSelectionComboBox->setItemText(1, QCoreApplication::translate("devUpdateWidget", "9\345\217\267\346\221\204\345\203\217\346\234\272", nullptr));

        contrastLineEdit->setText(QCoreApplication::translate("devUpdateWidget", "128", nullptr));
        label_9->setText(QCoreApplication::translate("devUpdateWidget", "\346\211\213\345\212\250\346\240\241\346\227\266", nullptr));
        timeAdjustPushButton->setText(QString());
        label_15->setText(QCoreApplication::translate("devUpdateWidget", "\345\233\276\345\275\242\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("devUpdateWidget", "\347\273\210\347\253\257\350\275\257\344\273\266", nullptr));

        saturationLineEdit->setText(QCoreApplication::translate("devUpdateWidget", "128", nullptr));
        imageParamSetPushButton->setText(QString());
        systimeAdjustLabel->setText(QString());
        saturationLabel->setText(QCoreApplication::translate("devUpdateWidget", "\351\245\261\345\222\214\345\272\246:", nullptr));
        brightnessLabel->setText(QCoreApplication::translate("devUpdateWidget", "\344\272\256   \345\272\246:", nullptr));
        clientRebootPushButton->setText(QString());
        configFileSelectionLabel->setText(QCoreApplication::translate("devUpdateWidget", "\351\200\211\346\213\251\351\205\215\347\275\256\346\226\207\344\273\266:", nullptr));
        cameraLabel->setText(QCoreApplication::translate("devUpdateWidget", "   \346\221\204\345\203\217\346\234\272:", nullptr));
        contrastLabel->setText(QCoreApplication::translate("devUpdateWidget", "\345\257\271\346\257\224\345\272\246:", nullptr));
        configFileImportPushButton->setText(QString());
        sysDataAdjustLabel->setText(QString());
        devConfigLabel->setText(QCoreApplication::translate("devUpdateWidget", "                                         \350\256\276\345\244\207\351\205\215\347\275\256", nullptr));
        updateStatusLabel->setText(QCoreApplication::translate("devUpdateWidget", "\347\250\213\345\272\217\346\233\264\346\226\260", nullptr));
        label_18->setText(QCoreApplication::translate("devUpdateWidget", "\350\256\276\345\244\207\351\200\211\346\213\251:", nullptr));
        label_5->setText(QCoreApplication::translate("devUpdateWidget", "\347\263\273\347\273\237\346\227\266\351\227\264", nullptr));
        updateBeginPushButton->setText(QString());
        clientRebootPushButton_2->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class devUpdateWidget: public Ui_devUpdateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVUPDATEWIDGET_H

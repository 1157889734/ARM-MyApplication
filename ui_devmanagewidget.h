/********************************************************************************
** Form generated from reading UI file 'devmanagewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVMANAGEWIDGET_H
#define UI_DEVMANAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_devManageWidget
{
public:
    QLineEdit *TrainNumberLineEdit;
    QLabel *TrainNumberlabel;
    QPushButton *TrainNumberSetPushButton;
    QPushButton *alarmPushButton;
    QPushButton *canselPushButton;
    QTableWidget *devStorageTableWidget;
    QTableWidget *devStatusTableWidget;
    QLabel *devStatusLabel;
    QLabel *devStorageLabel;
    QLabel *label_2;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;

    void setupUi(QWidget *devManageWidget)
    {
        if (devManageWidget->objectName().isEmpty())
            devManageWidget->setObjectName(QString::fromUtf8("devManageWidget"));
        devManageWidget->resize(1024, 630);
        TrainNumberLineEdit = new QLineEdit(devManageWidget);
        TrainNumberLineEdit->setObjectName(QString::fromUtf8("TrainNumberLineEdit"));
        TrainNumberLineEdit->setGeometry(QRect(550, 10, 161, 27));
        QFont font;
        font.setPointSize(12);
        TrainNumberLineEdit->setFont(font);
        TrainNumberlabel = new QLabel(devManageWidget);
        TrainNumberlabel->setObjectName(QString::fromUtf8("TrainNumberlabel"));
        TrainNumberlabel->setGeometry(QRect(470, 10, 71, 21));
        TrainNumberlabel->setFont(font);
        TrainNumberlabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);"));
        TrainNumberSetPushButton = new QPushButton(devManageWidget);
        TrainNumberSetPushButton->setObjectName(QString::fromUtf8("TrainNumberSetPushButton"));
        TrainNumberSetPushButton->setGeometry(QRect(850, 10, 137, 35));
        TrainNumberSetPushButton->setFont(font);
        TrainNumberSetPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/monres/ccsz.bmp);\n"
"border-color: rgb(255, 255, 255);\n"
"border-width: 1px;\n"
"border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-image: url(:/res/pressed-137-35.bmp);\n"
"	background-color: rgb(211, 215, 207);\n"
"   border-style: dashed; /*\350\276\271\346\241\206\346\240\267\345\274\217*/\n"
"   border-width: 1px;  /*\350\276\271\346\241\206\345\256\275\345\272\246\344\270\2724\345\203\217\347\264\240*/\n"
"}"));
        alarmPushButton = new QPushButton(devManageWidget);
        alarmPushButton->setObjectName(QString::fromUtf8("alarmPushButton"));
        alarmPushButton->setGeometry(QRect(480, 590, 82, 36));
        alarmPushButton->setFont(font);
        alarmPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/monres/alertoff.bmp);\n"
"border-color: rgb(255, 255, 255);\n"
"border-width: 1px;\n"
"border-style: solid;}\n"
"\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}"));
        alarmPushButton->setCheckable(true);
        canselPushButton = new QPushButton(devManageWidget);
        canselPushButton->setObjectName(QString::fromUtf8("canselPushButton"));
        canselPushButton->setGeometry(QRect(720, 590, 82, 36));
        canselPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/monres/cancel.bmp);\n"
"border-color: rgb(255, 255, 255);\n"
"border-width: 1px;\n"
"border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}"));
        devStorageTableWidget = new QTableWidget(devManageWidget);
        devStorageTableWidget->setObjectName(QString::fromUtf8("devStorageTableWidget"));
        devStorageTableWidget->setGeometry(QRect(30, 360, 964, 211));
        devStorageTableWidget->setFont(font);
        devStorageTableWidget->setStyleSheet(QString::fromUtf8("border-style: none;\n"
"background-color: rgb(255, 255, 255);\n"
"gridline-color: rgb(130, 135, 144);\n"
"border-color: rgb(130, 135, 144);\n"
"border-width: 1px;border-style: solid;"));
        devStorageTableWidget->setFrameShape(QFrame::StyledPanel);
        devStorageTableWidget->setShowGrid(false);
        devStorageTableWidget->setColumnCount(0);
        devStorageTableWidget->horizontalHeader()->setVisible(false);
        devStorageTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        devStorageTableWidget->horizontalHeader()->setMinimumSectionSize(61);
        devStorageTableWidget->horizontalHeader()->setDefaultSectionSize(100);
        devStorageTableWidget->horizontalHeader()->setHighlightSections(true);
        devStorageTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        devStorageTableWidget->horizontalHeader()->setStretchLastSection(false);
        devStorageTableWidget->verticalHeader()->setVisible(false);
        devStorageTableWidget->verticalHeader()->setHighlightSections(false);
        devStatusTableWidget = new QTableWidget(devManageWidget);
        devStatusTableWidget->setObjectName(QString::fromUtf8("devStatusTableWidget"));
        devStatusTableWidget->setGeometry(QRect(30, 80, 964, 231));
        devStatusTableWidget->setFont(font);
        devStatusTableWidget->setStyleSheet(QString::fromUtf8("border-style: none;\n"
"background-color: rgb(255, 255, 255);\n"
"gridline-color: rgb(130, 135, 144);\n"
"border-color: rgb(130, 135, 144);\n"
"border-width: 1px;border-style: solid;"));
        devStatusTableWidget->setProperty("showDropIndicator", QVariant(true));
        devStatusTableWidget->setShowGrid(false);
        devStatusTableWidget->verticalHeader()->setVisible(false);
        devStatusLabel = new QLabel(devManageWidget);
        devStatusLabel->setObjectName(QString::fromUtf8("devStatusLabel"));
        devStatusLabel->setGeometry(QRect(30, 55, 81, 21));
        devStatusLabel->setFont(font);
        devStatusLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        devStorageLabel = new QLabel(devManageWidget);
        devStorageLabel->setObjectName(QString::fromUtf8("devStorageLabel"));
        devStorageLabel->setGeometry(QRect(30, 335, 81, 21));
        devStorageLabel->setFont(font);
        devStorageLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_2 = new QLabel(devManageWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 1024, 661));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox = new QGroupBox(devManageWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(12, 50, 1000, 271));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	border-width:1px;\n"
"	border-style:solid;\n"
"	border-color:black;\n"
"}"));
        groupBox_2 = new QGroupBox(devManageWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(12, 330, 1000, 251));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	border-width:1px;\n"
"	border-style:solid;\n"
"	border-color:black;\n"
"}"));
        label_2->raise();
        alarmPushButton->raise();
        TrainNumberLineEdit->raise();
        TrainNumberlabel->raise();
        TrainNumberSetPushButton->raise();
        canselPushButton->raise();
        devStatusLabel->raise();
        devStorageLabel->raise();
        groupBox->raise();
        devStatusTableWidget->raise();
        groupBox_2->raise();
        devStorageTableWidget->raise();

        retranslateUi(devManageWidget);

        QMetaObject::connectSlotsByName(devManageWidget);
    } // setupUi

    void retranslateUi(QWidget *devManageWidget)
    {
        devManageWidget->setWindowTitle(QCoreApplication::translate("devManageWidget", "Form", nullptr));
        TrainNumberlabel->setText(QCoreApplication::translate("devManageWidget", "\345\275\223\345\211\215\350\275\246\346\254\241", nullptr));
        TrainNumberSetPushButton->setText(QString());
        alarmPushButton->setText(QString());
        canselPushButton->setText(QString());
        devStatusLabel->setText(QCoreApplication::translate("devManageWidget", "\350\256\276\345\244\207\347\212\266\346\200\201", nullptr));
        devStorageLabel->setText(QCoreApplication::translate("devManageWidget", "\345\255\230\345\202\250\347\212\266\346\200\201", nullptr));
        label_2->setText(QString());
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class devManageWidget: public Ui_devManageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVMANAGEWIDGET_H

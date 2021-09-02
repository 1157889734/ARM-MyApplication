/********************************************************************************
** Form generated from reading UI file 'ckeyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CKEYBOARD_H
#define UI_CKEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CKeyboard
{
public:
    QWidget *widget_KeyBoard;

    void setupUi(QWidget *CKeyboard)
    {
        if (CKeyboard->objectName().isEmpty())
            CKeyboard->setObjectName(QString::fromUtf8("CKeyboard"));
        CKeyboard->resize(400, 300);
        widget_KeyBoard = new QWidget(CKeyboard);
        widget_KeyBoard->setObjectName(QString::fromUtf8("widget_KeyBoard"));
        widget_KeyBoard->setGeometry(QRect(190, 80, 120, 80));

        retranslateUi(CKeyboard);

        QMetaObject::connectSlotsByName(CKeyboard);
    } // setupUi

    void retranslateUi(QWidget *CKeyboard)
    {
        CKeyboard->setWindowTitle(QCoreApplication::translate("CKeyboard", "CKeyboard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CKeyboard: public Ui_CKeyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CKEYBOARD_H

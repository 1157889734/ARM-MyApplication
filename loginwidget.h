#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include "ckeyboard.h"


namespace Ui {
class loginWidget;
}

typedef enum _E_DEVTYPE
{
    E_CVMSTYPE = 1,     //车厢监控设备
    E_PVMSTYPE = 2      //受电弓监控设备
} E_DEVTYPE;

class loginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit loginWidget(QWidget *parent = nullptr);
    ~loginWidget();
#ifdef KEYBOARD
    bool eventFilter(QObject *obj, QEvent *e);
#endif

signals:
    void loginCanselSignal();
    void gotoPvmsMenuPageSignal();


public slots:
    void okButtonSlot();
    void canselButtonSlot();
    void showPageSlot();  //显示当前页面的响应槽函数，这里iType代表接收到的参数，表示页面类型，1-车厢监控页面，2-受电弓监控页面
#ifdef KEYBOARD
    void KeyboardPressKeySlots(char key);
#endif

private:
    Ui::loginWidget *ui;
    int m_iLoginType;
#ifdef KEYBOARD
    CKeyboard *mCkeybord;
#endif
};

#endif // LOGINWIDGET_H

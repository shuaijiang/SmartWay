#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include "login.h"
#include "OneToOne.h"
#include "bus.h"
#include "bus_system.h"
#include <algorithm>
#include "result.h"
namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    Ui::Widget *ui;
private slots:
    void on_pushButton_BusChange_clicked();
    void on_pushButton_Update_clicked();
    void on_pushButton_DeleteBus_clicked();
    void on_pushButton_Add_clicked();
    void on_pushButton_OneBus_clicked();
    void on_pushButton_StationQuery_clicked();
    void on_pushButton_QueryAll_clicked();
    void on_pushButton_Logout_clicked();
    void on_pushButton_Quit_clicked();
    void on_pushButton_Login_clicked();
    void showOTO();
    void showOTOPrice();
    void showOTODistance();
};

#endif // WIDGET_H

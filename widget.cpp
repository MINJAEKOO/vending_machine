#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ckMoney(){
    if(money >= 100)
        ui->pbCoffee->setEnabled(true);
    else if (money < 100) {
        ui->pbCoffee->setEnabled(false);
    }
    if(money >= 150)
        ui->pbTea->setEnabled(true);
    else if (money < 150) {
        ui->pbTea->setEnabled(false);
    }
    if(money >= 200)
        ui->pbCass->setEnabled(true);
    else if (money < 200) {
        ui->pbCass->setEnabled(false);
    }
}

void Widget::changeMoney(int n)
{
    money += n;
    ui->lcdNumber->display(QString::number(money));
    ckMoney();
}

void Widget::Change()
{
    ckMoney();
    int cha;
    fhund=money/500;
    cha=money%500;
    hund=cha/100;
    cha=money%100;
    fifty=cha/50;
    cha=money%50;
    ten=cha/10;
}


void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbCass_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbChange_clicked()
{
    QMessageBox msg;
    Change();
    QString change = QString("10원 : %1개\n50원 : %2개\n100원 : %3개\n500원 : %4개\n").arg(ten).arg(fifty).arg(hund).arg(fhund);
    msg.information(nullptr, "거스름돈", change);
    money = 0;
    changeMoney(money);
}

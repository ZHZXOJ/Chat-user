#include "alreadylogin.h"
#include "ui_alreadylogin.h"
#include <QDebug>

extern int logout;

alreadylogin::alreadylogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alreadylogin)
{
    ui->setupUi(this);
    this->setWindowTitle("您已登录");
}

alreadylogin::~alreadylogin()
{
    delete ui;
}

void alreadylogin::on_pushButton_clicked()
{
    alreadylogin::close();
}

void alreadylogin::on_pushButton_2_clicked()
{
    logout=1;
    qDebug() << logout << "我是登出窗口传的参数";
    alreadylogin::close();
}

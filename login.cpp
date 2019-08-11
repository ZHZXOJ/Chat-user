#include "login.h"
#include "ui_dialog.h"
#include <mainwindow.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
}

Dialog::~Dialog()
{
    delete ui;
}

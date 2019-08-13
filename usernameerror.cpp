#include "usernameerror.h"
#include "ui_usernameerror.h"

usernamEerror::usernamEerror(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usernamEerror)
{
    ui->setupUi(this);
    this->setWindowTitle("Error");
}

usernamEerror::~usernamEerror()
{
    delete ui;
}

void usernamEerror::on_pushButton_clicked()
{
    usernamEerror::close();
}

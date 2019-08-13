#include "login.h"
#include "ui_login.h"
#include <mainwindow.h>
#include <alreadylogin.h>
#include <usernameerror.h>
#include <QDebug>

extern QString username;
int logout;

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

void Dialog::on_pushButton_clicked()
{
    QString lsname = ui->lineEdit->text();
    int len=lsname.size();
    if(len>20||len==0)
    {
        usernamEerror a;
        a.show();
    }
    for (int i=0;i<len;++i)
    {
        if((lsname[i]>='0'&&lsname[i]<='9')||(lsname[i]>='a'&&lsname[i]<='z')||(lsname[i]>='A'&&lsname[i]<='Z'))
            continue;
        else {
            usernamEerror a;
            a.exec();
            return;
        }
    }
    if(lsname==username&&username!="")
    {
        alreadylogin a;
        a.exec();
        qDebug() << logout << "QAQ" << username;
        if(logout==1)
        {
            lsname=username="";
            qDebug() << logout << "QAQ" << username;
        }
        Dialog::close();
    }

    username=lsname;
    Dialog::close();
}

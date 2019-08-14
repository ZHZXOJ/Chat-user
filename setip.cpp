#include "setip.h"
#include "ui_setip.h"

extern QString ServerIP;

setIP::setIP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setIP)
{
    ui->setupUi(this);
    ui->lineEdit->setText(ServerIP);
}

setIP::~setIP()
{
    delete ui;
}

void setIP::on_pushButton_clicked()
{
    QString lsIP = ui->lineEdit->text();
    int len=lsIP.size(),pointt=0,numberr=0;
    for (int i=0;i<len;++i)
    {

        if((lsIP[i]>='0'&&lsIP[i]<='9')||(lsIP[i]=='.'))
            continue;
        else
        {
            ui->label_3->setText("IP不合法");
            return;
        }
        if(lsIP[i]=='.')
            pointt++;
        if(lsIP[i]>='0'&&lsIP[i]<='9')
            numberr++;
    }
    if(pointt>3||numberr>12)
    {
        ui->label_3->setText("IP不合法");
        return;
    }
    ServerIP=lsIP;
    setIP::close();
}

void setIP::on_pushButton_2_clicked()
{
    setIP::close();
}

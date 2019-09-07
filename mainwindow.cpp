#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QMenuBar>
#include <login.h>
#include <setip.h>
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QDataStream>

QString username="";
QString ServerIP="127.0.0.1";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Chat");
    if(username=="")
    {
        ui->label_7->setText("您还没有登录，请先登录QAQ");
    }
    else
    {
        ui->label_7->setText("您好"+username+"，欢迎使用Chat");
    }
    qDebug() << username;
    connect(&tcpSocket,SIGNAL(readyRead()),
            this,SLOT(onReadReady()));
    connect(&tcpSocket,SIGNAL(connected()),
            this,SLOT(onConnected()));
    connect(&tcpSocket,SIGNAL(disconnected()),
            this,SLOT(onDisconnected()));
    connect(&tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(onError(QAbstractSocket::SocketError)));

    imageIndex = 0;
    sizePackLast = 0;

    tcpSocket.connectToHost(ServerIP,8888);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSign_in_triggered()
{
    if(ui->label->text()!="连接成功"+ServerIP)
        return;
    Dialog a;
    a.exec();
    if(username=="")
    {
        ui->label_7->setText("您还没有登录，请先登录QAQ");
    }
    else
    {
        ui->label_7->setText("您好"+username+"欢迎使用Chat");
    }
    qDebug() << username;
}

void MainWindow::onReadReady()
{
    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);

    quint64 sizeNow =0 ;
    //已发送
    do{
        sizeNow = socket->bytesAvailable();
        QDataStream stream(socket);

        if(sizePackLast == 0)
        {
            if(sizeNow < sizeof (quint32))
            {
                return;
            }

            stream >> sizePackLast;
        }

        if(sizeNow < sizePackLast - 4)
        {
            return;
        }
        qDebug()<<"full pack";
        QByteArray dataFull;
        stream >> dataFull;
        //剩下的字节
        sizeNow = socket->bytesAvailable();
        qDebug()<<dataFull;
        QString pre = dataFull.mid(0,4);
        if(pre == "TXT:")
            ui->textEdit->insertPlainText(dataFull.mid(4));
        else if (pre == "IMG:")
        {

        }
    }while(sizeNow > 0);
}

void MainWindow::onConnected()
{
    qDebug() << "connected" ;
    ui->label->setText("连接成功"+ServerIP);
}

void MainWindow::onDisconnected()
{
    qDebug() << "disconnected" ;
    ui->label->setText("连接断开");
}

void MainWindow::onError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "error:" << socketError;
    ui->label->setText("连接错误");
}

void MainWindow::on_actionExit_triggered()
{
    MainWindow::close();
}

void MainWindow::on_actionSign_out_triggered()
{
    username="";
    if(username=="")
    {
        ui->label_7->setText("您还没有登录，请先登录QAQ");
    }
    else
    {
        ui->label_7->setText("您好"+username+"，欢迎使用Chat");
    }
    qDebug() << username;
}

void MainWindow::on_actionsetting_triggered()
{
    QString TMP=ServerIP;
    setIP a;
    a.exec();
    if(TMP!=ServerIP)
        tcpSocket.connectToHost(ServerIP,8888);
}

void MainWindow::on_actionconnecting_triggered()
{
    if(ui->label->text()!="连接成功"+ServerIP)
        tcpSocket.connectToHost(ServerIP,8888);
}

void MainWindow::on_pushButton_clicked()
{
    if(username=="")
    {
        Dialog a;
        a.exec();
        if(username=="")
        {
            ui->label_7->setText("您还没有登录，请先登录QAQ");
        }
        else
        {
            ui->label_7->setText("您好"+username+"欢迎使用Chat");
        }
        return;
    }
    if(ui->label->text()!="连接成功"+ServerIP)
    {
        ui->label->setText("请尝试重新连接");
        return;
    }
    QString msgInput = ui->lineEdit->text();

    msgInput = "TXT:"+username+":\n"+msgInput;

    QByteArray dataSend;

    QDataStream stream(&dataSend,QIODevice::WriteOnly);
    stream<<(quint32)0<<msgInput.toLocal8Bit();
    stream.device()->seek(0);
    stream<<dataSend.size();

    tcpSocket.write(dataSend);

    qDebug()<<dataSend;
}

void MainWindow::on_actionTo_User_triggered()
{

}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QMenuBar>
#include <login.h>
#include <setip.h>
#include <QDebug>

QString username;
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

    tcpSocket.connectToHost(ServerIP,8888);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSign_in_triggered()
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
    qDebug() << username;
}

void MainWindow::onReadReady()
{
    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
    QByteArray data = socket ->readAll();
    qDebug() << "read:" << data;
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
    setIP a;
    a.exec();
    tcpSocket.connectToHost(ServerIP,8888);
}

void MainWindow::on_actionconnecting_triggered()
{
    tcpSocket.connectToHost(ServerIP,8888);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QMenuBar>
#include <login.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Chat");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSign_in_triggered()
{
    Dialog a;
    a.exec();
}

void MainWindow::on_actionExit_triggered()
{
    MainWindow::close();
}

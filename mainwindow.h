#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionSign_in_triggered();

    void on_actionSign_out_triggered();

    void on_actionsetting_triggered();

    void on_actionconnecting_triggered();

    void on_pushButton_clicked();

    void on_actionTo_User_triggered();

    void on_actiondelet_triggered();

public slots:
    void onReadReady();
    void onConnected();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError socketError);

private:
    Ui::MainWindow *ui;
    QTcpSocket tcpSocket;

    int imageIndex;

    quint32 sizePackLast;
};

#endif // MAINWINDOW_H

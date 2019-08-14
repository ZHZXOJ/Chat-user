#ifndef SETIP_H
#define SETIP_H

#include <QDialog>

namespace Ui {
class setIP;
}

class setIP : public QDialog
{
    Q_OBJECT

public:
    explicit setIP(QWidget *parent = nullptr);
    ~setIP();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::setIP *ui;
};

#endif // SETIP_H

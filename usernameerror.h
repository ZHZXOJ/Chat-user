#ifndef USERNAMEERROR_H
#define USERNAMEERROR_H

#include <QDialog>

namespace Ui {
class usernamEerror;
}

class usernamEerror : public QDialog
{
    Q_OBJECT

public:
    explicit usernamEerror(QWidget *parent = nullptr);
    ~usernamEerror();

private slots:
    void on_pushButton_clicked();

private:
    Ui::usernamEerror *ui;
};

#endif // USERNAMEERROR_H

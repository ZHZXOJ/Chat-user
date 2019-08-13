#ifndef ALREADYLOGIN_H
#define ALREADYLOGIN_H

//#include <QWidget>
#include <QDialog>

namespace Ui {
class alreadylogin;
}

class alreadylogin : public QDialog
{
    Q_OBJECT

public:
    explicit alreadylogin(QWidget *parent = nullptr);
    ~alreadylogin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::alreadylogin *ui;
};

#endif // ALREADYLOGIN_H

#ifndef MAINSIGNUP_H
#define MAINSIGNUP_H

#include <QMainWindow>
#include <QTimeEdit>
namespace Ui {
class MainSignup;
}

class MainSignup : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainSignup(QWidget *parent = nullptr);
    ~MainSignup();

private slots:

    void on_signup_btn_clicked();

private:
    Ui::MainSignup *ui;
};

#endif // MAINSIGNUP_H

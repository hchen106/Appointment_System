#ifndef SIGNUPUI_H
#define SIGNUPUI_H

#include <QMainWindow>

namespace Ui {
class signup;
}

class signup : public QMainWindow
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_signup_btn_clicked();

private:
    Ui::signup *ui;
};

#endif // SIGNUPUI_H

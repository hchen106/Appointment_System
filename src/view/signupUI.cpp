#include "src/view/UI.h"
#include "ui_signup.h"
//#include "src/view/signupUI.h"

signup::signup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_signup_btn_clicked()
{

}

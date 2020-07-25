#include "view/UI.h"
#include "ui_login.h"
#include "controller/LoginUIController.h"

LoginUI::LoginUI(QWidget *parent): QMainWindow(parent), ui(new Ui::LoginUI)
{   
    this->IP = "localhost";
    this->PORT = 8000;
    std::cout << this->IP  + " " + std::to_string(this->PORT) << std::endl;
    Controller::LoginUIController *l = new Controller::LoginUIController(this->IP, this->PORT);
    ui->setupUi(this);
}

LoginUI::~LoginUI()
{
    delete ui;
}

void LoginUI::on_signup_btn_clicked() {
    signupui = new signup(this);
    signupui -> show();


}

void LoginUI::on_login_btn_clicked() {
    //if(isVertified() == "id") {
        mainwindow = new MainWindow(this);
        mainwindow -> show();
        this -> hide();
    //}
}


#include "UI.h"
#include "ui_login.h"
#include "src/controller/LoginUIController.h"

LoginUI::LoginUI(QWidget *parent): QMainWindow(parent), ui(new Ui::LoginUI)
{   
    this->IP = "localhost";
    this->PORT = 8001;
    std::cout << this->IP  + " " + std::to_string(this->PORT) << std::endl;
    Controller::LoginUIController *l = new Controller::LoginUIController(this->IP, this->PORT);
    ui->setupUi(this);
}

LoginUI::~LoginUI()
{
    delete ui;
}


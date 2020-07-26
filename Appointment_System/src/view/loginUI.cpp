#include "UI.h"
#include "ui_login.h"
#include "src/controller/LoginUIController.h"

LoginUI::LoginUI(QWidget *parent): QMainWindow(parent), ui(new Ui::LoginUI)
{   
    this->IP = "192.168.1.9";
    this->PORT = 8002;
    std::cout << this->IP  + " " + std::to_string(this->PORT) << std::endl;
    this->controller = new Controller::LoginUIController(this->IP, this->PORT);
    ui->setupUi(this);
}

LoginUI::~LoginUI()
{
    delete ui;
}

void LoginUI::on_login_btn_clicked(){
    std::string loginID = this->get_text(ui->id_entry->text());
    std::string password = this->get_text(ui->password_entry->text());
    //std::cout << loginID << std::endl;
    //std::cout << password << std::endl;
    this->controller->isVertified(loginID, password);



    
}

std::string LoginUI::get_text(QString qs) {
    return qs.toUtf8().constData();
}

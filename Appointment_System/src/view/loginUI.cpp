#include "UI.h"
#include "ui_login.h"
#include "src/controller/controller.h"
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <QCloseEvent>

LoginUI::LoginUI(QWidget *parent): QMainWindow(parent), ui(new Ui::LoginUI)
{   
    this->IP = "192.168.1.10";
    this->PORT = 8003;
    std::cout << this->IP  + " " + std::to_string(this->PORT) << std::endl;
    ui->setupUi(this);
    
}

LoginUI::~LoginUI()
{
    delete ui;
}

void LoginUI::closeEvent(QCloseEvent *event) {
    if(this->controller != NULL) {
        this->controller->closeConnection();
        event->accept();
    }
}

void LoginUI::on_login_btn_clicked(){
    boost::asio::io_service io_service;
    boost::asio::ssl::context ctx(boost::asio::ssl::context::sslv23);
    ctx.load_verify_file("src/controller/user.crt");
    this->controller = new Controller::LoginUIController(this->IP, this->PORT,io_service,ctx);
    //this->controller->TcpConnection();
    std::string loginID = this->get_text(ui->id_entry->text());
    std::string password = this->get_text(ui->password_entry->text());
    //std::cout << loginID << std::endl;
    //std::cout << password << std::endl;
    std::string vertified = this->controller->isVertified(loginID, password);

    if(vertified == "Successful") {
        std::cout << "Successfully logined" << std::endl;

        //Open the MainWindow
        MainWindowUI *mainwindow = new MainWindowUI(this);
        QString id = QString::fromStdString(loginID);
        mainwindow->setLoginID(id);
        mainwindow->show();
        
        Controller::MainWindowUIController *mainController= this->controller->createMainWindowController();
        mainwindow->createController(mainController);
        this->hide();


    }else{
        std::cout << vertified << std::endl;
    }
    

    
}

std::string LoginUI::get_text(QString qs) {
    return qs.toUtf8().constData();
}

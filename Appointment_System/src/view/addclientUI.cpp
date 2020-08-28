#include "src/view/UI.h"
#include "ui_addclient.h"
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include "src/controller/controller.h"
static const QString path = "/home/huihao/Desktop/master/Appointment_System/Appointment_System/src/controller/provider.db";

addClientUI::addClientUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addClientUI)
{
    ui->setupUi(this);
    
}

addClientUI::~addClientUI()
{
    delete ui;
}




void addClientUI::on_add_btn_clicked()
{
    QString name = ui->add_name_entry->text();
    QString email = ui->add_email_entry->text();
    QString address = ui->add_address_entry->text();
    QString phone = ui->add_phone_entry->text();
    QString birthday = ui->add_birthday_entry->text();
    QString provider = ui->provider_entry->text();
    QString providerID = getLoginID();

    std::string name_ = name.toUtf8().constData();
    std::string email_ = email.toUtf8().constData();
    std::string address_ = address.toUtf8().constData();
    std::string phone_ = phone.toUtf8().constData();
    std::string birthday_ = birthday.toUtf8().constData();
    std::string provider_ = provider.toUtf8().constData();
    std::string providerID_ = providerID.toUtf8().constData();


    bool rlt = addClientController->sendInformation(name_, email_, address_, phone_, birthday_, provider_, providerID_);

    if(rlt == true) {
        QMessageBox::information(this, "add", "Client is Successfully added");
        
    }else {
        QMessageBox::information(this, "add", "Client is fail to add");
    }
    ui->add_name_entry->setText(" ");
    ui->add_email_entry->setText(" ");
    ui->add_address_entry->setText(" ");
    ui->add_phone_entry->setText(" ");
    ui->add_birthday_entry->setText(" ");
    ui->provider_entry->setText(" ");
   
}


void addClientUI::createController(Controller::addClientController *controller) {
    addClientController = controller;
}
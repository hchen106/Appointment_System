#include "src/view/UI.h"
#include "ui_addclient.h"
#include "src/controller/DbManager.h"
#include <QMessageBox>
#include <QDebug>
#include <QString>
static const QString path = "/home/huihao/Desktop/myDB/Appointment_System/Appointment_System/src/controller/provider.db";

addClient::addClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addClient)
{
    ui->setupUi(this);
}

addClient::~addClient()
{
    delete ui;
}


void addClient::on_add_btn_clicked()
{
    DbManager db(path);
    QString name = ui->add_name_entry->text();
    QString email = ui->add_email_entry->text();
    QString address = ui->add_address_entry->text();
    QString phone = ui->add_phone_entry->text();
    QString birthday = ui->add_birthday_entry->text();
    QString provider = ui->provider_entry->text();
    QString providerID = getLoginID();

    if(db.addNewClient(name, birthday, email, provider, phone, address, providerID)){
        QMessageBox::information(this, "add", "Client is Successfully added");
    }else{
        QMessageBox::information(this, "add", "Client is fail to add");
    }
}

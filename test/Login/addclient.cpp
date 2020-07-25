#include "addclient.h"
#include "ui_addclient.h"
#include "DbManager.h"
#include <QMessageBox>
#include <QDebug>
#include <QString>
static const QString path = "/home/huihao/Desktop/newclone/Appointment_System/test/Login/provider.db";

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

    if(db.addNewClient(name, birthday, email, provider, phone, address)){
        QMessageBox::information(this, "add", "Client is Successfully added");
    }else{
        QMessageBox::information(this, "add", "Client is fail to add");
    }
}

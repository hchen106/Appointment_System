#include "editclient.h"
#include "ui_editclient.h"
#include "DbManager.h"
#include <QDebug>
#include <QMessageBox>
static const QString path = "/home/huihao/Desktop/myDB/Appointment_System/test/Login/provider.db";

editclient::editclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editclient)
{
    QString name = getName();
    qDebug() << getName();
    ui->setupUi(this);
    ui->add_name_entry->setText(getName());
}

    
editclient::~editclient()
{
    delete ui;
}

void editclient::on_update_btn_clicked()
{
    
    DbManager db(path);
    QString name = ui->add_name_entry->text();
    QString email = ui->add_email_entry->text();
    QString address = ui->add_address_entry->text();
    QString phone = ui->add_phone_entry->text();
    QString birthday = ui->add_birthday_entry->text();
    QString provider = ui->provider_entry->text();
    QString id = getid();
    if(db.updateClientInfo(id, name, birthday, email, provider, phone, address)){
        QMessageBox::information(this, "add", "Client is Successfully updated");
    }else{
        QMessageBox::information(this, "add", "Client is fail to updated");
    }
}


void editclient::on_load_btn_clicked()
{
    DbManager db(path);
    QString name = getName();
    QString info = db.getClientInfo(name);
    QStringList list = info.split("+");
    qDebug() << list;
    ui->add_name_entry->setText(list[0]);
    ui->add_birthday_entry->setText(list[1]);
    ui->add_email_entry->setText(list[2]);
    ui->add_address_entry->setText(list[3]);
    ui->provider_entry->setText(list[4]);
    ui->add_phone_entry->setText(list[6]);
    setid(list[7]);

}

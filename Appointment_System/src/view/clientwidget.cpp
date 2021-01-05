#include "src/view/UI.h"
#include "ui_clientwidget.h"


clientwidget::clientwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientwidget)
{
    ui->setupUi(this);
}

clientwidget::~clientwidget()
{
    delete ui;
}

void clientwidget::showEvent(QShowEvent *ev) {
    QWidget::showEvent(ev);
    //picIcon();
}

void clientwidget::picIcon(Json::Value info) {
    QPixmap pixmap("/Users/xinhaoxiao/Desktop/document/Appointment_System/Appointment_System/src/resource/icon.png");
    ui->Picture_label->setPixmap(pixmap);
    //ui->Picture_label->setMask(pixmap.mask());
    ui->Picture_label->setScaledContents( true );
    ui->Picture_label->show();
    std::string name = info["name"].asString();
    std::string phone = info["phone"].asString();
    
    ui->name_label->setText(QString::fromStdString(name));
    ui->name_label->setStyleSheet("font-weight: bold");
    ui->phone_label->setText(QString::fromStdString(phone));
    //ui->address_label->setText("412 Hight Ave, \nSan Francisco, CA, 94112");
    //ui->address_label->setWordWrap(true);
    //ui->view_btn->setStyleSheet("QPushButton { background-color: rgba(0, 0, 0, 0); }");
   


}

void clientwidget::on_view_btn_clicked()
{
    
}

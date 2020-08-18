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
    picIcon();
}

void clientwidget::picIcon() {
    QPixmap pixmap("/home/huihao/Desktop/myDB/Appointment_System/test/Login/icon.png");
    ui->Picture_label->setPixmap(pixmap);
    //ui->Picture_label->setMask(pixmap.mask());
    ui->Picture_label->setScaledContents( true );
    ui->Picture_label->show();
    ui->name_label->setText("Jacky Chen");
    ui->name_label->setStyleSheet("font-weight: bold");
    ui->phone_label->setText("415-888-8888");
    ui->address_label->setText("412 Hight Ave, \nSan Francisco, CA, 94112");
    ui->address_label->setWordWrap(true);
    //ui->view_btn->setStyleSheet("QPushButton { background-color: rgba(0, 0, 0, 0); }");
   


}

void clientwidget::on_view_btn_clicked()
{
    edit = new editclient(this);
    //QString name = stringlist.join("");
    //edit->setid();
    edit->show();
}

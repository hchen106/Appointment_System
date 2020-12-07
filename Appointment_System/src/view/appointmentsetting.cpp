#include "src/view/UI.h"
#include "ui_appointmentsetting.h"
#include "src/controller/controller.h"
#include "QMessageBox"
static const QString path = "/home/huihao/Desktop/myDB/Appointment_System/Appointment_System/src/controller/provider.db";

appointmentsetting::appointmentsetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::appointmentsetting)
{
    ui->setupUi(this);
}

appointmentsetting::~appointmentsetting()
{
    delete ui;
}
/*
void appointmentsetting::showEvent(QShowEvent *ev) {
    QDialog::showEvent(ev);
    
}
*/
void appointmentsetting::createController(Controller::addAppointmentSettingController *controller) {
    appointmentSettingController = controller;
}


#include "src/view/UI.h"
#include "ui_appointmentsetting.h"
#include "src/controller/DbManager.h"
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

void appointmentsetting::showEvent(QShowEvent *ev) {
    QDialog::showEvent(ev);
    getCurrentSetting();

}

void appointmentsetting::getCurrentSetting() {
    DbManager db(path);
    QString timeinfo = db.getTime(getLoginID());
    QStringList list = timeinfo.split("+");
    int open_hour = list[0].toInt();
    int open_min = list[1].toInt();
    int close_hour = list[2].toInt();
    int close_min = list[3].toInt();

    QTime open_time(open_hour, open_min);
    QTime close_time(close_hour, close_min);
    ui->open_time_entry->setTime(open_time);
    ui->close_time_entry->setTime(close_time);
    ui->gap_time_entry->setText(list[4]);

}

void appointmentsetting::on_apply_btn_clicked()
{
    DbManager db(path);
    int open_hour = ui->open_time_entry->time().hour();
    int open_min = ui->open_time_entry->time().minute();
    int close_hour = ui->close_time_entry->time().hour();
    int close_min = ui->close_time_entry->time().minute();
    QString gap_time = ui->gap_time_entry->text();
    if(db.updateTimeSetting(getLoginID(), open_hour, open_min, close_hour, close_min, gap_time)) {
        QMessageBox::information(this, "time setting", "Setting is Successfully updated");
    }else{
        QMessageBox::warning(this, "time setting", " Setting is fail to update");
    }
}

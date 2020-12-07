#include "src/view/UI.h"
#include "ui_timeslot.h"
//#include "src/controller/DbManager.h"
#include <QDebug>
#include <vector>
#include <QMessageBox>
using namespace std;

static const QString path = "/home/huihao/Desktop/myDB/Appointment_System/Appointment_System/src/controller/provider.db";

timeslot::timeslot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::timeslot)
    
{
ui->setupUi(this);
}
    
    

timeslot::~timeslot()
{
    delete ui;
}


void timeslot::showEvent(QShowEvent *ev) {
    QDialog::showEvent(ev);
    generateLabel();
    //qDebug() << "event";
}

void timeslot::createController(Controller::TimeslotController *controller) {
    timeslotController = controller;
}

void timeslot::initialize(QString date) {
    QString timeinfo = timeslotController->getTime();
    this->setTimeinfo(timeinfo);
    this->setDate(date);
    std::cout << date.toStdString()  << std::endl;
    generateLabel();
    this->exec();
}

void timeslot::generateLabel() {
    QVector<QLabel*> labels;
    vector<int> hours;
    vector<int> mins;
    
    //DbManager db(path);
    QString timeinfo = getTimeinfo();
    QStringList list = timeinfo.split("+");
    int open_hour = list[0].toInt();
    int open_min = list[1].toInt();
    int close_hour = list[2].toInt();
    int close_min = list[3].toInt();
    int gap_time = list[4].toInt();
    
    if(open_hour > close_hour) {
        int tmp_hour = open_hour;
        int tmp_min = open_min;
        open_hour = close_hour;
        open_min = close_min;
        close_hour = tmp_hour;
        close_min = tmp_min;
    }
    int total_min = ((close_hour - open_hour) * 60) + (close_min - open_min);
    qDebug() << getDate();
    for(int hour = open_hour, min = open_min, row = 0, col = 0, i = 0, checkmin = 0; checkmin <= total_min; checkmin = checkmin + gap_time, min = min + gap_time, row++, i++) {
        if(min >= 60) {
            min = abs(60 - min);
            hour++;
        }
        if(row >= 5) {
            col++;
            row = 0;
        }
        QString str = "";
        if(min == 0) {
            str = QString::number(hour) + ":00";
        }else if(min < 10) {
            str = QString::number(hour) + ":0" + QString::number(min);
        }else{
            str = QString::number(hour) + ":" + QString::number(min);
        }
        
        
    
        labels.append(new QLabel(str));
        
        if(timeslotController->checkBooking(getDate(),hour,min)) {
            labels[i]->setStyleSheet("QLabel { background-color : red; color : black; }");
        }else{
            labels[i]->setStyleSheet("QLabel { background-color : green; color : black; }");
            ui->book_time_entry->addItem(str);
        }   
        
        ui->gridLayout->addWidget(labels[i], col, row ,0);
        
        //qDebug() << hour;
    }
    
    for(int i = 0; i<labels.size(); i++){
        labels[i]->setAlignment(Qt::AlignCenter);
    }
   
    qDebug() << "label";


}

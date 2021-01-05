#include "src/view/UI.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <QSqlQuery>
#include <string>
#include <QSqlQueryModel>
#include <iostream>
#include <QDebug>

#include "src/controller/controller.h"

static const QString path = "/home/huihao/Desktop/master/Appointment_System/Appointment_System/src/controller/provider.db";

MainWindowUI::MainWindowUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowUI)
{
    ui->setupUi(this);
    // ui->listView->verticalHeader()->hide();
    // ui->listView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // ui->listView->horizontalHeader()->setStretchLastSection(true);
    // ui->listView->selectRow(0);
    // ui->listView->setSelectionMode(QAbstractItemView::SingleSelection);
}

MainWindowUI::~MainWindowUI()
{
    delete ui;
}

void MainWindowUI::closeEvent(QCloseEvent *event) {
    if(this->mainController != NULL) {
        this->mainController->closeConnection();
        event->accept();
    }
}

void MainWindowUI::createController(Controller::MainWindowUIController *controller) {
    mainController = controller;
    
    std::vector<Json::Value> json_vec = mainController->load();

    


    /*
    QStandardItemModel *model;
    */
    //QVector<QWidget*> widgets;
   
     for(int i = 0,row = 0, col = 0; i < json_vec.size() ; i++,row++) {
         if(row >= 3) {
              col++;
              row = 0;
          }
        
         clientwidget *client = new clientwidget();
         client->picIcon(json_vec[i]);
         widgets.append(client);
         //widgets[i]->setStyleSheet("border: 2 solid black;");
         ui->gridLayout->addWidget(client, col, row, 0);
     }
    
    
    //ui->listView->setModel(model);
}

void MainWindowUI::on_add_btn_clicked()
{
    addClientUI *addclient = new addClientUI(this);
    QString id = getLoginID();
    Controller::addClientController *addController = mainController->createAddClientController();
    addclient->createController(addController);
    addclient->setLoginID(id);
    addclient->show();
}

void MainWindowUI::on_setting_btn_clicked()
{
    
    appointmentsetting *setting = new appointmentsetting(this);
    QString id = getLoginID();
    Controller::addAppointmentSettingController *addController = mainController->createAddAppointmentSetttingController();
    setting->createController(addController);
    setting->setLoginID(id);
    setting->show();
    
}

void MainWindowUI::on_refresh_btn_clicked()
{
    std::vector<Json::Value> json_vec = mainController->load();

    //clientwidget *client = widgets[0];
    std::cout << widgets.size() << std::endl;
    int i = widgets.size()-1;
    
    
    while(widgets.size() > 0) {
        ui->gridLayout->removeWidget(widgets[i]);
        delete widgets[i];
        widgets.remove(i);
        i--;
        
    }
    

    std::cout << widgets.size() << std::endl;

   
   //sleep(1);
    for(int i = 0,row = 0, col = 0; i < json_vec.size() ; i++,row++) {
        if(row >= 3) {
            col++;
            row = 0;
        }
    
        clientwidget *client = new clientwidget();
        client->picIcon(json_vec[i]);
        widgets.append(client);
        //widgets[i]->setStyleSheet("border: 2 solid black;");
        ui->gridLayout->addWidget(client, col, row, 0);
        
    }
    std::cout << widgets.size() << std::endl;
    
}

void MainWindowUI::on_listView_clicked(const QModelIndex &index)
{
    
    
}

void MainWindowUI::on_calendarWidget_clicked(const QDate &date)
{
    std::cout << "calender" << std::endl;
    // qDebug() << ui->calendarWidget->selectedDate().toString("MM/dd/yyyy");
    // DbManager db(path);
    // QString loginID = getLoginID();
    // QString timeinfo = db.getTime(loginID);
    timeslot *slot = new timeslot(this);
    QString id = getLoginID();
    Controller::TimeslotController *timeslotController = mainController->createTimeslotController();
    slot->createController(timeslotController);
    slot->initialize(ui->calendarWidget->selectedDate().toString("MM/dd/yyyy"));
    //slot->exec();
    // //to-do getTime()
    
    // slot->setTimeinfo(timeinfo);
    //slot->setDate();
    // slot->exec();
}

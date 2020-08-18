#include "src/view/UI.h"
#include "ui_mainwindow.h"
#include "src/controller/DbManager.h"
#include <algorithm>
#include <QSqlQuery>
#include <string>
#include <QSqlQueryModel>
#include <iostream>
#include <QDebug>


static const QString path = "/home/huihao/Desktop/myDB/Appointment_System/Appointment_System/src/controller/provider.db";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*ui->listView->verticalHeader()->hide();
    ui->listView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->listView->horizontalHeader()->setStretchLastSection(true);
    ui->listView->selectRow(0);
    ui->listView->setSelectionMode(QAbstractItemView::SingleSelection);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_btn_clicked()
{
    addclient = new addClient(this);
    QString id = getLoginID();
    addclient->setLoginID(id);
    addclient->show();
}

void MainWindow::on_refresh_btn_clicked()
{
    /*DbManager db(path);
    QSqlQuery qry;
    QString loginID = getLoginID();
    qDebug() << loginID;
    qry = db.getClientList(loginID);
    QSqlQueryModel * modal = new QSqlQueryModel();
    modal->setQuery(qry);
    ui->listView->setModel(modal);*/
    QVector<QWidget*> widgets;
    for(int i = 0, row = 0, col = 0; i < 8; i++, row++) {
         if(row >= 3) {
             col++;
             row = 0;
         }
         //
        widgets.append(new clientwidget());
        //widgets[i]->setStyleSheet("border: 2 solid black;");
        ui->gridLayout->addWidget(widgets[i], col, row, 0);

    }
       
    
}

/*void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    
    QModelIndex temp_list = ui->listView->selectionModel()->selectedRows(0).at(0);
    
    QStringList stringlist;
    //foreach(const QModelIndex &index, temp_list) {
    //    stringlist.append(index.data(Qt::DisplayRole).toString());
    //} 
    stringlist.append(temp_list.data(Qt::DisplayRole).toString());
    qDebug() << stringlist.join("");
    edit = new editclient(this);
    QString name = stringlist.join("");
    edit->setName(name);
    edit->show();
}*/

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    
    qDebug() << ui->calendarWidget->selectedDate().toString("MM/dd/yyyy");
    DbManager db(path);
    QString loginID = getLoginID();
    QString timeinfo = db.getTime(loginID);
    slot = new timeslot(this);
    //to-do getTime()
    slot->setTimeinfo(timeinfo);
    slot->setDate(ui->calendarWidget->selectedDate().toString("MM/dd/yyyy"));
    slot->exec();
}


void MainWindow::on_setting_btn_clicked()
{
    setting = new appointmentsetting(this);
    setting->setLoginID(getLoginID());
    setting->exec();
}

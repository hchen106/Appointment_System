#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addclient.h"
#include "editclient.h"
#include "DbManager.h"
#include <algorithm>
#include <QSqlQuery>
#include <string>
#include <QSqlQueryModel>
#include <iostream>
#include <QDebug>

static const QString path = "/home/huihao/Desktop/myDB/Appointment_System/test/Login/provider.db";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    DbManager db(path);
    QSqlQuery qry;
    QString loginID = getLoginID();
    qDebug() << loginID;
    qry = db.getClientList(loginID);
    QSqlQueryModel * modal = new QSqlQueryModel();
    modal->setQuery(qry);
    ui->listView->setModel(modal);
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    
    QModelIndexList temp_list = ui->listView->selectionModel()->selectedIndexes();
    QStringList stringlist;
    foreach(const QModelIndex &index, temp_list) {
        stringlist.append(index.data(Qt::DisplayRole).toString());
    } 
    qDebug() << stringlist.join("");
    edit = new editclient(this);
    QString name = stringlist.join("");
    edit->setName(name);
    edit->show();
}

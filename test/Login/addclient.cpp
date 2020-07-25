#include "addclient.h"
#include "ui_addclient.h"
#include "DbManager.h"
#include <QMessageBox>
#include <QDebug>
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


#include "view/UI.h"
#include "ui_mainwindow.h"
//#include "src/view/mainwindow.h"

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

void MainWindow::on_logout_btn_clicked()
{

}

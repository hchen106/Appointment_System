#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addclient.h"
#include "DbManager.h"
#include <QSqlQuery>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     explicit MainWindow(QWidget *parent = nullptr);
    
    ~MainWindow();
    void setLoginID(QString& loginID) {
        id = loginID;
    }
    
    QString getLoginID() {
        return id;
    }

private slots:
    void on_add_btn_clicked();
    
    void on_refresh_btn_clicked();

private:
    Ui::MainWindow *ui;
    addClient *addclient;
    QString id;
};

#endif // MAINWINDOW_H

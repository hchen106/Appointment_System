#ifndef UI_H
#define UI_H

#include <QMainWindow>

#include <iostream>
#include "src/controller/LoginUIController.h"
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class Login_UI; class Signup; class MainWindow; class editclient; class addClient;}
QT_END_NAMESPACE


class Signup : public QMainWindow
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();

private slots:

    void on_signup_btn_clicked();

private:
    Ui::Signup *ui;
};


class editclient : public QMainWindow
{
    Q_OBJECT

public:
    explicit editclient(QWidget *parent = nullptr);
    ~editclient();
    
    QString getName() {
        return name;
    }

    void setName(QString& selected_name) { 
        name = selected_name;
    }

    QString getid(){
        return id;
    }

    void setid(QString& clientID) {
        id = clientID;
    }
    
private slots:
    void on_update_btn_clicked();

    void on_load_btn_clicked();

private:
    Ui::editclient *ui;
    QString name;
    QString id;
};

class addClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit addClient(QWidget *parent = nullptr);
    ~addClient();

    void setLoginID(QString& loginid) {
        id = loginid;
    }
    QString getLoginID() {
        return id;
    }

private slots:
    void on_add_btn_clicked();

private:
    Ui::addClient *ui;
    QString id;
};



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
    
    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    addClient *addclient;
    editclient *edit;
    QString id;
};


class Login_UI : public QMainWindow
{
    Q_OBJECT

public:
    Login_UI(QWidget *parent = nullptr);
    ~Login_UI();

private slots:
    void on_signup_btn_clicked();

    void on_login_btn_clicked();

private:
    Ui::Login_UI *ui;
    Signup *signup;
    MainWindow *mainwindow;

};
#endif // UI_H

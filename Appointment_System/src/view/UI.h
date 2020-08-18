#ifndef UI_H
#define UI_H

#include <QMainWindow>

#include <iostream>
#include "src/controller/LoginUIController.h"
#include <string>
#include <QLabel>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Login_UI; class Signup; class MainWindow; class editclient; class addClient; class appointmentsetting; class clientwidget; class timeslot;}
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


class appointmentsetting : public QDialog
{
    Q_OBJECT

protected:
      void showEvent(QShowEvent *ev);

public:
    explicit appointmentsetting(QWidget *parent = nullptr);
    ~appointmentsetting();
    void getCurrentSetting();
    void setLoginID(QString loginID) {
        id = loginID;
    }
    QString getLoginID() {
        return id;
    }
private slots:
    void on_apply_btn_clicked();

private:
    Ui::appointmentsetting *ui;
    QString id;
};


class clientwidget : public QWidget
{
    Q_OBJECT

protected:
      void showEvent(QShowEvent *ev);

public:
    explicit clientwidget(QWidget *parent = nullptr);
    ~clientwidget();
    void picIcon();
    void setInfo(QString names, QString phones, QString addresses) {
        name = names;
        phone = phones;
        address = addresses;

    }

    QString getName() {
        return name;
    }

    QString getPhone() {
        return phone;
    }

    QString getAddress() {
        return address;
    }
    
private slots:
    void on_view_btn_clicked();

private:
    Ui::clientwidget *ui;
    QString name;
    QString phone;
    QString address;
    editclient *edit;
};


class timeslot : public QDialog
{
    Q_OBJECT

protected:
      void showEvent(QShowEvent *ev);

public:
    explicit timeslot(QWidget *parent = nullptr);
    ~timeslot();
    void setTimeinfo(QString& time) {
        timeinfo = time;
    }
    
    QString getTimeinfo() {
        return timeinfo;
    }

    void setDate(QString setdate) {
        date = setdate;
    }

    QString getDate() {
        return date;
    }

   


private slots:
    void on_book_btn_clicked();

private:
    Ui::timeslot *ui;
    QString date;
    QString timeinfo;
    void generateLabel();
    QVector<QLabel*> labels;
    
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
    
    //void on_listView_clicked(const QModelIndex &index);

    void on_calendarWidget_clicked(const QDate &date);

    void on_setting_btn_clicked();

private:
    Ui::MainWindow *ui;
    addClient *addclient;
    editclient *edit;
    timeslot *slot;
    appointmentsetting *setting;
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

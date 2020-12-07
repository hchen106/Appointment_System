#ifndef UI_H
#define UI_H

#include <QMainWindow>

#include <iostream>
#include "src/controller/controller.h"
#include <string>
#include <QCloseEvent>
#include <vector>
#include "json/json.h"
#include <QStandardItem>
#include <QString>
#include <QStandardItemModel>
#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class LoginUI; class addClientUI; class MainWindowUI; class clientwidget; class MainSignup; class appointmentsetting; class timeslot;}
QT_END_NAMESPACE

class LoginUI : public QMainWindow
{
    Q_OBJECT

    public:
        LoginUI(QWidget *parent = nullptr);
        ~LoginUI();
        void closeEvent(QCloseEvent*);

    private slots:

        void on_login_btn_clicked();

        void on_signup_btn_clicked();

    private:
        std::string IP;
        int PORT;
        Ui::LoginUI *ui;
        //Ui::MainSignup *mainsignup;
        Controller::LoginUIController *controller;
        std::string get_text(QString);
    
};

class MainWindowUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowUI(QWidget *parent = nullptr);
    
    ~MainWindowUI();
    void setLoginID(QString& loginID) {
        id = loginID;
    }
    
    QString getLoginID() {
        return id;
    }

    void closeEvent(QCloseEvent*);

    void createController(Controller::MainWindowUIController*);

    

private slots:
    void on_calendarWidget_clicked(const QDate &date);

    void on_add_btn_clicked();
    
    void on_refresh_btn_clicked();

    void on_setting_btn_clicked();
    
    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::MainWindowUI *ui;
    Controller::MainWindowUIController *mainController;
    QVector<QWidget*> widgets;
    //Ui::addClientUI *addclient;
    //editclient *edit;
    
    QString id;
};

class addClientUI : public QMainWindow
{
    Q_OBJECT

    public:
        explicit addClientUI(QWidget *parent = nullptr);
        ~addClientUI();

        void setLoginID(QString& loginid) {
            id = loginid;
        }
        QString getLoginID() {
            return id;
        }

        void createController(Controller::addClientController*);
        

    private slots:
        void on_add_btn_clicked();

    private:
        Ui::addClientUI *ui;
        Controller::addClientController *addClientController;
        QString id;
};

class appointmentsetting : public QDialog
{
    Q_OBJECT



public:
    explicit appointmentsetting(QWidget *parent = nullptr);
    ~appointmentsetting();
    void createController(Controller::addAppointmentSettingController*);

    void getCurrentSetting();
    void setLoginID(QString loginID) {
        id = loginID;
    }
    QString getLoginID() {
        return id;
    }
private slots:
    //void on_apply_btn_clicked();

private:
    Ui::appointmentsetting *ui;
    Controller::addAppointmentSettingController *appointmentSettingController;
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
    void picIcon(Json::Value);
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
    //editclient *edit;
};



class MainSignup : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainSignup(QWidget *parent = nullptr);
    ~MainSignup();

private slots:

    void on_signup_btn_clicked();

private:
    Ui::MainSignup *ui;
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

    void initialize(QString setdate);

    void createController(Controller::TimeslotController *controller);

   

private:
    Ui::timeslot *ui;
    QString date;
    QString timeinfo;
    void generateLabel();
    Controller::TimeslotController *timeslotController;
    
    
};



#endif // UI_H

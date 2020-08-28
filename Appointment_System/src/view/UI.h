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


QT_BEGIN_NAMESPACE
namespace Ui { class LoginUI; class addClientUI; class MainWindowUI; class clientwidget; }
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

    private:
        std::string IP;
        int PORT;
        Ui::LoginUI *ui;
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
    void on_add_btn_clicked();
    
    void on_refresh_btn_clicked();
    
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



#endif // UI_H

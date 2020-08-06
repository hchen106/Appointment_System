#ifndef EDITCLIENT_H
#define EDITCLIENT_H

#include <QMainWindow>

namespace Ui {
class editclient;
}

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

#endif // EDITCLIENT_H

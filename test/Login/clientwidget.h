#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include "editclient.h"

namespace Ui {
class clientwidget;
}

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

#endif // CLIENTWIDGET_H

#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class addClient;
}

class addClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit addClient(QWidget *parent = nullptr);
    ~addClient();


private:
    Ui::addClient *ui;
};

#endif // ADDCLIENT_H

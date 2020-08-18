#ifndef APPOINTMENTSETTING_H
#define APPOINTMENTSETTING_H

#include <QDialog>

namespace Ui {
class appointmentsetting;
}

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

#endif // APPOINTMENTSETTING_H

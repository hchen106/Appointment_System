#ifndef TIMESLOT_H
#define TIMESLOT_H
#include <QDialog>
#include <QDate>
#include <QLabel>
namespace Ui {
class timeslot;
}

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

#endif // TIMESLOT_H

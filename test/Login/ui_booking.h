/********************************************************************************
** Form generated from reading UI file 'booking.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKING_H
#define UI_BOOKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_booking
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *name_label;
    QLineEdit *phone_entry;
    QLineEdit *name_entry;
    QLineEdit *email_entry;
    QLabel *email_label;
    QLabel *phone_label;
    QLabel *book_label;
    QComboBox *book_time_entry;
    QPushButton *book_btn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *booking)
    {
        if (booking->objectName().isEmpty())
            booking->setObjectName(QString::fromUtf8("booking"));
        booking->resize(378, 191);
        centralwidget = new QWidget(booking);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        name_label = new QLabel(centralwidget);
        name_label->setObjectName(QString::fromUtf8("name_label"));

        gridLayout->addWidget(name_label, 0, 0, 1, 1);

        phone_entry = new QLineEdit(centralwidget);
        phone_entry->setObjectName(QString::fromUtf8("phone_entry"));

        gridLayout->addWidget(phone_entry, 1, 1, 1, 1);

        name_entry = new QLineEdit(centralwidget);
        name_entry->setObjectName(QString::fromUtf8("name_entry"));

        gridLayout->addWidget(name_entry, 0, 1, 1, 1);

        email_entry = new QLineEdit(centralwidget);
        email_entry->setObjectName(QString::fromUtf8("email_entry"));

        gridLayout->addWidget(email_entry, 2, 1, 1, 1);

        email_label = new QLabel(centralwidget);
        email_label->setObjectName(QString::fromUtf8("email_label"));

        gridLayout->addWidget(email_label, 2, 0, 1, 1);

        phone_label = new QLabel(centralwidget);
        phone_label->setObjectName(QString::fromUtf8("phone_label"));

        gridLayout->addWidget(phone_label, 1, 0, 1, 1);

        book_label = new QLabel(centralwidget);
        book_label->setObjectName(QString::fromUtf8("book_label"));

        gridLayout->addWidget(book_label, 3, 0, 1, 1);

        book_time_entry = new QComboBox(centralwidget);
        book_time_entry->setObjectName(QString::fromUtf8("book_time_entry"));

        gridLayout->addWidget(book_time_entry, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        book_btn = new QPushButton(centralwidget);
        book_btn->setObjectName(QString::fromUtf8("book_btn"));

        verticalLayout->addWidget(book_btn);

        booking->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(booking);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        booking->setStatusBar(statusbar);

        retranslateUi(booking);

        QMetaObject::connectSlotsByName(booking);
    } // setupUi

    void retranslateUi(QMainWindow *booking)
    {
        booking->setWindowTitle(QApplication::translate("booking", "MainWindow", nullptr));
        name_label->setText(QApplication::translate("booking", "Name", nullptr));
        email_label->setText(QApplication::translate("booking", "Email", nullptr));
        phone_label->setText(QApplication::translate("booking", "Phone", nullptr));
        book_label->setText(QApplication::translate("booking", "Book Time", nullptr));
        book_btn->setText(QApplication::translate("booking", "Book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class booking: public Ui_booking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKING_H

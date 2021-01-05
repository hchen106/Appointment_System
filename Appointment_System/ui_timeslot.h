/********************************************************************************
** Form generated from reading UI file 'timeslot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMESLOT_H
#define UI_TIMESLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_timeslot
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLineEdit *phone_entry;
    QLineEdit *name_entry;
    QLabel *phone_label;
    QLabel *name_label;
    QComboBox *book_time_entry;
    QLabel *book_label;
    QLineEdit *email_entry;
    QLabel *email_label;
    QPushButton *book_btn;

    void setupUi(QDialog *timeslot)
    {
        if (timeslot->objectName().isEmpty())
            timeslot->setObjectName(QString::fromUtf8("timeslot"));
        timeslot->resize(714, 387);
        gridLayout_3 = new QGridLayout(timeslot);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        phone_entry = new QLineEdit(timeslot);
        phone_entry->setObjectName(QString::fromUtf8("phone_entry"));

        gridLayout_2->addWidget(phone_entry, 1, 1, 1, 1);

        name_entry = new QLineEdit(timeslot);
        name_entry->setObjectName(QString::fromUtf8("name_entry"));

        gridLayout_2->addWidget(name_entry, 0, 1, 1, 1);

        phone_label = new QLabel(timeslot);
        phone_label->setObjectName(QString::fromUtf8("phone_label"));

        gridLayout_2->addWidget(phone_label, 1, 0, 1, 1);

        name_label = new QLabel(timeslot);
        name_label->setObjectName(QString::fromUtf8("name_label"));

        gridLayout_2->addWidget(name_label, 0, 0, 1, 1);

        book_time_entry = new QComboBox(timeslot);
        book_time_entry->setObjectName(QString::fromUtf8("book_time_entry"));

        gridLayout_2->addWidget(book_time_entry, 3, 1, 1, 1);

        book_label = new QLabel(timeslot);
        book_label->setObjectName(QString::fromUtf8("book_label"));

        gridLayout_2->addWidget(book_label, 3, 0, 1, 1);

        email_entry = new QLineEdit(timeslot);
        email_entry->setObjectName(QString::fromUtf8("email_entry"));

        gridLayout_2->addWidget(email_entry, 2, 1, 1, 1);

        email_label = new QLabel(timeslot);
        email_label->setObjectName(QString::fromUtf8("email_label"));

        gridLayout_2->addWidget(email_label, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        book_btn = new QPushButton(timeslot);
        book_btn->setObjectName(QString::fromUtf8("book_btn"));

        verticalLayout->addWidget(book_btn);


        gridLayout_3->addLayout(verticalLayout, 0, 1, 1, 1);

        QWidget::setTabOrder(name_entry, phone_entry);
        QWidget::setTabOrder(phone_entry, email_entry);
        QWidget::setTabOrder(email_entry, book_time_entry);
        QWidget::setTabOrder(book_time_entry, book_btn);

        retranslateUi(timeslot);

        QMetaObject::connectSlotsByName(timeslot);
    } // setupUi

    void retranslateUi(QDialog *timeslot)
    {
        timeslot->setWindowTitle(QCoreApplication::translate("timeslot", "Dialog", nullptr));
        phone_label->setText(QCoreApplication::translate("timeslot", "Phone", nullptr));
        name_label->setText(QCoreApplication::translate("timeslot", "Name", nullptr));
        book_label->setText(QCoreApplication::translate("timeslot", "Book Time", nullptr));
        email_label->setText(QCoreApplication::translate("timeslot", "Email", nullptr));
        book_btn->setText(QCoreApplication::translate("timeslot", "Book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class timeslot: public Ui_timeslot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMESLOT_H

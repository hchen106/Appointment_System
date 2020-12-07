/********************************************************************************
** Form generated from reading UI file 'addclient.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCLIENT_H
#define UI_ADDCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addClientUI
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLabel *phone_label;
    QLabel *name_label;
    QLineEdit *add_email_entry;
    QLabel *email_label;
    QLineEdit *add_name_entry;
    QLineEdit *add_phone_entry;
    QGridLayout *gridLayout_2;
    QLabel *birthday_label;
    QLineEdit *add_birthday_entry;
    QLabel *provider_label;
    QLineEdit *provider_entry;
    QGridLayout *gridLayout_3;
    QLabel *address_label;
    QLineEdit *add_address_entry;
    QPushButton *add_btn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *addClientUI)
    {
        if (addClientUI->objectName().isEmpty())
            addClientUI->setObjectName(QString::fromUtf8("addClientUI"));
        addClientUI->resize(746, 477);
        centralwidget = new QWidget(addClientUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        phone_label = new QLabel(centralwidget);
        phone_label->setObjectName(QString::fromUtf8("phone_label"));

        gridLayout->addWidget(phone_label, 2, 0, 1, 1);

        name_label = new QLabel(centralwidget);
        name_label->setObjectName(QString::fromUtf8("name_label"));

        gridLayout->addWidget(name_label, 0, 0, 1, 1);

        add_email_entry = new QLineEdit(centralwidget);
        add_email_entry->setObjectName(QString::fromUtf8("add_email_entry"));

        gridLayout->addWidget(add_email_entry, 1, 1, 1, 1);

        email_label = new QLabel(centralwidget);
        email_label->setObjectName(QString::fromUtf8("email_label"));

        gridLayout->addWidget(email_label, 1, 0, 1, 1);

        add_name_entry = new QLineEdit(centralwidget);
        add_name_entry->setObjectName(QString::fromUtf8("add_name_entry"));

        gridLayout->addWidget(add_name_entry, 0, 1, 1, 1);

        add_phone_entry = new QLineEdit(centralwidget);
        add_phone_entry->setObjectName(QString::fromUtf8("add_phone_entry"));

        gridLayout->addWidget(add_phone_entry, 2, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        birthday_label = new QLabel(centralwidget);
        birthday_label->setObjectName(QString::fromUtf8("birthday_label"));

        gridLayout_2->addWidget(birthday_label, 0, 0, 1, 1);

        add_birthday_entry = new QLineEdit(centralwidget);
        add_birthday_entry->setObjectName(QString::fromUtf8("add_birthday_entry"));

        gridLayout_2->addWidget(add_birthday_entry, 0, 1, 1, 1);

        provider_label = new QLabel(centralwidget);
        provider_label->setObjectName(QString::fromUtf8("provider_label"));

        gridLayout_2->addWidget(provider_label, 1, 0, 1, 1);

        provider_entry = new QLineEdit(centralwidget);
        provider_entry->setObjectName(QString::fromUtf8("provider_entry"));

        gridLayout_2->addWidget(provider_entry, 1, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        address_label = new QLabel(centralwidget);
        address_label->setObjectName(QString::fromUtf8("address_label"));

        gridLayout_3->addWidget(address_label, 0, 0, 1, 1);

        add_address_entry = new QLineEdit(centralwidget);
        add_address_entry->setObjectName(QString::fromUtf8("add_address_entry"));

        gridLayout_3->addWidget(add_address_entry, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        add_btn = new QPushButton(centralwidget);
        add_btn->setObjectName(QString::fromUtf8("add_btn"));

        verticalLayout_2->addWidget(add_btn);

        addClientUI->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(addClientUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        addClientUI->setStatusBar(statusbar);
        QWidget::setTabOrder(add_name_entry, add_email_entry);
        QWidget::setTabOrder(add_email_entry, add_phone_entry);
        QWidget::setTabOrder(add_phone_entry, add_birthday_entry);
        QWidget::setTabOrder(add_birthday_entry, provider_entry);
        QWidget::setTabOrder(provider_entry, add_address_entry);
        QWidget::setTabOrder(add_address_entry, add_btn);

        retranslateUi(addClientUI);

        QMetaObject::connectSlotsByName(addClientUI);
    } // setupUi

    void retranslateUi(QMainWindow *addClientUI)
    {
        addClientUI->setWindowTitle(QCoreApplication::translate("addClientUI", "MainWindow", nullptr));
        phone_label->setText(QCoreApplication::translate("addClientUI", "Phone", nullptr));
        name_label->setText(QCoreApplication::translate("addClientUI", "Name", nullptr));
        email_label->setText(QCoreApplication::translate("addClientUI", "Email", nullptr));
        birthday_label->setText(QCoreApplication::translate("addClientUI", "Birthday", nullptr));
        provider_label->setText(QCoreApplication::translate("addClientUI", "Provider", nullptr));
        address_label->setText(QCoreApplication::translate("addClientUI", "Address", nullptr));
        add_btn->setText(QCoreApplication::translate("addClientUI", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addClientUI: public Ui_addClientUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCLIENT_H

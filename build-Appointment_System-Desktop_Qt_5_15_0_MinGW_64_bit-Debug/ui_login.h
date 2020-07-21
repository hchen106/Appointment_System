/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

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

class Ui_Login
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *password_lable;
    QLabel *id_label;
    QLineEdit *id_entry;
    QLineEdit *password_entry;
    QHBoxLayout *horizontalLayout;
    QPushButton *signup_btn;
    QPushButton *login_btn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(314, 122);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        password_lable = new QLabel(centralwidget);
        password_lable->setObjectName(QString::fromUtf8("password_lable"));

        gridLayout->addWidget(password_lable, 1, 0, 1, 1);

        id_label = new QLabel(centralwidget);
        id_label->setObjectName(QString::fromUtf8("id_label"));

        gridLayout->addWidget(id_label, 0, 0, 1, 1);

        id_entry = new QLineEdit(centralwidget);
        id_entry->setObjectName(QString::fromUtf8("id_entry"));

        gridLayout->addWidget(id_entry, 0, 1, 1, 1);

        password_entry = new QLineEdit(centralwidget);
        password_entry->setObjectName(QString::fromUtf8("password_entry"));

        gridLayout->addWidget(password_entry, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        signup_btn = new QPushButton(centralwidget);
        signup_btn->setObjectName(QString::fromUtf8("signup_btn"));

        horizontalLayout->addWidget(signup_btn);

        login_btn = new QPushButton(centralwidget);
        login_btn->setObjectName(QString::fromUtf8("login_btn"));

        horizontalLayout->addWidget(login_btn);


        verticalLayout->addLayout(horizontalLayout);

        Login->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        password_lable->setText(QCoreApplication::translate("Login", "Password", nullptr));
        id_label->setText(QCoreApplication::translate("Login", "ID", nullptr));
        signup_btn->setText(QCoreApplication::translate("Login", "Sign Up", nullptr));
        login_btn->setText(QCoreApplication::translate("Login", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

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

class Ui_LoginUI
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

    void setupUi(QMainWindow *LoginUI)
    {
        if (LoginUI->objectName().isEmpty())
            LoginUI->setObjectName(QString::fromUtf8("LoginUI"));
        LoginUI->resize(314, 122);
        centralwidget = new QWidget(LoginUI);
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

        LoginUI->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LoginUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginUI->setStatusBar(statusbar);

        retranslateUi(LoginUI);

        QMetaObject::connectSlotsByName(LoginUI);
    } // setupUi

    void retranslateUi(QMainWindow *LoginUI)
    {
        LoginUI->setWindowTitle(QCoreApplication::translate("LoginUI", "Login", nullptr));
        password_lable->setText(QCoreApplication::translate("LoginUI", "Password", nullptr));
        id_label->setText(QCoreApplication::translate("LoginUI", "ID", nullptr));
        signup_btn->setText(QCoreApplication::translate("LoginUI", "Sign Up", nullptr));
        login_btn->setText(QCoreApplication::translate("LoginUI", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginUI: public Ui_LoginUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

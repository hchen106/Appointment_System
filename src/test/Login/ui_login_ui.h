/********************************************************************************
** Form generated from reading UI file 'login_ui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_UI_H
#define UI_LOGIN_UI_H

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

class Ui_Login_UI
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *id_label;
    QLabel *password_label;
    QLineEdit *id_entry;
    QLineEdit *password_entry;
    QHBoxLayout *horizontalLayout;
    QPushButton *signup_btn;
    QPushButton *login_btn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login_UI)
    {
        if (Login_UI->objectName().isEmpty())
            Login_UI->setObjectName(QString::fromUtf8("Login_UI"));
        Login_UI->resize(331, 131);
        centralwidget = new QWidget(Login_UI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        id_label = new QLabel(centralwidget);
        id_label->setObjectName(QString::fromUtf8("id_label"));

        gridLayout->addWidget(id_label, 0, 0, 1, 1);

        password_label = new QLabel(centralwidget);
        password_label->setObjectName(QString::fromUtf8("password_label"));

        gridLayout->addWidget(password_label, 1, 0, 1, 1);

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

        Login_UI->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Login_UI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Login_UI->setStatusBar(statusbar);

        retranslateUi(Login_UI);

        QMetaObject::connectSlotsByName(Login_UI);
    } // setupUi

    void retranslateUi(QMainWindow *Login_UI)
    {
        Login_UI->setWindowTitle(QApplication::translate("Login_UI", "Login_UI", nullptr));
        id_label->setText(QApplication::translate("Login_UI", "ID", nullptr));
        password_label->setText(QApplication::translate("Login_UI", "Password", nullptr));
        signup_btn->setText(QApplication::translate("Login_UI", "Sign Up", nullptr));
        login_btn->setText(QApplication::translate("Login_UI", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login_UI: public Ui_Login_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_UI_H

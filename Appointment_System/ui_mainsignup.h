/********************************************************************************
** Form generated from reading UI file 'mainsignup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSIGNUP_H
#define UI_MAINSIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainSignup
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *signup_password_label;
    QLabel *signup_name_label;
    QLabel *signup_loginID_label;
    QLineEdit *signup_loginID_entry;
    QLineEdit *signup_name_entry;
    QLineEdit *signup_password_entry;
    QHBoxLayout *horizontalLayout;
    QPushButton *signup_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainSignup)
    {
        if (MainSignup->objectName().isEmpty())
            MainSignup->setObjectName(QString::fromUtf8("MainSignup"));
        MainSignup->resize(434, 184);
        centralwidget = new QWidget(MainSignup);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        signup_password_label = new QLabel(centralwidget);
        signup_password_label->setObjectName(QString::fromUtf8("signup_password_label"));

        gridLayout->addWidget(signup_password_label, 2, 0, 1, 1);

        signup_name_label = new QLabel(centralwidget);
        signup_name_label->setObjectName(QString::fromUtf8("signup_name_label"));

        gridLayout->addWidget(signup_name_label, 0, 0, 1, 1);

        signup_loginID_label = new QLabel(centralwidget);
        signup_loginID_label->setObjectName(QString::fromUtf8("signup_loginID_label"));

        gridLayout->addWidget(signup_loginID_label, 1, 0, 1, 1);

        signup_loginID_entry = new QLineEdit(centralwidget);
        signup_loginID_entry->setObjectName(QString::fromUtf8("signup_loginID_entry"));

        gridLayout->addWidget(signup_loginID_entry, 1, 1, 1, 1);

        signup_name_entry = new QLineEdit(centralwidget);
        signup_name_entry->setObjectName(QString::fromUtf8("signup_name_entry"));

        gridLayout->addWidget(signup_name_entry, 0, 1, 1, 1);

        signup_password_entry = new QLineEdit(centralwidget);
        signup_password_entry->setObjectName(QString::fromUtf8("signup_password_entry"));

        gridLayout->addWidget(signup_password_entry, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        signup_btn = new QPushButton(centralwidget);
        signup_btn->setObjectName(QString::fromUtf8("signup_btn"));

        horizontalLayout->addWidget(signup_btn);


        verticalLayout->addLayout(horizontalLayout);

        MainSignup->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainSignup);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 434, 22));
        MainSignup->setMenuBar(menubar);
        statusbar = new QStatusBar(MainSignup);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainSignup->setStatusBar(statusbar);
        QWidget::setTabOrder(signup_name_entry, signup_loginID_entry);
        QWidget::setTabOrder(signup_loginID_entry, signup_password_entry);
        QWidget::setTabOrder(signup_password_entry, signup_btn);

        retranslateUi(MainSignup);

        QMetaObject::connectSlotsByName(MainSignup);
    } // setupUi

    void retranslateUi(QMainWindow *MainSignup)
    {
        MainSignup->setWindowTitle(QApplication::translate("MainSignup", "MainWindow", nullptr));
        signup_password_label->setText(QApplication::translate("MainSignup", "Password", nullptr));
        signup_name_label->setText(QApplication::translate("MainSignup", "Name", nullptr));
        signup_loginID_label->setText(QApplication::translate("MainSignup", "Login ID", nullptr));
        signup_btn->setText(QApplication::translate("MainSignup", "SignUp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainSignup: public Ui_MainSignup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSIGNUP_H

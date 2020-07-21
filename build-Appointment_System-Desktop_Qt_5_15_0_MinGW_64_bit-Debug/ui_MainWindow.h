/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *id_label;
    QLabel *password_label;
    QLineEdit *id_entry;
    QLineEdit *passwor_entry;
    QHBoxLayout *horizontalLayout;
    QPushButton *sign_up_btn;
    QPushButton *login_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(344, 143);
        centralwidget = new QWidget(MainWindow);
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

        passwor_entry = new QLineEdit(centralwidget);
        passwor_entry->setObjectName(QString::fromUtf8("passwor_entry"));

        gridLayout->addWidget(passwor_entry, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sign_up_btn = new QPushButton(centralwidget);
        sign_up_btn->setObjectName(QString::fromUtf8("sign_up_btn"));

        horizontalLayout->addWidget(sign_up_btn);

        login_btn = new QPushButton(centralwidget);
        login_btn->setObjectName(QString::fromUtf8("login_btn"));

        horizontalLayout->addWidget(login_btn);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 344, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        id_label->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        password_label->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        sign_up_btn->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        login_btn->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

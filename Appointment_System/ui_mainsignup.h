/********************************************************************************
** Form generated from reading UI file 'mainsignup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
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
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainSignup
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *signup_name_label;
    QLineEdit *signup_name_entry;
    QLabel *signup_password_label;
    QLabel *signup_loginID_label;
    QLineEdit *signup_password_entry;
    QLineEdit *signup_loginID_entry;
    QGridLayout *gridLayout_2;
    QTimeEdit *close_time_entry;
    QLabel *gap_time_label;
    QLabel *close_time_label;
    QLineEdit *gap_time_entry;
    QTimeEdit *open_time_entry;
    QLabel *open_time_label;
    QHBoxLayout *horizontalLayout;
    QPushButton *signup_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainSignup)
    {
        if (MainSignup->objectName().isEmpty())
            MainSignup->setObjectName(QString::fromUtf8("MainSignup"));
        MainSignup->resize(485, 184);
        centralwidget = new QWidget(MainSignup);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        signup_name_label = new QLabel(centralwidget);
        signup_name_label->setObjectName(QString::fromUtf8("signup_name_label"));

        gridLayout->addWidget(signup_name_label, 0, 0, 1, 1);

        signup_name_entry = new QLineEdit(centralwidget);
        signup_name_entry->setObjectName(QString::fromUtf8("signup_name_entry"));

        gridLayout->addWidget(signup_name_entry, 0, 1, 1, 1);

        signup_password_label = new QLabel(centralwidget);
        signup_password_label->setObjectName(QString::fromUtf8("signup_password_label"));

        gridLayout->addWidget(signup_password_label, 2, 0, 1, 1);

        signup_loginID_label = new QLabel(centralwidget);
        signup_loginID_label->setObjectName(QString::fromUtf8("signup_loginID_label"));

        gridLayout->addWidget(signup_loginID_label, 1, 0, 1, 1);

        signup_password_entry = new QLineEdit(centralwidget);
        signup_password_entry->setObjectName(QString::fromUtf8("signup_password_entry"));

        gridLayout->addWidget(signup_password_entry, 2, 1, 1, 1);

        signup_loginID_entry = new QLineEdit(centralwidget);
        signup_loginID_entry->setObjectName(QString::fromUtf8("signup_loginID_entry"));

        gridLayout->addWidget(signup_loginID_entry, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        close_time_entry = new QTimeEdit(centralwidget);
        close_time_entry->setObjectName(QString::fromUtf8("close_time_entry"));

        gridLayout_2->addWidget(close_time_entry, 1, 1, 1, 1);

        gap_time_label = new QLabel(centralwidget);
        gap_time_label->setObjectName(QString::fromUtf8("gap_time_label"));

        gridLayout_2->addWidget(gap_time_label, 2, 0, 1, 1);

        close_time_label = new QLabel(centralwidget);
        close_time_label->setObjectName(QString::fromUtf8("close_time_label"));

        gridLayout_2->addWidget(close_time_label, 1, 0, 1, 1);

        gap_time_entry = new QLineEdit(centralwidget);
        gap_time_entry->setObjectName(QString::fromUtf8("gap_time_entry"));

        gridLayout_2->addWidget(gap_time_entry, 2, 1, 1, 1);

        open_time_entry = new QTimeEdit(centralwidget);
        open_time_entry->setObjectName(QString::fromUtf8("open_time_entry"));

        gridLayout_2->addWidget(open_time_entry, 0, 1, 1, 1);

        open_time_label = new QLabel(centralwidget);
        open_time_label->setObjectName(QString::fromUtf8("open_time_label"));

        gridLayout_2->addWidget(open_time_label, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        signup_btn = new QPushButton(centralwidget);
        signup_btn->setObjectName(QString::fromUtf8("signup_btn"));

        horizontalLayout->addWidget(signup_btn);


        gridLayout_3->addLayout(horizontalLayout, 1, 1, 1, 1);

        MainSignup->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainSignup);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 485, 22));
        MainSignup->setMenuBar(menubar);
        statusbar = new QStatusBar(MainSignup);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainSignup->setStatusBar(statusbar);
        QWidget::setTabOrder(signup_name_entry, signup_loginID_entry);
        QWidget::setTabOrder(signup_loginID_entry, signup_password_entry);

        retranslateUi(MainSignup);

        QMetaObject::connectSlotsByName(MainSignup);
    } // setupUi

    void retranslateUi(QMainWindow *MainSignup)
    {
        MainSignup->setWindowTitle(QCoreApplication::translate("MainSignup", "MainWindow", nullptr));
        signup_name_label->setText(QCoreApplication::translate("MainSignup", "Name", nullptr));
        signup_password_label->setText(QCoreApplication::translate("MainSignup", "Password", nullptr));
        signup_loginID_label->setText(QCoreApplication::translate("MainSignup", "Login ID", nullptr));
        gap_time_label->setText(QCoreApplication::translate("MainSignup", "Gap Time(Min)", nullptr));
        close_time_label->setText(QCoreApplication::translate("MainSignup", "Close Time", nullptr));
        open_time_label->setText(QCoreApplication::translate("MainSignup", "Open Time", nullptr));
        signup_btn->setText(QCoreApplication::translate("MainSignup", "SignUp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainSignup: public Ui_MainSignup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSIGNUP_H

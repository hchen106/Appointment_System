/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowUI
{
public:
    QWidget *centralwidget;
    QPushButton *add_btn;
    QTabWidget *tabWidget;
    QWidget *List;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *Date;
    QCalendarWidget *calendarWidget;
    QPushButton *refresh_btn;
    QPushButton *setting_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowUI)
    {
        if (MainWindowUI->objectName().isEmpty())
            MainWindowUI->setObjectName(QString::fromUtf8("MainWindowUI"));
        MainWindowUI->resize(853, 660);
        centralwidget = new QWidget(MainWindowUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        add_btn = new QPushButton(centralwidget);
        add_btn->setObjectName(QString::fromUtf8("add_btn"));
        add_btn->setGeometry(QRect(710, 50, 131, 81));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(40, 30, 661, 581));
        List = new QWidget();
        List->setObjectName(QString::fromUtf8("List"));
        gridLayoutWidget = new QWidget(List);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 641, 541));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(List, QString());
        Date = new QWidget();
        Date->setObjectName(QString::fromUtf8("Date"));
        calendarWidget = new QCalendarWidget(Date);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(10, 10, 551, 341));
        tabWidget->addTab(Date, QString());
        refresh_btn = new QPushButton(centralwidget);
        refresh_btn->setObjectName(QString::fromUtf8("refresh_btn"));
        refresh_btn->setGeometry(QRect(710, 170, 131, 81));
        setting_btn = new QPushButton(centralwidget);
        setting_btn->setObjectName(QString::fromUtf8("setting_btn"));
        setting_btn->setGeometry(QRect(710, 450, 131, 81));
        MainWindowUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 853, 22));
        MainWindowUI->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowUI->setStatusBar(statusbar);

        retranslateUi(MainWindowUI);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowUI);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowUI)
    {
        MainWindowUI->setWindowTitle(QCoreApplication::translate("MainWindowUI", "MainWindow", nullptr));
        add_btn->setText(QCoreApplication::translate("MainWindowUI", "Add Client", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(List), QCoreApplication::translate("MainWindowUI", "List", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Date), QCoreApplication::translate("MainWindowUI", "Date", nullptr));
        refresh_btn->setText(QCoreApplication::translate("MainWindowUI", "Refresh", nullptr));
        setting_btn->setText(QCoreApplication::translate("MainWindowUI", "Setting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowUI: public Ui_MainWindowUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

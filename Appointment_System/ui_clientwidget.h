/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientwidget
{
public:
    QLabel *Picture_label;
    QLabel *name_label;
    QLabel *phone_label;
    QLabel *address_label;
    QPushButton *view_btn;

    void setupUi(QWidget *clientwidget)
    {
        if (clientwidget->objectName().isEmpty())
            clientwidget->setObjectName(QString::fromUtf8("clientwidget"));
        clientwidget->resize(242, 113);
        clientwidget->setStyleSheet(QString::fromUtf8(""));
        Picture_label = new QLabel(clientwidget);
        Picture_label->setObjectName(QString::fromUtf8("Picture_label"));
        Picture_label->setGeometry(QRect(10, 0, 71, 71));
        name_label = new QLabel(clientwidget);
        name_label->setObjectName(QString::fromUtf8("name_label"));
        name_label->setGeometry(QRect(90, 9, 151, 17));
        phone_label = new QLabel(clientwidget);
        phone_label->setObjectName(QString::fromUtf8("phone_label"));
        phone_label->setGeometry(QRect(90, 32, 151, 17));
        address_label = new QLabel(clientwidget);
        address_label->setObjectName(QString::fromUtf8("address_label"));
        address_label->setGeometry(QRect(90, 50, 151, 61));
        view_btn = new QPushButton(clientwidget);
        view_btn->setObjectName(QString::fromUtf8("view_btn"));
        view_btn->setGeometry(QRect(10, 74, 71, 31));

        retranslateUi(clientwidget);

        QMetaObject::connectSlotsByName(clientwidget);
    } // setupUi

    void retranslateUi(QWidget *clientwidget)
    {
        clientwidget->setWindowTitle(QCoreApplication::translate("clientwidget", "Form", nullptr));
        Picture_label->setText(QCoreApplication::translate("clientwidget", "TextLabel", nullptr));
        name_label->setText(QCoreApplication::translate("clientwidget", "TextLabel", nullptr));
        phone_label->setText(QCoreApplication::translate("clientwidget", "TextLabel", nullptr));
        address_label->setText(QCoreApplication::translate("clientwidget", "TextLabel", nullptr));
        view_btn->setText(QCoreApplication::translate("clientwidget", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientwidget: public Ui_clientwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H

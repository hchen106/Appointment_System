/********************************************************************************
** Form generated from reading UI file 'appointmentsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPOINTMENTSETTING_H
#define UI_APPOINTMENTSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_appointmentsetting
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QTimeEdit *close_time_entry;
    QLineEdit *gap_time_entry;
    QLabel *gap_time_label;
    QTimeEdit *open_time_entry;
    QLabel *close_time_label;
    QLabel *open_time_label;
    QHBoxLayout *horizontalLayout;
    QPushButton *apply_btn;

    void setupUi(QDialog *appointmentsetting)
    {
        if (appointmentsetting->objectName().isEmpty())
            appointmentsetting->setObjectName(QString::fromUtf8("appointmentsetting"));
        appointmentsetting->resize(341, 199);
        gridLayout = new QGridLayout(appointmentsetting);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        close_time_entry = new QTimeEdit(appointmentsetting);
        close_time_entry->setObjectName(QString::fromUtf8("close_time_entry"));

        gridLayout_2->addWidget(close_time_entry, 1, 1, 1, 1);

        gap_time_entry = new QLineEdit(appointmentsetting);
        gap_time_entry->setObjectName(QString::fromUtf8("gap_time_entry"));

        gridLayout_2->addWidget(gap_time_entry, 2, 1, 1, 1);

        gap_time_label = new QLabel(appointmentsetting);
        gap_time_label->setObjectName(QString::fromUtf8("gap_time_label"));

        gridLayout_2->addWidget(gap_time_label, 2, 0, 1, 1);

        open_time_entry = new QTimeEdit(appointmentsetting);
        open_time_entry->setObjectName(QString::fromUtf8("open_time_entry"));

        gridLayout_2->addWidget(open_time_entry, 0, 1, 1, 1);

        close_time_label = new QLabel(appointmentsetting);
        close_time_label->setObjectName(QString::fromUtf8("close_time_label"));

        gridLayout_2->addWidget(close_time_label, 1, 0, 1, 1);

        open_time_label = new QLabel(appointmentsetting);
        open_time_label->setObjectName(QString::fromUtf8("open_time_label"));

        gridLayout_2->addWidget(open_time_label, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        apply_btn = new QPushButton(appointmentsetting);
        apply_btn->setObjectName(QString::fromUtf8("apply_btn"));

        horizontalLayout->addWidget(apply_btn);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(appointmentsetting);

        QMetaObject::connectSlotsByName(appointmentsetting);
    } // setupUi

    void retranslateUi(QDialog *appointmentsetting)
    {
        appointmentsetting->setWindowTitle(QCoreApplication::translate("appointmentsetting", "Dialog", nullptr));
        gap_time_label->setText(QCoreApplication::translate("appointmentsetting", "Gap Time(Min)", nullptr));
        close_time_label->setText(QCoreApplication::translate("appointmentsetting", "Close Time", nullptr));
        open_time_label->setText(QCoreApplication::translate("appointmentsetting", "Open Time", nullptr));
        apply_btn->setText(QCoreApplication::translate("appointmentsetting", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class appointmentsetting: public Ui_appointmentsetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPOINTMENTSETTING_H

/********************************************************************************
** Form generated from reading UI file 'ratemyprof.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RATEMYPROF_H
#define UI_RATEMYPROF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rateMyProf
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_3;
    QTableView *tableView;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QTableView *tableView_2;
    QLabel *label_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *rateMyProf)
    {
        if (rateMyProf->objectName().isEmpty())
            rateMyProf->setObjectName(QString::fromUtf8("rateMyProf"));
        rateMyProf->resize(1153, 1074);
        centralwidget = new QWidget(rateMyProf);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 941, 71));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 401, 16));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 270, 1121, 201));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 100, 941, 55));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        comboBox_2 = new QComboBox(layoutWidget1);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        verticalLayout_2->addWidget(comboBox_2);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 180, 931, 61));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        horizontalLayout_3->addLayout(horizontalLayout_2);

        lineEdit = new QLineEdit(layoutWidget2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);

        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(horizontalLayout_3);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 250, 921, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 480, 901, 31));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 530, 861, 16));
        tableView_2 = new QTableView(centralwidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(20, 560, 1121, 241));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 820, 881, 31));
        rateMyProf->setCentralWidget(centralwidget);
        menubar = new QMenuBar(rateMyProf);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1153, 24));
        rateMyProf->setMenuBar(menubar);
        statusbar = new QStatusBar(rateMyProf);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        rateMyProf->setStatusBar(statusbar);

        retranslateUi(rateMyProf);

        QMetaObject::connectSlotsByName(rateMyProf);
    } // setupUi

    void retranslateUi(QMainWindow *rateMyProf)
    {
        rateMyProf->setWindowTitle(QCoreApplication::translate("rateMyProf", "rateMyProf", nullptr));
        label->setText(QCoreApplication::translate("rateMyProf", "Menu Options:", nullptr));
        label_3->setText(QCoreApplication::translate("rateMyProf", "Find out the best professor from your University!!", nullptr));
        label_2->setText(QCoreApplication::translate("rateMyProf", "University:", nullptr));
        label_4->setText(QCoreApplication::translate("rateMyProf", "Text", nullptr));
        pushButton->setText(QCoreApplication::translate("rateMyProf", "Search", nullptr));
        label_5->setText(QCoreApplication::translate("rateMyProf", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("rateMyProf", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("rateMyProf", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("rateMyProf", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rateMyProf: public Ui_rateMyProf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RATEMYPROF_H

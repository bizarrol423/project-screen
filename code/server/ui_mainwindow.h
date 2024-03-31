/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *SendButton;
    QSpacerItem *horizontalSpacer;
    QTextBrowser *CommadBrowser;
    QLineEdit *IpAddress;
    QTableWidget *TableClientData;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *CommandLine;
    QPushButton *StartListerningButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(751, 688);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        SendButton = new QPushButton(centralwidget);
        SendButton->setObjectName("SendButton");

        gridLayout->addWidget(SendButton, 2, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        CommadBrowser = new QTextBrowser(centralwidget);
        CommadBrowser->setObjectName("CommadBrowser");

        gridLayout->addWidget(CommadBrowser, 1, 4, 1, 2);

        IpAddress = new QLineEdit(centralwidget);
        IpAddress->setObjectName("IpAddress");

        gridLayout->addWidget(IpAddress, 0, 0, 1, 1);

        TableClientData = new QTableWidget(centralwidget);
        if (TableClientData->columnCount() < 3)
            TableClientData->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TableClientData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TableClientData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TableClientData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        TableClientData->setObjectName("TableClientData");
        TableClientData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        TableClientData->setDragEnabled(false);
        TableClientData->setAlternatingRowColors(false);
        TableClientData->setSelectionMode(QAbstractItemView::SingleSelection);
        TableClientData->setSelectionBehavior(QAbstractItemView::SelectRows);
        TableClientData->setSortingEnabled(false);
        TableClientData->horizontalHeader()->setCascadingSectionResizes(false);
        TableClientData->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        TableClientData->horizontalHeader()->setStretchLastSection(true);
        TableClientData->verticalHeader()->setVisible(false);

        gridLayout->addWidget(TableClientData, 1, 0, 2, 4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        CommandLine = new QLineEdit(centralwidget);
        CommandLine->setObjectName("CommandLine");
        CommandLine->setMaxLength(32763);

        gridLayout->addWidget(CommandLine, 2, 4, 1, 1);

        StartListerningButton = new QPushButton(centralwidget);
        StartListerningButton->setObjectName("StartListerningButton");

        gridLayout->addWidget(StartListerningButton, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 751, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "server", nullptr));
        SendButton->setText(QCoreApplication::translate("MainWindow", "send", nullptr));
        IpAddress->setText(QCoreApplication::translate("MainWindow", "45.86.86.32", nullptr));
        IpAddress->setPlaceholderText(QCoreApplication::translate("MainWindow", "IP address", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TableClientData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TableClientData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "IP address", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TableClientData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "size screen", nullptr));
        CommandLine->setText(QString());
        CommandLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "command send", nullptr));
        StartListerningButton->setText(QCoreApplication::translate("MainWindow", "Start Listening", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'console.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLE_H
#define UI_CONSOLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_console
{
public:
    QLabel *label;

    void setupUi(QWidget *console)
    {
        if (console->objectName().isEmpty())
            console->setObjectName("console");
        console->resize(766, 521);
        label = new QLabel(console);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 411, 501));
        label->setScaledContents(true);

        retranslateUi(console);

        QMetaObject::connectSlotsByName(console);
    } // setupUi

    void retranslateUi(QWidget *console)
    {
        console->setWindowTitle(QCoreApplication::translate("console", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class console: public Ui_console {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLE_H

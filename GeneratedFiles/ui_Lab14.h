/********************************************************************************
** Form generated from reading UI file 'Lab14.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB14_H
#define UI_LAB14_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab14Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lab14Class)
    {
        if (Lab14Class->objectName().isEmpty())
            Lab14Class->setObjectName(QStringLiteral("Lab14Class"));
        Lab14Class->resize(600, 400);
        menuBar = new QMenuBar(Lab14Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Lab14Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lab14Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lab14Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lab14Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Lab14Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lab14Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lab14Class->setStatusBar(statusBar);

        retranslateUi(Lab14Class);

        QMetaObject::connectSlotsByName(Lab14Class);
    } // setupUi

    void retranslateUi(QMainWindow *Lab14Class)
    {
        Lab14Class->setWindowTitle(QApplication::translate("Lab14Class", "Lab14", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lab14Class: public Ui_Lab14Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB14_H

/********************************************************************************
** Form generated from reading UI file 'summarywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUMMARYWINDOW_H
#define UI_SUMMARYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SummaryWindow
{
public:
    QAction *actionTeaching_Graph;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTreeWidget *treeWidget;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuGraphs;
    QMenu *menuSet_Date_Range;

    void setupUi(QMainWindow *SummaryWindow)
    {
        if (SummaryWindow->objectName().isEmpty())
            SummaryWindow->setObjectName(QStringLiteral("SummaryWindow"));
        SummaryWindow->resize(662, 366);
        actionTeaching_Graph = new QAction(SummaryWindow);
        actionTeaching_Graph->setObjectName(QStringLiteral("actionTeaching_Graph"));
        centralwidget = new QWidget(SummaryWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 661, 331));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        treeWidget = new QTreeWidget(tab);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(0, 0, 657, 327));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        SummaryWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SummaryWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 662, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuGraphs = new QMenu(menubar);
        menuGraphs->setObjectName(QStringLiteral("menuGraphs"));
        menuSet_Date_Range = new QMenu(menubar);
        menuSet_Date_Range->setObjectName(QStringLiteral("menuSet_Date_Range"));
        SummaryWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuGraphs->menuAction());
        menubar->addAction(menuSet_Date_Range->menuAction());
        menuGraphs->addAction(actionTeaching_Graph);

        retranslateUi(SummaryWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SummaryWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SummaryWindow)
    {
        SummaryWindow->setWindowTitle(QApplication::translate("SummaryWindow", "MainWindow", 0));
        actionTeaching_Graph->setText(QApplication::translate("SummaryWindow", "Teaching Graph", 0));
        actionTeaching_Graph->setShortcut(QApplication::translate("SummaryWindow", "Meta+G", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SummaryWindow", "Publications", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SummaryWindow", "Presentations", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("SummaryWindow", "Grants", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("SummaryWindow", "Teaching", 0));
        menuFile->setTitle(QApplication::translate("SummaryWindow", "File", 0));
        menuGraphs->setTitle(QApplication::translate("SummaryWindow", "Graphs", 0));
        menuSet_Date_Range->setTitle(QApplication::translate("SummaryWindow", "Set Date Range", 0));
    } // retranslateUi

};

namespace Ui {
    class SummaryWindow: public Ui_SummaryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUMMARYWINDOW_H

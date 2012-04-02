/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 19. Mar 21:48:19 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDockWidget>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QListWidget *messagesList;
    QTextEdit *messageEdit;
    QComboBox *protocolSelection;
    QPushButton *sendBtn;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QCommandLinkButton *commandLinkButton_4;
    QCommandLinkButton *commandLinkButton_3;
    QCommandLinkButton *commandLinkButton_2;
    QCommandLinkButton *commandLinkButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 588);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        messagesList = new QListWidget(centralWidget);
        messagesList->setObjectName(QString::fromUtf8("messagesList"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(messagesList->sizePolicy().hasHeightForWidth());
        messagesList->setSizePolicy(sizePolicy);

        gridLayout->addWidget(messagesList, 0, 0, 1, 1);

        messageEdit = new QTextEdit(centralWidget);
        messageEdit->setObjectName(QString::fromUtf8("messageEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(messageEdit->sizePolicy().hasHeightForWidth());
        messageEdit->setSizePolicy(sizePolicy1);
        messageEdit->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(messageEdit, 3, 0, 2, 1);

        protocolSelection = new QComboBox(centralWidget);
        protocolSelection->setObjectName(QString::fromUtf8("protocolSelection"));

        gridLayout->addWidget(protocolSelection, 3, 1, 1, 1);

        sendBtn = new QPushButton(centralWidget);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));

        gridLayout->addWidget(sendBtn, 4, 1, 1, 1);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        commandLinkButton_4 = new QCommandLinkButton(frame);
        commandLinkButton_4->setObjectName(QString::fromUtf8("commandLinkButton_4"));

        horizontalLayout->addWidget(commandLinkButton_4);

        commandLinkButton_3 = new QCommandLinkButton(frame);
        commandLinkButton_3->setObjectName(QString::fromUtf8("commandLinkButton_3"));

        horizontalLayout->addWidget(commandLinkButton_3);

        commandLinkButton_2 = new QCommandLinkButton(frame);
        commandLinkButton_2->setObjectName(QString::fromUtf8("commandLinkButton_2"));

        horizontalLayout->addWidget(commandLinkButton_2);

        commandLinkButton = new QCommandLinkButton(frame);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));

        horizontalLayout->addWidget(commandLinkButton);


        gridLayout->addWidget(frame, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        retranslateUi(MainWindow);

        protocolSelection->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        sendBtn->setText(QApplication::translate("MainWindow", "Senden...", 0, QApplication::UnicodeUTF8));
        commandLinkButton_4->setText(QApplication::translate("MainWindow", "IM", 0, QApplication::UnicodeUTF8));
        commandLinkButton_3->setText(QApplication::translate("MainWindow", "E-Mail", 0, QApplication::UnicodeUTF8));
        commandLinkButton_2->setText(QApplication::translate("MainWindow", "Datei\303\274bertragung", 0, QApplication::UnicodeUTF8));
        commandLinkButton->setText(QApplication::translate("MainWindow", "Posten", 0, QApplication::UnicodeUTF8));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "Kontakte", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

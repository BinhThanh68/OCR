/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *LB_MainView;
    QGroupBox *groupBox;
    QPushButton *BTN_ImageOpen;
    QPushButton *BTN_CamOpen;
    QPushButton *BTN_VideoOpen;
    QPushButton *BTNPause;
    QTabWidget *Algorithms;
    QWidget *tab;
    QCheckBox *CB_TextDetectorEnable;
    QLabel *LB_ScoreTresholdVal;
    QLabel *label;
    QSlider *SB_ScoreTreshold;
    QLabel *LB_NMSThresholdVal;
    QSlider *SB_NMSThreshold;
    QLabel *label_3;
    QWidget *tab_2;
    QCheckBox *CB_TextRecogEnable;
    QPushButton *BTN_WriteText2File;
    QComboBox *CBB_WriteMethod;
    QPlainTextEdit *PTE_AppLog;
    QPlainTextEdit *PTE_TextOutput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1011, 753);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        LB_MainView = new QLabel(centralwidget);
        LB_MainView->setObjectName(QStringLiteral("LB_MainView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LB_MainView->sizePolicy().hasHeightForWidth());
        LB_MainView->setSizePolicy(sizePolicy1);
        LB_MainView->setMinimumSize(QSize(711, 441));
        LB_MainView->setAutoFillBackground(false);
        LB_MainView->setStyleSheet(QStringLiteral("background-color: rgb(51, 51, 51);"));
        LB_MainView->setScaledContents(false);
        LB_MainView->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LB_MainView, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMinimumSize(QSize(276, 691));
        BTN_ImageOpen = new QPushButton(groupBox);
        BTN_ImageOpen->setObjectName(QStringLiteral("BTN_ImageOpen"));
        BTN_ImageOpen->setGeometry(QRect(10, 30, 71, 61));
        sizePolicy.setHeightForWidth(BTN_ImageOpen->sizePolicy().hasHeightForWidth());
        BTN_ImageOpen->setSizePolicy(sizePolicy);
        BTN_ImageOpen->setIconSize(QSize(150, 150));
        BTN_CamOpen = new QPushButton(groupBox);
        BTN_CamOpen->setObjectName(QStringLiteral("BTN_CamOpen"));
        BTN_CamOpen->setGeometry(QRect(100, 30, 71, 61));
        sizePolicy.setHeightForWidth(BTN_CamOpen->sizePolicy().hasHeightForWidth());
        BTN_CamOpen->setSizePolicy(sizePolicy);
        BTN_VideoOpen = new QPushButton(groupBox);
        BTN_VideoOpen->setObjectName(QStringLiteral("BTN_VideoOpen"));
        BTN_VideoOpen->setGeometry(QRect(190, 30, 71, 61));
        sizePolicy.setHeightForWidth(BTN_VideoOpen->sizePolicy().hasHeightForWidth());
        BTN_VideoOpen->setSizePolicy(sizePolicy);
        BTNPause = new QPushButton(groupBox);
        BTNPause->setObjectName(QStringLiteral("BTNPause"));
        BTNPause->setGeometry(QRect(120, 100, 31, 31));
        Algorithms = new QTabWidget(groupBox);
        Algorithms->setObjectName(QStringLiteral("Algorithms"));
        Algorithms->setGeometry(QRect(10, 170, 251, 271));
        QFont font;
        font.setPointSize(13);
        Algorithms->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        CB_TextDetectorEnable = new QCheckBox(tab);
        CB_TextDetectorEnable->setObjectName(QStringLiteral("CB_TextDetectorEnable"));
        CB_TextDetectorEnable->setGeometry(QRect(100, 20, 101, 21));
        QFont font1;
        font1.setPointSize(15);
        CB_TextDetectorEnable->setFont(font1);
        CB_TextDetectorEnable->setAutoFillBackground(false);
        LB_ScoreTresholdVal = new QLabel(tab);
        LB_ScoreTresholdVal->setObjectName(QStringLiteral("LB_ScoreTresholdVal"));
        LB_ScoreTresholdVal->setGeometry(QRect(210, 70, 31, 31));
        LB_ScoreTresholdVal->setFont(font1);
        LB_ScoreTresholdVal->setAutoFillBackground(false);
        LB_ScoreTresholdVal->setStyleSheet(QStringLiteral(""));
        LB_ScoreTresholdVal->setAlignment(Qt::AlignCenter);
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 60, 131, 20));
        label->setFont(font);
        SB_ScoreTreshold = new QSlider(tab);
        SB_ScoreTreshold->setObjectName(QStringLiteral("SB_ScoreTreshold"));
        SB_ScoreTreshold->setGeometry(QRect(20, 82, 181, 18));
        SB_ScoreTreshold->setMinimum(1);
        SB_ScoreTreshold->setMaximum(9);
        SB_ScoreTreshold->setValue(5);
        SB_ScoreTreshold->setOrientation(Qt::Horizontal);
        LB_NMSThresholdVal = new QLabel(tab);
        LB_NMSThresholdVal->setObjectName(QStringLiteral("LB_NMSThresholdVal"));
        LB_NMSThresholdVal->setGeometry(QRect(210, 130, 31, 31));
        LB_NMSThresholdVal->setFont(font1);
        LB_NMSThresholdVal->setAutoFillBackground(false);
        LB_NMSThresholdVal->setStyleSheet(QStringLiteral(""));
        LB_NMSThresholdVal->setAlignment(Qt::AlignCenter);
        SB_NMSThreshold = new QSlider(tab);
        SB_NMSThreshold->setObjectName(QStringLiteral("SB_NMSThreshold"));
        SB_NMSThreshold->setGeometry(QRect(20, 143, 181, 18));
        SB_NMSThreshold->setMinimum(1);
        SB_NMSThreshold->setMaximum(9);
        SB_NMSThreshold->setValue(4);
        SB_NMSThreshold->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 120, 151, 20));
        label_3->setFont(font);
        Algorithms->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        CB_TextRecogEnable = new QCheckBox(tab_2);
        CB_TextRecogEnable->setObjectName(QStringLiteral("CB_TextRecogEnable"));
        CB_TextRecogEnable->setGeometry(QRect(100, 20, 101, 22));
        CB_TextRecogEnable->setFont(font1);
        CB_TextRecogEnable->setAutoFillBackground(false);
        BTN_WriteText2File = new QPushButton(tab_2);
        BTN_WriteText2File->setObjectName(QStringLiteral("BTN_WriteText2File"));
        BTN_WriteText2File->setGeometry(QRect(80, 90, 111, 51));
        BTN_WriteText2File->setFont(font1);
        CBB_WriteMethod = new QComboBox(tab_2);
        CBB_WriteMethod->setObjectName(QStringLiteral("CBB_WriteMethod"));
        CBB_WriteMethod->setGeometry(QRect(80, 150, 111, 25));
        Algorithms->addTab(tab_2, QString());
        PTE_AppLog = new QPlainTextEdit(groupBox);
        PTE_AppLog->setObjectName(QStringLiteral("PTE_AppLog"));
        PTE_AppLog->setGeometry(QRect(10, 450, 251, 231));
        PTE_AppLog->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        PTE_AppLog->setReadOnly(true);

        gridLayout->addWidget(groupBox, 0, 1, 2, 1);

        PTE_TextOutput = new QPlainTextEdit(centralwidget);
        PTE_TextOutput->setObjectName(QStringLiteral("PTE_TextOutput"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(PTE_TextOutput->sizePolicy().hasHeightForWidth());
        PTE_TextOutput->setSizePolicy(sizePolicy3);
        PTE_TextOutput->setMinimumSize(QSize(0, 244));
        PTE_TextOutput->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        PTE_TextOutput->setReadOnly(true);

        gridLayout->addWidget(PTE_TextOutput, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1011, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Algorithms->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OCR Tool", Q_NULLPTR));
        LB_MainView->setText(QString());
        groupBox->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        BTN_ImageOpen->setToolTip(QApplication::translate("MainWindow", "Open image", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        BTN_ImageOpen->setText(QString());
#ifndef QT_NO_TOOLTIP
        BTN_CamOpen->setToolTip(QApplication::translate("MainWindow", "Open camera", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        BTN_CamOpen->setText(QString());
#ifndef QT_NO_TOOLTIP
        BTN_VideoOpen->setToolTip(QApplication::translate("MainWindow", "Open video", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        BTN_VideoOpen->setText(QString());
        BTNPause->setText(QString());
#ifndef QT_NO_TOOLTIP
        CB_TextDetectorEnable->setToolTip(QApplication::translate("MainWindow", "Enable cascade detector", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        CB_TextDetectorEnable->setText(QApplication::translate("MainWindow", "Enable", Q_NULLPTR));
        LB_ScoreTresholdVal->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Score threshold", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        SB_ScoreTreshold->setToolTip(QApplication::translate("MainWindow", "Adjust scale factor", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        LB_NMSThresholdVal->setText(QString());
#ifndef QT_NO_TOOLTIP
        SB_NMSThreshold->setToolTip(QApplication::translate("MainWindow", "Adjust min neigbor", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("MainWindow", "NMS threshold", Q_NULLPTR));
        Algorithms->setTabText(Algorithms->indexOf(tab), QApplication::translate("MainWindow", "Detection", Q_NULLPTR));
        CB_TextRecogEnable->setText(QApplication::translate("MainWindow", "Enable", Q_NULLPTR));
        BTN_WriteText2File->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        CBB_WriteMethod->clear();
        CBB_WriteMethod->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Overwrite", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Append", Q_NULLPTR)
        );
        Algorithms->setTabText(Algorithms->indexOf(tab_2), QApplication::translate("MainWindow", "Recognition", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *refuelGroupBox;
    QLabel *fuelTypeLabel;
    QComboBox *fuelTypeComboBox;
    QLabel *fuelAmountLabel;
    QLabel *paymentTypeLabel;
    QComboBox *paymentTypeComboBox;
    QPushButton *refuelButton;
    QComboBox *workstationComboBox;
    QLabel *workstationlabel;
    QDoubleSpinBox *fuelAmountSpinBox;
    QGroupBox *refuelButton_2;
    QLabel *price92Label;
    QLabel *price95Label;
    QLabel *price100Label;
    QLabel *priceDTLabel;
    QPushButton *pricesButton;
    QDoubleSpinBox *price92SpinBox;
    QDoubleSpinBox *price95SpinBox;
    QDoubleSpinBox *price100SpinBox;
    QDoubleSpinBox *priceDTSpinBox;
    QGroupBox *historyGroupBox;
    QPushButton *historyButton;
    QTableView *historyTableView;
    QPushButton *resizeButton;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(525, 270);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8("background: qlineargradient(angle: 45deg, stop:0 #ee9ca7, stop:1 #ffdde1);\n"
"border-color: rgb(0, 0, 0);\n"
"\n"
""));
        refuelGroupBox = new QGroupBox(centralwidget);
        refuelGroupBox->setObjectName(QString::fromUtf8("refuelGroupBox"));
        refuelGroupBox->setGeometry(QRect(10, 20, 491, 191));
        refuelGroupBox->setStyleSheet(QString::fromUtf8("background: linear-gradient(90deg, #b9deed, #efefef);\n"
"border-color: rgb(0, 0, 0);"));
        fuelTypeLabel = new QLabel(refuelGroupBox);
        fuelTypeLabel->setObjectName(QString::fromUtf8("fuelTypeLabel"));
        fuelTypeLabel->setGeometry(QRect(20, 70, 171, 16));
        fuelTypeLabel->setTextFormat(Qt::AutoText);
        fuelTypeComboBox = new QComboBox(refuelGroupBox);
        fuelTypeComboBox->addItem(QString());
        fuelTypeComboBox->addItem(QString());
        fuelTypeComboBox->addItem(QString());
        fuelTypeComboBox->addItem(QString());
        fuelTypeComboBox->setObjectName(QString::fromUtf8("fuelTypeComboBox"));
        fuelTypeComboBox->setGeometry(QRect(210, 70, 121, 22));
        fuelTypeComboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        fuelTypeComboBox->setEditable(false);
        fuelAmountLabel = new QLabel(refuelGroupBox);
        fuelAmountLabel->setObjectName(QString::fromUtf8("fuelAmountLabel"));
        fuelAmountLabel->setGeometry(QRect(20, 110, 181, 16));
        paymentTypeLabel = new QLabel(refuelGroupBox);
        paymentTypeLabel->setObjectName(QString::fromUtf8("paymentTypeLabel"));
        paymentTypeLabel->setGeometry(QRect(20, 150, 151, 16));
        paymentTypeLabel->setTextFormat(Qt::AutoText);
        paymentTypeComboBox = new QComboBox(refuelGroupBox);
        paymentTypeComboBox->addItem(QString());
        paymentTypeComboBox->addItem(QString());
        paymentTypeComboBox->addItem(QString());
        paymentTypeComboBox->setObjectName(QString::fromUtf8("paymentTypeComboBox"));
        paymentTypeComboBox->setGeometry(QRect(180, 150, 151, 22));
        paymentTypeComboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        refuelButton = new QPushButton(refuelGroupBox);
        refuelButton->setObjectName(QString::fromUtf8("refuelButton"));
        refuelButton->setGeometry(QRect(350, 30, 131, 141));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../build-ARM-Desktop_Qt_5_12_12_MinGW_32_bit-Debug/oil-can.png"), QSize(), QIcon::Normal, QIcon::Off);
        refuelButton->setIcon(icon);
        refuelButton->setIconSize(QSize(64, 64));
        workstationComboBox = new QComboBox(refuelGroupBox);
        workstationComboBox->addItem(QString());
        workstationComboBox->addItem(QString());
        workstationComboBox->addItem(QString());
        workstationComboBox->addItem(QString());
        workstationComboBox->addItem(QString());
        workstationComboBox->setObjectName(QString::fromUtf8("workstationComboBox"));
        workstationComboBox->setGeometry(QRect(210, 30, 121, 22));
        workstationComboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        workstationComboBox->setEditable(false);
        workstationlabel = new QLabel(refuelGroupBox);
        workstationlabel->setObjectName(QString::fromUtf8("workstationlabel"));
        workstationlabel->setGeometry(QRect(20, 30, 181, 20));
        fuelAmountSpinBox = new QDoubleSpinBox(refuelGroupBox);
        fuelAmountSpinBox->setObjectName(QString::fromUtf8("fuelAmountSpinBox"));
        fuelAmountSpinBox->setGeometry(QRect(210, 110, 121, 22));
        fuelAmountSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        fuelAmountSpinBox->setMaximum(50.000000000000000);
        refuelButton_2 = new QGroupBox(centralwidget);
        refuelButton_2->setObjectName(QString::fromUtf8("refuelButton_2"));
        refuelButton_2->setGeometry(QRect(560, 20, 521, 191));
        refuelButton_2->setStyleSheet(QString::fromUtf8("background: linear-gradient(90deg, #b9deed, #efefef);"));
        price92Label = new QLabel(refuelButton_2);
        price92Label->setObjectName(QString::fromUtf8("price92Label"));
        price92Label->setGeometry(QRect(10, 30, 241, 16));
        price92Label->setStyleSheet(QString::fromUtf8(""));
        price95Label = new QLabel(refuelButton_2);
        price95Label->setObjectName(QString::fromUtf8("price95Label"));
        price95Label->setGeometry(QRect(10, 70, 241, 16));
        price95Label->setStyleSheet(QString::fromUtf8(""));
        price100Label = new QLabel(refuelButton_2);
        price100Label->setObjectName(QString::fromUtf8("price100Label"));
        price100Label->setGeometry(QRect(10, 110, 241, 16));
        price100Label->setStyleSheet(QString::fromUtf8(""));
        priceDTLabel = new QLabel(refuelButton_2);
        priceDTLabel->setObjectName(QString::fromUtf8("priceDTLabel"));
        priceDTLabel->setGeometry(QRect(10, 150, 241, 16));
        priceDTLabel->setStyleSheet(QString::fromUtf8(""));
        pricesButton = new QPushButton(refuelButton_2);
        pricesButton->setObjectName(QString::fromUtf8("pricesButton"));
        pricesButton->setGeometry(QRect(390, 30, 121, 141));
        pricesButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"text-align: center;\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(255, 255, 0);\n"
"	color: rgb(0, 0, 0);\n"
"	\n"
"}"));
        price92SpinBox = new QDoubleSpinBox(refuelButton_2);
        price92SpinBox->setObjectName(QString::fromUtf8("price92SpinBox"));
        price92SpinBox->setGeometry(QRect(260, 30, 111, 22));
        price92SpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        price92SpinBox->setValue(45.500000000000000);
        price95SpinBox = new QDoubleSpinBox(refuelButton_2);
        price95SpinBox->setObjectName(QString::fromUtf8("price95SpinBox"));
        price95SpinBox->setGeometry(QRect(260, 70, 111, 22));
        price95SpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        price95SpinBox->setValue(48.500000000000000);
        price100SpinBox = new QDoubleSpinBox(refuelButton_2);
        price100SpinBox->setObjectName(QString::fromUtf8("price100SpinBox"));
        price100SpinBox->setGeometry(QRect(260, 110, 111, 22));
        price100SpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        price100SpinBox->setValue(52.000000000000000);
        priceDTSpinBox = new QDoubleSpinBox(refuelButton_2);
        priceDTSpinBox->setObjectName(QString::fromUtf8("priceDTSpinBox"));
        priceDTSpinBox->setGeometry(QRect(260, 150, 111, 22));
        priceDTSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        priceDTSpinBox->setValue(47.000000000000000);
        historyGroupBox = new QGroupBox(centralwidget);
        historyGroupBox->setObjectName(QString::fromUtf8("historyGroupBox"));
        historyGroupBox->setGeometry(QRect(10, 280, 1071, 271));
        historyGroupBox->setStyleSheet(QString::fromUtf8("background: linear-gradient(90deg, #b9deed, #efefef);"));
        historyButton = new QPushButton(historyGroupBox);
        historyButton->setObjectName(QString::fromUtf8("historyButton"));
        historyButton->setGeometry(QRect(960, 30, 91, 21));
        historyButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"text-align: center;\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(255, 255, 0);\n"
"	color: rgb(0, 0, 0);\n"
"	\n"
"}"));
        historyTableView = new QTableView(historyGroupBox);
        historyTableView->setObjectName(QString::fromUtf8("historyTableView"));
        historyTableView->setGeometry(QRect(20, 60, 1031, 201));
        historyTableView->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        historyTableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        historyTableView->setTextElideMode(Qt::ElideMiddle);
        historyTableView->setSortingEnabled(true);
        historyTableView->setProperty("resizeColumnsToContents", QVariant(true));
        historyTableView->horizontalHeader()->setCascadingSectionResizes(true);
        historyTableView->horizontalHeader()->setHighlightSections(true);
        historyTableView->verticalHeader()->setVisible(false);
        resizeButton = new QPushButton(centralwidget);
        resizeButton->setObjectName(QString::fromUtf8("resizeButton"));
        resizeButton->setGeometry(QRect(330, 220, 171, 21));
        resizeButton->setAutoFillBackground(false);
        resizeButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"text-align: center;\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(255, 255, 0);\n"
"	color: rgb(0, 0, 0);\n"
"	\n"
"}\n"
""));
        resizeButton->setCheckable(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 525, 20));
        menubar->setAutoFillBackground(false);
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\320\274\320\260\321\202\320\270\320\267\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\276\320\265 \321\200\320\260\320\261\320\276\321\207\320\265\320\265 \320\274\320\265\321\201\321\202\320\276", nullptr));
        refuelGroupBox->setTitle(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\200\320\260\320\262\320\272\320\260 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\217", nullptr));
        fuelTypeLabel->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\202\320\276\320\277\320\273\320\270\320\262\320\260:", nullptr));
        fuelTypeComboBox->setItemText(0, QApplication::translate("MainWindow", "92", nullptr));
        fuelTypeComboBox->setItemText(1, QApplication::translate("MainWindow", "95", nullptr));
        fuelTypeComboBox->setItemText(2, QApplication::translate("MainWindow", "100", nullptr));
        fuelTypeComboBox->setItemText(3, QApplication::translate("MainWindow", "DT", nullptr));

        fuelAmountLabel->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\202\320\276\320\277\320\273\320\270\320\262\320\260:", nullptr));
        paymentTypeLabel->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\276\320\277\320\273\320\260\321\202\321\213:", nullptr));
        paymentTypeComboBox->setItemText(0, QApplication::translate("MainWindow", "\320\235\320\260\320\273\320\270\321\207\320\275\321\213\320\265", nullptr));
        paymentTypeComboBox->setItemText(1, QApplication::translate("MainWindow", "\320\221\320\260\320\275\320\272\320\276\320\262\321\201\320\272\320\260\321\217 \320\272\320\260\321\200\321\202\320\260", nullptr));
        paymentTypeComboBox->setItemText(2, QApplication::translate("MainWindow", "\320\232\320\260\321\200\321\202\320\260 \320\273\320\276\321\217\320\273\321\214\320\275\320\276\321\201\321\202\320\270", nullptr));

        refuelButton->setText(QString());
        workstationComboBox->setItemText(0, QApplication::translate("MainWindow", "1", nullptr));
        workstationComboBox->setItemText(1, QApplication::translate("MainWindow", "2", nullptr));
        workstationComboBox->setItemText(2, QApplication::translate("MainWindow", "3", nullptr));
        workstationComboBox->setItemText(3, QApplication::translate("MainWindow", "4", nullptr));
        workstationComboBox->setItemText(4, QApplication::translate("MainWindow", "5", nullptr));

        workstationlabel->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\207\320\265\320\265 \320\274\320\265\321\201\321\202\320\276:", nullptr));
        refuelButton_2->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \321\206\320\265\320\275 \320\275\320\260 \321\202\320\276\320\277\320\273\320\270\320\262\320\276", nullptr));
        price92Label->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\320\260 \320\267\320\260 \320\273\320\270\321\202\321\200 \321\202\320\276\320\277\320\273\320\270\320\262\320\260 92:", nullptr));
        price95Label->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\320\260 \320\267\320\260 \320\273\320\270\321\202\321\200 \321\202\320\276\320\277\320\273\320\270\320\262\320\260 95:", nullptr));
        price100Label->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\320\260 \320\267\320\260 \320\273\320\270\321\202\321\200 \321\202\320\276\320\277\320\273\320\270\320\262\320\260 100:", nullptr));
        priceDTLabel->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\320\260 \320\267\320\260 \320\273\320\270\321\202\321\200 \321\202\320\276\320\277\320\273\320\270\320\262\320\260 \320\224\320\242:", nullptr));
        pricesButton->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        historyGroupBox->setTitle(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \320\267\320\260\320\277\321\200\320\260\320\262\320\276\320\272", nullptr));
        historyButton->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        resizeButton->setText(QApplication::translate("MainWindow", "\320\241\320\265\321\200\320\262\320\270\321\201\320\275\320\276\320\265 \320\274\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QDateTime>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QProcess>
#include <QThread>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <QScrollBar>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Refueling {
    int check_number;
    QDateTime time;
    float check_fuel1;
    float check_fuel2;
    QString fuel_type;
    float fuel_amount;
    float fuel_price;
    float payment_amount;
    QString payment_type;
    QString workstation_number;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_refuelButton_clicked();
    void on_resizeButton_clicked();
    void on_pricesButton_clicked();
    void on_historyButton_clicked();

private:
    Ui::MainWindow *ui;
    double fuel_prices[4] = { 45.5, 48.5, 52.0, 47.0 };
    int check_number = 1;
    QStandardItemModel *history_model;
    float check_fuel1;
    float check_fuel2;
    void saveRefuelingToFile(Refueling refueling);
    void readRefuelingsFromFile();
    float readNumbers(QString fuel_type, float check_fuel1);
    void saveNumbers(QString fuel_type, float check_fuel2);
    void sendoil(QString fuel_type);
    void sendoil2(QString fuel_type);
    bool raznica(QString fuel_type);
};

#endif // MAINWINDOW_H

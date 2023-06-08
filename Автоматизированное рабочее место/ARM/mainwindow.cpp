#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QIcon icon("icon.png"); // создание объекта иконки
    setWindowIcon(icon);



    QFile check_file("check_number.txt");
    if (check_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&check_file);
        in >> check_number;
    }
    check_file.close();

    history_model = new QStandardItemModel(this);
    history_model->setColumnCount(10);
    history_model->setHeaderData(0, Qt::Horizontal, "Номер чека");
    history_model->setHeaderData(1, Qt::Horizontal, "Время");
    history_model->setHeaderData(2, Qt::Horizontal, "Начальный счетчик");
    history_model->setHeaderData(3, Qt::Horizontal, "Конечный счетчик");
    history_model->setHeaderData(4, Qt::Horizontal, "Тип топлива");
    history_model->setHeaderData(5, Qt::Horizontal, "Кол-во литров");
    history_model->setHeaderData(6, Qt::Horizontal, "Цена за литр");
    history_model->setHeaderData(7, Qt::Horizontal, "Стоимость заправки");
    history_model->setHeaderData(8, Qt::Horizontal, "Тип оплаты");
    history_model->setHeaderData(9, Qt::Horizontal, "Номер рабочего места");

    ui->historyTableView->setModel(history_model);
    ui->historyTableView->horizontalHeader()->setStyleSheet("QHeaderView {color: rgb(0, 0, 0); }");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_refuelButton_clicked()
{
    
    QString fuel_type = ui->fuelTypeComboBox->currentText();
    float fuel_amount = ui->fuelAmountSpinBox->value();
    QString payment_type = ui->paymentTypeComboBox->currentText();
    QString workstation_number = ui->workstationComboBox->currentText();

    float fuel_price;

    if (fuel_type == "92") {
        fuel_price = fuel_prices[0];
    } else if (fuel_type == "95") {
        fuel_price = fuel_prices[1];
    } else if (fuel_type == "100") {
        fuel_price = fuel_prices[2];
    } else if (fuel_type == "DT") {
        fuel_price = fuel_prices[3];
    } else {
        QMessageBox::critical(this, "Ошибка", "Неверный тип топлива");
        return;
    }

    check_fuel1 = readNumbers(fuel_type, check_fuel1);
    float payment_amount = fuel_amount * fuel_price;

    check_fuel2 = check_fuel1 - fuel_amount;
    saveNumbers(fuel_type, check_fuel2);

    if (check_fuel2 < 100) {
        sendoil(fuel_type);
    }


    Refueling refueling;
    refueling.check_number = check_number;
    refueling.time = QDateTime::currentDateTime();
    refueling.check_fuel1 = check_fuel1;
    refueling.check_fuel2 = check_fuel2;
    refueling.fuel_type = fuel_type;
    refueling.fuel_amount = fuel_amount;
    refueling.fuel_price = fuel_price;
    refueling.payment_amount = payment_amount;
    refueling.payment_type = payment_type;
    refueling.workstation_number = workstation_number; 



    saveRefuelingToFile(refueling);

    
    check_number++;

    
    QFile check_file("check_number.txt");
    if (check_file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&check_file);
        out << check_number;
    }
    check_file.close();

    
    QList<QStandardItem*> row_items;
    row_items.append(new QStandardItem(QString::number(refueling.check_number)));
    row_items.append(new QStandardItem(refueling.time.toString()));
    row_items.append(new QStandardItem(QString::number(refueling.check_fuel1)));
    row_items.append(new QStandardItem(QString::number(refueling.check_fuel2)));
    row_items.append(new QStandardItem(refueling.fuel_type));
    row_items.append(new QStandardItem(QString::number(refueling.fuel_amount)));
    row_items.append(new QStandardItem(QString::number(refueling.fuel_price)));
    row_items.append(new QStandardItem(QString::number(refueling.payment_amount)));
    row_items.append(new QStandardItem(refueling.payment_type));
    row_items.append(new QStandardItem(refueling.workstation_number));
    history_model->appendRow(row_items);

    bool flazhok = raznica(fuel_type);
    if (flazhok == true) sendoil2(fuel_type);

    QMessageBox::information(this, "Успешно", "Заправка завершена");


}
int initialWidth = 525;
int initialHeight = 270;

bool isResized = false;
void MainWindow::on_resizeButton_clicked()
{
    if (!isResized) {
        resize(1115, 614);
        isResized = true;
    } else {
        resize(initialWidth, initialHeight);
        isResized = false;
    }
}
void MainWindow::on_pricesButton_clicked()
{
    
    fuel_prices[0] = ui->price92SpinBox->value();
    fuel_prices[1] = ui->price95SpinBox->value();
    fuel_prices[2] = ui->price100SpinBox->value();
    fuel_prices[3] = ui->priceDTSpinBox->value();

    QMessageBox::information(this, "Успешно", "Цены на топливо обновлены");
}

void MainWindow::on_historyButton_clicked()
{
    
    readRefuelingsFromFile();
}

void MainWindow::saveRefuelingToFile(Refueling refueling)
{
    QFile file("history.csv");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << refueling.check_number << ",";
        out << refueling.time.toString("yyyy-MM-dd hh:mm:ss") << ",";
        out << refueling.check_fuel1 << ",";
        out << refueling.check_fuel2 << ",";
        out << refueling.fuel_type << ",";
        out << refueling.fuel_amount << ",";
        out << refueling.fuel_price << ",";
        out << refueling.payment_amount << ",";
        out << refueling.payment_type << ",";
        out << refueling.workstation_number << "\n";
    }
    file.close();
}

void MainWindow::readRefuelingsFromFile()
{
    QFile file("history.csv");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        history_model->removeRows(0, history_model->rowCount());
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            QList<QStandardItem*> row_items;
            for (int i = 0; i < fields.size(); i++) {
                row_items.append(new QStandardItem(fields.at(i)));
            }
            history_model->appendRow(row_items);
        }
    }
    file.close();
}
float MainWindow::readNumbers(QString fuel_type, float check_fuel1) {
    QFile check(fuel_type + ".txt");
    if (check.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&check);
        in >> check_fuel1;
    }
    check.close();
    return check_fuel1;
}


void MainWindow::saveNumbers(QString fuel_type, float check_fuel2) {
    QFile file(fuel_type + ".txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << check_fuel2 << "\n";
    }
    file.close();
}

void MainWindow::sendoil(QString fuel_type) {
    QFile file("sendmail/debug/replace.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << fuel_type << "\n";
    }
    file.close();

    QProcess::startDetached("sendmail/debug/konec.exe");


}
void MainWindow::sendoil2(QString fuel_type) {
    QFile file("sendmail/debug/replace.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << fuel_type << "\n";
    }
    file.close();

    QProcess::startDetached("sendmail/debug/project2.exe");


}
std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
bool MainWindow::raznica(QString fuel_type) {
    std::string filename = "history.csv";
    std::string str = fuel_type.toStdString();
    std::ifstream input(filename);
    std::ifstream input1(filename);
    std::string prover;
    bool flag = true;
        std::string line;
        std::string line1;
        while (std::getline(input, line)) {
            std::vector<std::string> fields = split(line, ',');
            if (fields[4] == str) {
                prover = fields[2];
            }
        }
        while (std::getline(input1, line1)) {
            std::vector<std::string> fields1 = split(line1, ',');
            if (fields1[4] == str) {
                if (prover == fields1[3])
                    flag = false;

            }
        }
        return flag;
}

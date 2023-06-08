#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFontDatabase>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
// путь к файлу шрифта
QString fontPath = "MuseoCyrl500.otf";

// загрузить шрифт из файла
int id = QFontDatabase::addApplicationFont(fontPath);

if (id != -1) {
    // получить список семейств шрифтов, доступных в файле
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(id);

    // задать шрифт для приложения
    if (!fontFamilies.isEmpty()) {
        QFont font(fontFamilies.at(0));
        QApplication::setFont(font);
    }
}
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ARM_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}

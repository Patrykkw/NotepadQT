#include <iostream>
#include "mainwindow.h"
#include <QApplication>
using namespace std;
int main(int argc, char *argv[])
{
    cout << "hi";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

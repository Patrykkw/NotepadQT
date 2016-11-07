#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   qApp->quit();

}

void MainWindow::on_actionQuit_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(), tr("TextFiles (*.txt);; C++ Files (*.cpp *.h);; Java Files (*.jar)"));

    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly))
        {
            //error
        }else{
            QTextStream stream(&file);
            stream << ui->textEdit->toPlainText();
            stream.flush();
            file.close();
        }
    }

}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(), tr("Text Files (*.txt);; C++ Files (*.cpp *.h);; Java Files (*.jar)"));

    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly)){
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        file.close();
    }

}


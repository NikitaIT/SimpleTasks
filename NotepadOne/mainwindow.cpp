#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QTextStream>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
    ui->statusBar->showMessage("Готово к работе!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_M_Quit_triggered()
{
    close();
}

void MainWindow::on_M_OpenFile_triggered()
{
        fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
            tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

        if (fileName != "") {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
                return;
            }
            QTextStream in(&file);
            ui->textEdit->setText(in.readAll());
            file.close();
        }
    qDebug()<<"Вызван конструктор";
}

void MainWindow::on_M_SaveFile_triggered()
{
    if (fileName.isEmpty()) {
            on_M_SaveAsFile_triggered();
            return;
        }

        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream(&file) << ui->textEdit->toPlainText();
            file.close();
        }

}

void MainWindow::on_M_SaveAsFile_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
        tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

        if (fileName != "") {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                // error message
            } else {
                QTextStream stream(&file);
                stream << ui->textEdit->toPlainText();
                stream.flush();
                file.close();
            }
        }
}



void MainWindow::on_textEdit_textChanged()
{
    QString text = ui->textEdit->toPlainText();
    ui->statusBar->showMessage(QString("Total characters: %1").arg(text.length()));
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

    void on_M_Quit_triggered();
    void on_M_OpenFile_triggered();
    void on_M_SaveAsFile_triggered();
    void on_M_SaveFile_triggered();

    void on_textEdit_textChanged();

private:
    Ui::MainWindow *ui;

    QString fileName;
};

#endif // MAINWINDOW_H

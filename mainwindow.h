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

private:
    Ui::MainWindow *ui;

private slots:
    void on_digitsNumbersButtons_clicked();
    void on_mathOperationsButtons_clicked();
    void on_operationsButtons_clicked();
    void on_pushButton_dot_clicked();
    void on_pushButton_ac_clicked();
    void on_pushButton_equal_clicked();
};

#endif // MAINWINDOW_H

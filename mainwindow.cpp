#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first = 0.0;
double num_second = 0.0;
bool unstable_label = true;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(on_digitsNumbersButtons_clicked()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(on_digitsNumbersButtons_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_digitsNumbersButtons_clicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(on_digitsNumbersButtons_clicked()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(on_digitsNumbersButtons_clicked()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(on_digitsNumbersButtons_clicked()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(on_digitsNumbersButtons_clicked()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(on_digitsNumbersButtons_clicked()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_digitsNumbersButtons_clicked()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(on_digitsNumbersButtons_clicked()));
    connect(ui->pushButton_add_sub, SIGNAL(clicked()), this, SLOT(on_operationsButtons_clicked()));
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(on_operationsButtons_clicked()));
    connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(on_mathOperationsButtons_clicked()));
    connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(on_mathOperationsButtons_clicked()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(on_mathOperationsButtons_clicked()));
    connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(on_mathOperationsButtons_clicked()));

    ui->pushButton_add->setCheckable(true);
    ui->pushButton_sub->setCheckable(true);
    ui->pushButton_div->setCheckable(true);
    ui->pushButton_mul->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_digitsNumbersButtons_clicked()
{
    if(unstable_label)
    {
        ui->result_show->setText("");
        unstable_label = !unstable_label;
    }

    QPushButton *button = (QPushButton *)sender();
    QString new_label = ui->result_show->text();

    if (new_label.length() < 14)
    {
        new_label += button->text();
    }

    ui->result_show->setText(new_label);
}

void MainWindow::on_mathOperationsButtons_clicked()
{
    QPushButton *button = (QPushButton *)sender();
    button->setChecked(true);

    unstable_label = true;

    if (num_first == 0.0)
    {
        num_first = ui->result_show->text().toDouble();
    }
}

void MainWindow::on_operationsButtons_clicked()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers = (ui->result_show->text()).toDouble();

    if (button->text() == "+/-")
    {
        all_numbers *= -1;
    }
    else if (button->text() == "%")
    {
        all_numbers *= 0.01;
    }

    QString new_label = QString::number(all_numbers, 'g', 14);
    ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui->result_show->text().contains('.')))
    {
        ui->result_show->setText(ui->result_show->text() + '.');
    }
}

void MainWindow::on_pushButton_ac_clicked()
{
    ui->result_show->setText("0");
    num_first = 0.0;
    unstable_label = true;
}

void MainWindow::on_pushButton_equal_clicked()
{
    if (num_second == 0.0 && !unstable_label)
    {
        num_second = ui->result_show->text().toDouble();
    }

    if (ui->pushButton_add->isChecked())
    {
        num_first += num_second;
        ui->pushButton_add->setChecked(false);
    }
    else if (ui->pushButton_sub->isChecked())
    {
        num_first -= num_second;
        ui->pushButton_sub->setChecked(false);
    }
    else if (ui->pushButton_div->isChecked())
    {
        num_first = num_second == 0 ? 0 : num_first / num_second;
        ui->pushButton_div->setChecked(false);
    }
    else if (ui->pushButton_mul->isChecked())
    {
        num_first *= num_second;
        ui->pushButton_mul->setChecked(false);
    }
    else
    {
        unstable_label = true;
    }

    QString new_label = QString::number(num_first, 'g', 14);
    ui->result_show->setText(new_label);
    num_second = 0.0;
}

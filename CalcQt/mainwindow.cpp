#include "mainwindow.h"
#include "./ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Калькулятор");

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_plus_minys,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_procent,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->pushButton_multiply,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_divide,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString current_text = ui->result_show->text();

    if (current_text.contains(".") && button->text() == "0") {
        current_text += button->text();
    } else if (current_text == "0" && button->text() != ".") {
        current_text = button->text();
    } else {
        current_text += button->text();
    }

    ui->result_show->setText(current_text);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui->result_show->text().contains('.'))) {
        ui->result_show->setText(ui->result_show->text() + ".");
    }
}

void MainWindow::operations() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString current_text = ui->result_show->text();
    QString new_label;

    if (button->text() == "+/-") {
        double all_numbers = current_text.toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers, 'g', 15);
    } else if (button->text() == "%") {
        double all_numbers = current_text.toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 15);// Установите точность на 4 знака после запятой
    }

    ui->result_show->setText(new_label);
}

void MainWindow::math_operations(){
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    num_first = ui->result_show->text().toDouble();

    ui->result_show->setText("");

    //Set the clicked button to checked
    button->setChecked(true);
    if (button == ui->pushButton_plus) {
        operation = Operation::Plus;
    } else if (button == ui->pushButton_minus) {
        operation = Operation::Minus;
    } else if (button == ui->pushButton_multiply) {
        operation = Operation::Multiply;
    } else if (button == ui->pushButton_divide) {
        operation = Operation::Divide;
    }
}


void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_multiply->setChecked(false);

    ui->result_show->setText("0");
}
void MainWindow::on_pushButton_ravno_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->result_show->text().toDouble();

    switch (operation) {
    case Operation::Plus:
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->result_show->setText(new_label);
        break;
    case Operation::Minus:
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->result_show->setText(new_label);
        break;
    case Operation::Multiply:
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->result_show->setText(new_label);
        break;
    case Operation::Divide:
        if (num_second != 0) {
            labelNumber = num_first / num_second;
            new_label = QString::number(labelNumber, 'g', 15);
            ui->result_show->setText(new_label);
        } else {
            ui->result_show->setText("Error: Division by zero");
        }
        break;
    }

    // Сбрасываем флажки всех кнопок
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);
}


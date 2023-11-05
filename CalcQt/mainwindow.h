#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
enum class Operation {
    Plus,
    Minus,
    Multiply,
    Divide
};
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Operation operation;
    Ui::MainWindow *ui;

private slots:
    void on_pushButton_AC_clicked();
    void on_pushButton_ravno_clicked();
    void digits_numbers();
    void on_pushButton_dot_clicked();
    void operations();
    void math_operations();
};
#endif // MAINWINDOW_H

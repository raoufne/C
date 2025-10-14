#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ArrayOfInteger.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();
    void on_btnRemove_clicked();
    void on_btnShow_clicked();
    void on_btnCompare_clicked();

private:
    Ui::MainWindow *ui;
    ArrayOfInteger arr1;
    ArrayOfInteger arr2;
    void updateOutput();
};

#endif // MAINWINDOW_H

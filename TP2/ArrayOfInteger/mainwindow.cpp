#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Exemple : remplir arr2 avec quelques valeurs
    int vals[] = {1, 2, 3, 4, 5};
    arr2 = ArrayOfInteger(5, vals);
    updateOutput();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateOutput() {
    QString text;
    text += "arr1 = ";
    for (int i = 0; i < arr1.getSize(); i++) {
        text += QString::number(arr1.contains(i) ? i : 0);
    }
    text += "\narr2 = ";
    for (int i = 0; i < arr2.getSize(); i++) {
        text += QString::number(arr2.contains(i) ? i : 0);
    }
    text += QString("\nCompteur = %1").arg(ArrayOfInteger::getCompteur());
    ui->outputBox->setPlainText(text);
}

void MainWindow::on_btnAdd_clicked() {
    bool ok;
    int val = ui->inputNumber->text().toInt(&ok);
    if (ok) {
        arr1.ajouter(val);
        updateOutput();
    }
}

void MainWindow::on_btnRemove_clicked() {
    bool ok;
    int val = ui->inputNumber->text().toInt(&ok);
    if (ok) {
        arr1.retirer(val);
        updateOutput();
    }
}

void MainWindow::on_btnShow_clicked() {
    updateOutput();
}

void MainWindow::on_btnCompare_clicked() {
    bool equal = arr1.egal(arr2);
    ui->outputBox->append(equal ? "arr1 == arr2 ✅" : "arr1 != arr2 ❌");
}

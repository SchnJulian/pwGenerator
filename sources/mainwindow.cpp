#include "mainwindow.h"
#include <QFileDialog>
#include <QGraphicsEffect>
#include <QGraphicsItem>
#include <QMessageBox>
#include "password.h"
#include "ui_mainwindow.h"
#include "csvparser.h"

#include <QString>
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_generateButton_clicked() {
  p.generatePassword(ui->spinBox->value());
  ui->displayPassword->setText(QString::fromStdString(p.getPassword()));
}

void MainWindow::on_hideButton_clicked() {
  if (!hidden) {
    int j = ui->displayPassword->text().count();
    ui->displayPassword->setText("");
    QString s;
    for (int i = 0; i < j; i++) {
      s += "*";
    }
    ui->displayPassword->setText(s);
    hidden = true;
    ui->hideButton->setText("Show");
  } else if (hidden) {
    ui->displayPassword->setText("");
    ui->displayPassword->setText(QString::fromStdString(p.getPassword()));
    hidden = false;
    ui->hideButton->setText("Hide");
  }
}

void MainWindow::on_showButton_clicked() {
  ui->displayPassword->setText(QString::fromStdString(p.getPassword()));
}


void MainWindow::on_upperCaseLetters_stateChanged(int arg1) {
  if (arg1 == 2) {
    p.addToPool(upperCaseLetters);
  } else if (arg1 == 0) {
    p.resetPool();
    updatePool();
  }
}

void MainWindow::on_lowerCaseLetters_stateChanged(int arg1) {
  if (arg1 == 2) {
    p.addToPool(lowerCaseLetters);
  } else if (arg1 == 0) {
    p.resetPool();
    updatePool();
  }
}

void MainWindow::on_numbers_stateChanged(int arg1) {
  if (arg1 == 2) {
    p.addToPool(numbers);
  } else if (arg1 == 0) {
    p.resetPool();
    updatePool();
  }
}

void MainWindow::on_specialCharacters_stateChanged(int arg1) {
  if (arg1 == 2) {
    p.addToPool(specialCharacters);
  } else if (arg1 == 0) {
    p.resetPool();
    updatePool();
  }
}

void MainWindow::updatePool() {
  p.resetPool();
  if (ui->specialCharacters->isChecked()) {
    p.addToPool(specialCharacters);
  }

  if (ui->upperCaseLetters->isChecked()) {
    p.addToPool(upperCaseLetters);
  }

  if (ui->lowerCaseLetters->isChecked()) {
    p.addToPool(lowerCaseLetters);
  }

  if (ui->numbers->isChecked()) {
    p.addToPool(numbers);
  }
}

void MainWindow::on_spinBox_valueChanged(int arg1) {
  ui->passwordLengthSlider->setValue(arg1);

  if (!p.isPoolEmpty()) {
    p.generatePassword(ui->spinBox->value());
  }

  ui->displayPassword->setText(QString::fromStdString(p.getPassword()));
}

void MainWindow::on_testPwBtn_clicked() {
  Dialog* q = new Dialog;
  q->setPassword(p);
  q->show();
}

void MainWindow::on_dataBaseCheckButton_clicked() {
  if (p.databaseCheck() == true) {
    this->passwordFound();
  }
}

void MainWindow::passwordFound() {
  WarningPopup* w = new WarningPopup;
  w->show();
}

void MainWindow::on_passwordLengthSlider_sliderReleased() {
  ui->spinBox->setValue(ui->passwordLengthSlider->value());
}

void MainWindow::on_displayPassword_textEdited(const QString &arg1)
{
    p.setPassword(arg1.toUtf8().constData());
}

void MainWindow::on_opeFileBtn_clicked()
{
  QFileDialog *f = new QFileDialog;
  readData(f->getOpenFileName(this, ("Open File"),"/home",("Tables (*.csv)")).toUtf8().constData());
}

void readData(std::string path){
  std::ifstream f(path);
 csv::CsvParser parser(f);
}


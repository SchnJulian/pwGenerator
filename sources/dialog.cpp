#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget* parent) : QDialog(parent), ui(new Ui::Dialog) {
  ui->setupUi(this);
}

Dialog::~Dialog() {
  delete ui;
}

InfInt Dialog::pow(int v, int n) {
  InfInt ret = 1;
  for (int i = 0; i < n; i++) {
    ret *= v;
  }
  return ret;
}

void Dialog::setPassword(Password password) {
  this->password = password;
  ui->passWordInput->setText(QString::fromStdString(password.getPassword()));
}

void Dialog::on_passWordInput_textChanged(const QString& arg1) {
  this->password.setPassword(arg1.toUtf8().constData());
  this->characters = this->password.getCharacters();
  ui->charCounter->setNum(characters);
  lenght = arg1.length();
  permutations = pow(characters, lenght);
  ui->permutationCount->setText(
      QString::fromStdString(permutations.toString()));
  ui->timeLbl->setText(
      QString::fromStdString(password.timeUnit((permutations / 2) / pwProS)));
}

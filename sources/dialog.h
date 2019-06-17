#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "infint.h"
#include "password.h"

#include <string>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog {
  Q_OBJECT

 public:
  explicit Dialog(QWidget* parent = nullptr);
  ~Dialog();
  void setPassword(Password password);

 private slots:
  void on_passWordInput_textChanged(const QString& arg1);

 private:
  InfInt pwProS = 72000000000;
  InfInt pow(int i, int n);
  InfInt permutations;
  int lenght;
  int characters;
  Ui::Dialog* ui;
  Password password;
};

#endif  // DIALOG_H

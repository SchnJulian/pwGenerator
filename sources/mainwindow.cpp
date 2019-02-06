#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "password.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_generateButton_clicked()
{

 p.generatePassword(ui->passwordLength->value());
  ui->displayPassword->document()->setPlainText(QString::fromStdString(p.getPassword()));
 on_hideButton_clicked();
}

void MainWindow::on_hideButton_clicked()
{
  ui->displayPassword->document()->setPlainText("");
  for(int i = 0; i < p.getPassword().length(); i++){
      ui->displayPassword->moveCursor(QTextCursor::End);
      ui->displayPassword->insertPlainText("*");
      ui->displayPassword->moveCursor(QTextCursor::End);
    }
}

void MainWindow::on_showButton_clicked()
{
  ui->displayPassword->document()->setPlainText(QString::fromStdString(p.getPassword()));
}



void MainWindow::on_passwordLength_sliderMoved(int position)
{
  if(!p.isPoolEmpty()){
      p.generatePassword(ui->passwordLength->value());
    }

ui->spinBox->setValue(position);
  ui->displayPassword->document()->setPlainText(QString::fromStdString(p.getPassword()));
  on_hideButton_clicked();
}

void MainWindow::on_upperCaseLetters_stateChanged(int arg1)
{
  if(arg1 == 2){
      p.addToPool(upperCaseLetters);
    }else if(arg1 == 0){
      p.resetPool();
      updatePool();
    }
}

void MainWindow::on_lowerCaseLetters_stateChanged(int arg1)
{
  if(arg1 == 2){
      p.addToPool(lowerCaseLetters);
    }else if(arg1 == 0){
      p.resetPool();
      updatePool();
    }
}

void MainWindow::on_numbers_stateChanged(int arg1)
{
  if(arg1 == 2){
      p.addToPool(numbers);
    }else if(arg1 == 0){
      p.resetPool();
    updatePool();
    }
}

void MainWindow::on_specialCharacters_stateChanged(int arg1)
{
  if(arg1 == 2){
      p.addToPool(specialCharacters);
    }else if(arg1 == 0){
      p.resetPool();
      updatePool();
    }
}


void MainWindow::updatePool(){
  p.resetPool();
  if(ui->specialCharacters->isChecked()){
      p.addToPool(specialCharacters);
    }

  if(ui->upperCaseLetters->isChecked()){
      p.addToPool(upperCaseLetters);
    }

  if(ui->lowerCaseLetters->isChecked()){
      p.addToPool(lowerCaseLetters);
    }

  if(ui->numbers->isChecked()){
      p.addToPool(numbers);
    }

}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
ui->passwordLength->setValue(arg1);

  if(!p.isPoolEmpty()){
      p.generatePassword(ui->passwordLength->value());
    }
    ui->displayPassword->document()->setPlainText(QString::fromStdString(p.getPassword()));
on_hideButton_clicked();
}

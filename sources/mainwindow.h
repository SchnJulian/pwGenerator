#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <password.h>
namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  Password p;
private:
  std::vector<char> upperCaseLetters = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  std::vector<char> lowerCaseLetters = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  std::vector<char> specialCharacters = {'!','"','#','$','%','&','\'','(',')','*','+','`','-','.','/',':',';','<','=','>','?','@','[','\\',']','^','_'};
  std::vector<char> numbers = {'0','1','2','3','4','5','6','7','8','9'};
  void updatePool();

int l;
private slots:
  void on_generateButton_clicked();

  void on_hideButton_clicked();

  void on_showButton_clicked();

  void on_passwordLength_sliderMoved(int position);

  void on_upperCaseLetters_stateChanged(int arg1);

  void on_lowerCaseLetters_stateChanged(int arg1);

  void on_numbers_stateChanged(int arg1);

  void on_specialCharacters_stateChanged(int arg1);



  void on_spinBox_valueChanged(int arg1);

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

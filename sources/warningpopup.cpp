#include "warningpopup.h"
#include "ui_warningpopup.h"

WarningPopup::WarningPopup(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::WarningPopup)
{
  ui->setupUi(this);
}

WarningPopup::~WarningPopup()
{
  delete ui;
}

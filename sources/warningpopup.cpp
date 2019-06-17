#include "warningpopup.h"
#include "ui_warningpopup.h"

WarningPopup::WarningPopup(QWidget* parent)
    : QDialog(parent), ui(new Ui::WarningPopup) {
  ui->setupUi(this);
  setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
  setParent(0); // Create TopLevel-Widget
  setAttribute(Qt::WA_NoSystemBackground, true);
  setAttribute(Qt::WA_TranslucentBackground, true);
  setAttribute(Qt::WA_PaintOnScreen); // not needed in Qt 5.2 and up
}

WarningPopup::~WarningPopup() {
  delete ui;
}

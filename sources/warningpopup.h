#ifndef WARNINGPOPUP_H
#define WARNINGPOPUP_H

#include <QDialog>

namespace Ui {
  class WarningPopup;
}

class WarningPopup : public QDialog
{
  Q_OBJECT

public:
  explicit WarningPopup(QWidget *parent = nullptr);
  ~WarningPopup();

private:
  Ui::WarningPopup *ui;
};

#endif // WARNINGPOPUP_H

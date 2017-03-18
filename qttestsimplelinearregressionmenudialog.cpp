#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "qttestsimplelinearregressionmenudialog.h"

#include <boost/units/systems/si.hpp>

#include <QDesktopWidget>
#include <QKeyEvent>

#include "simplelinearregression.h"
#include "simplelinearregressionmenudialog.h"
#include "qtaboutdialog.h"
#include "qttestsimplelinearregressionmaindialog.h"
#include "qthideandshowdialog.h"
#include "ui_qttestsimplelinearregressionmenudialog.h"

#pragma GCC diagnostic pop

ribi::QtToolTestSimpleLinearRegressionMenuDialog::QtToolTestSimpleLinearRegressionMenuDialog(
  QWidget *parent) noexcept
  : QtHideAndShowDialog(parent),
    ui(new Ui::QtToolTestSimpleLinearRegressionMenuDialog)
{
  ui->setupUi(this);
}

ribi::QtToolTestSimpleLinearRegressionMenuDialog::~QtToolTestSimpleLinearRegressionMenuDialog() noexcept
{
  delete ui;
}

void ribi::QtToolTestSimpleLinearRegressionMenuDialog::keyPressEvent(
  QKeyEvent * event) noexcept
{
  if (event->key() == Qt::Key_Escape) { close(); return; }
}

void ribi::QtToolTestSimpleLinearRegressionMenuDialog::on_button_about_clicked() noexcept
{
  About a = ToolTestSimpleLinearRegressionMenuDialog().GetAbout();
  a.AddLibrary("QtHideAndShowDialog version: " + QtHideAndShowDialog::GetVersion());
  QtAboutDialog d(a);
  d.setWindowIcon(this->windowIcon());
  d.setStyleSheet(this->styleSheet());
  this->ShowChild(&d);
}

void ribi::QtToolTestSimpleLinearRegressionMenuDialog::on_button_quit_clicked() noexcept
{
  close();
}

void ribi::QtToolTestSimpleLinearRegressionMenuDialog::on_button_start_clicked() noexcept
{
  QtToolTestSimpleLinearRegressionMainDialog d;
  d.setWindowIcon(this->windowIcon());
  d.setStyleSheet(this->styleSheet());
  ShowChild(&d);
}

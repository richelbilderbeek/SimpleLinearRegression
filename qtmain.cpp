#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include <QApplication>

#include "qttestsimplelinearregressionmenudialog.h"
#pragma GCC diagnostic pop

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  ribi::QtToolTestSimpleLinearRegressionMenuDialog d;
  d.show();
  return a.exec();
}

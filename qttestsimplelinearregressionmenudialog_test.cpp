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

void ribi_QtToolTestSimpleLinearRegressionMenuDialog_Test() noexcept
{
  //Let Boost.Units check for compiling
  {
    typedef boost::units::quantity<boost::units::si::time> Time;
    typedef boost::units::quantity<boost::units::si::length> Distance;
    typedef boost::units::quantity<boost::units::si::velocity> Velocity;
    const std::vector<Time> xs
      =
      {
        Time(1.0 * boost::units::si::second),
        Time(2.0 * boost::units::si::second),
        Time(3.0 * boost::units::si::second)
      };
    const std::vector<Distance> ys
      =
      {
        Distance(2.0 * boost::units::si::meter),
        Distance(3.0 * boost::units::si::meter),
        Distance(4.0 * boost::units::si::meter)
      };

    const Velocity expected_slope(1.0 * boost::units::si::meter / boost::units::si::second);
    const Distance expected_offset(1.0 * boost::units::si::meter);

    const std::pair<Velocity,Distance> p
      = SimpleLinearRegression::CalculateBestFit(xs,ys);
    const Velocity slope(p.first);
    const Distance offset(p.second);
    assert(std::abs( Velocity(slope - expected_slope).value() )
      < Velocity(0.0001 * boost::units::si::meter / boost::units::si::second).value() );
    assert(std::abs( Distance(offset - expected_offset).value() )
      < Distance(0.0001 * boost::units::si::meter).value() );

  }
}

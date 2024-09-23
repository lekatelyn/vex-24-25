#include "vex.h"

double Convert::inToDeg(double inch){
  return (inch / (M_PI * Odom::wheelDiam)) * 360;
}

double degToIn (double deg){
  return (deg * Odom::wheelDiam * M_PI) / 360;
}

double Convert::degToRad(double deg){
  return (deg/(180.0/M_PI));
}
#include "vex.h"
using namespace Odom;

// setting up variables
const double Odom::wheelDiam = 2.75; // inches
const double Odom::rightWheelDist = 5;
const double Odom::sideWheelDist = 5;
const double Odom::gearRatio = 0.6; //36:60


double Odom::rightPrevPos = 0;
double Odom::sidePrevPos = 0;
double Odom::prevTheta = 0;

double Odom::deltaRight = 0;
double Odom::deltaSide = 0;
double Odom::deltaTheta = 0;

double Odom::deltaGlobalX = 0;
double Odom::deltaGlobalY = 0;
double Odom::deltaLocalX = 0;
double Odom::deltaLocalY = 0;


double Odom::currentTheta = 0;
double Odom::currentX = 0;
double Odom::currentY = 0;

double Odom::avgTheta = 0;

void Odom::updateEncoders(){
  rightWheelPos = rightWheel.position(deg);
  sideWheelPos = sideWheel.position(deg);
  currentTheta = Convert::degToRad(inert.heading(deg));

  deltaRight = Convert::degToIn(rightWheelPos - rightPrevPos);
  deltaSide = Convert::degToIn(sideWheelPos - sidePrevPos);
  deltaTheta = currentTheta - prevTheta;

  rightPrevPos = rightWheelPos;
  sidePrevPos = sideWheelPos;
  prevTheta = currentTheta;

}

void Odom::updatePos() {
 
  
  if (deltaTheta == 0){
    deltaLocalX = deltaSide;
    deltaLocalY = deltaRight;
  }
  else { 
    double dist = 2 * sin(deltaTheta / 2);
    deltaLocalX = dist * (deltaSide / deltaTheta + sideWheelDist);
    deltaLocalY = dist * (deltaRight / deltaTheta + rightWheelDist);
  }

  avgTheta = currentTheta - (deltaTheta / 2);

  deltaGlobalX = (deltaLocalX * cos(avgTheta)) - (deltaLocalX * sin(avgTheta));
  deltaGlobalY = (deltaLocalY * sin(avgTheta)) + (deltaLocalX * cos(avgTheta));

  currentX += deltaGlobalX;
  currentY += deltaGlobalY;
}


void Odom::printPos(){
  Brain.Screen.printAt(1, 20, "X: %f", currentX);
  Brain.Screen.printAt(1, 40, "Y: %f", currentY);
  Brain.Screen.printAt(1, 60, "Heading: %f", currentTheta);
}

int Odom::Odometry(){
  while (1){
    updateEncoders();
    updatePos();
    printPos();

    this_thread::sleep_for(10);
  }
  return 1;
}
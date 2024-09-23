namespace Odom {
  const extern double wheelDiam;
  const extern double gearRatio;

  const extern double rightWheelDist;
  const extern double sideWheelDist;

  extern double rightWheelPos;
  extern double sideWheelPos;

  extern double rightPrevPos;
  extern double sidePrevPos;

  extern double deltaRight;
  extern double deltaSide;
  extern double deltaTheta;

  extern double currentTheta;
  extern double prevTheta;

  extern double deltaGlobalX;
  extern double deltaGlobalY;
  extern double deltaLocalX;
  extern double deltaLocalY;

  extern double currentX;
  extern double currentY;

  extern double avgTheta;

  extern void updateEncoders();
  extern void updatePos();
  extern void printPos();
  extern int Odometry();


};
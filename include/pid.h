class PID
{
   public:
  
  double error;
  double prevError;
  double motorPower;
  double integral;
  double derivative;
  double reading;
  float kP;
  float kI;
  float kD;

  PID(float ikP, float ikI, float ikD);


  void calculate(float target, double currentRead, float timeout){
    }
  private:


 

};

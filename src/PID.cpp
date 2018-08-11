#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  besterr = 1.0;
}

void PID::UpdateError(double cte) {
  _UpdateError(cte);
}
void PID::_UpdateError(double cte) {
  _cte = cte;
  diff_CTE = cte - prev_CTE;
  prev_CTE = cte;
  int_CTE += cte;
}

void PID::twiddle(double new_cte) {

  p[0] = Kp;
  p[1] = Ki;
  p[2] = Kd;

  if ((p[0] + p[1] + p[2]) > 0.00001) {
    _UpdateError(new_cte);
    for (int i = 0; i < 3; i++) {
      p[i] += dp[i];
      if (_cte < besterr) {
        besterr = _cte;
        p[i] *= 1.1;
      } else {
        p[i] -= 2 * dp[i];
        if (_cte < besterr) {
          besterr = _cte;
          dp[i] *= 1.1;
        } else {
          p[i] += dp[i];
          dp[i] *= 0.9;
        }
      }
    }
    std::cout<< besterr << endl;

    Kp = p[0];
    Ki = p[1];
    Kd = p[2];
    std::cout << "Kp: " << Kp << ", Ki " << Ki << ", Kd " << Kd << std::endl;

  }


}
double PID::TotalError() {
  return -Kp * _cte - Kd * diff_CTE - Ki * int_CTE;
}

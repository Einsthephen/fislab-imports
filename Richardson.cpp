#include <iostream>
#include <cstdio>
#include <cmath>

double f(double x);
double forward_deriv(double x, double h);
double central_deriv(double x, double h);
double richardson_derivcentral(double x, double h);
double richardson_derivFWD(double x, double h);

int main(void)
{
  std::cout.precision(15); std::cout.setf(std::ios::scientific);
  double x = 3.7;
  double dexact = 2*std::cos(2*x);
  for (int ii = 1; ii <= 10; ii++) {
    double h = std::pow(10.0, -ii);
    double df = forward_deriv(x, h);
    double dc = central_deriv(x, h);
    double drc = richardson_derivcentral(x, h);
    double drf = richardson_derivFWD(x, h);
    
    std::cout << h << "\t"
              << fabs(df-dexact/dexact) << "\t"
              << fabs(dc-dexact/dexact) << "\t"
	      << fabs(drf-dexact/dexact) << "\t"
              << fabs(drc-dexact/dexact) << "\n";
  }

  return 0;
}

double f(double x)
{ 
  double resp =sin(2*x);
  return resp;
}

double forward_deriv(double x, double h)
{ 
  double a= f(x+h);
  double b = f(x);
  double resp = (a - b)/h;
  return resp;
}

double central_deriv(double x, double h)
{
  double a= f(x + h/2);
  double b = f(x - h/2);
  double resp = (a - b)/h;
  return resp;
}

double richardson_derivcentral(double x, double h)
{
  double c1 = central_deriv(x, h);
  double c2 = central_deriv(x, h/2);
  double resp= (4*c2 - c1)/3.0;
  return resp;
}

double richardson_derivFWD(double x, double h)
{ 
  double f1 = forward_deriv(x, h);
  double f2 = forward_deriv(x, h/2);
  double resp = (2*f2 - f1);
  return resp;
}

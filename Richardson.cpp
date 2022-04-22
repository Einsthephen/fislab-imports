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
  double h, x, df, dc, drc, drf, dexact;

  x = 3.7;
  for (int ii = 1; ii <= 10; ii++) {
    h = std::pow(10.0, -ii);
    df = forward_deriv(x, h);
    dc = central_deriv(x, h);
    drc = richardson_derivcentral(x, h);
    drf = richardson_derivFWD(x, h);
    dexact = 2*std::cos(2*x);
    std::cout << h << "\t"
              << std::fabs(df-dexact)/dexact << "\t"
              << std::fabs(dc-dexact)/dexact << "\t"
	      << std::fabs(drf-dexact)/dexact << "\t"
              << std::fabs(drc-dexact)/dexact << "\n";

    // std::printf("%25.16e%25.16e%25.16e%25.16e\n", h,
    //             std::fabs(df-dexact)/dexact,
    //             std::fabs(dc-dexact)/dexact,
    //             std::fabs(dr-dexact)/dexact);
  }

  return 0;
}

double f(double x)
{
  return std::sin(2*x);
}

double forward_deriv(double x, double h)
{
  return (f(x+h) - f(x))/h;
}

double central_deriv(double x, double h)
{
  return (f(x + h/2) - f(x - h/2))/h;
}

double richardson_derivcentral(double x, double h)
{
  double c1, c2;
  c1 = central_deriv(x, h);
  c2 = central_deriv(x, h/2);
  return (4*c2 - c1)/3.0;
}

double richardson_derivFWD(double x, double h)
{
  double f1, f2;
  f1 = forward_deriv(x, h);
  f2 = forward_deriv(x, h/2);
  return (2*f2 - f1);
}

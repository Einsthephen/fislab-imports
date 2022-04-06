#include <iostream>
#include <fstream>
#include <cmath>
double sph_value(unsigned n, double x);
int main(int argc, char **argv){
  std::ofstream fout{"data.txt"};
  double dx {0.05};
  int num_steps = 10/dx;
  int num=0;
   for(int i = 0;  i <=num_steps ; i++) {
     double x = i*dx;
     if (num==0){
     fout << x <<"\t "<< sph_value(0, x)<<"\t \t "<< sph_value(1, x) << '\n';
     num= 1;
     }
     else {fout << x <<"\t "<< sph_value(0, x)<<"\t "<< sph_value(1, x) << '\n';}
   }
   fout.close();
    return 0;  
}

double sph_value(unsigned n = 0, double x = 0){
  double value = std::sph_bessel(n , x);
  return value;
}

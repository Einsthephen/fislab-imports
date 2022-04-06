#include <iostream>
#include <fstream> // escribir o leer archivos
#include <cmath>
double sph_value(unsigned n, double x);

int main(int argc, char **argv)
{
  std::ofstream fout{"data.txt"};
   for(double x = 0;  x <= 10; x= x+0.05) {

     fout << x <<"\t"<< sph_value(0, x)<<"   "<< sph_value(1, x) << '\n';

    
  }
   fout.close();
    return 0;  
}

double sph_value(unsigned n = 0, double x = 0){
  //aqui piensas en que va a desarrollar la funcion
  double value = std::sph_bessel(n , x);

  return value;
}


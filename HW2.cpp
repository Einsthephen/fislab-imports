#include <iostream>
#include <fstream> // escribir o leer archivos
#include <cmath>
int sph_function(unsigned n, double x);


int main(int argc, char **argv)//aqui pones la funcion y le cambias variables de acuerdo a lo que necesites, en este caso n siendo el valor variable
{
  std::ofstream fout("data.txt");
  for (int x = 0; x <= 10; x = x + 1){
    
    std::cout << x <<"\t"<< sph_function(0, x)<<"   "<< sph_function(1, x) << '\n';

    fout.close();

  }
  

  return 0;  
}

int sph_function(unsigned n = 0, double x = 0){
  //aqui piensas en que va a desarrollar la funcion
  std::ofstream fout("data.txt");
  std::sph_bessel(n , x);

  four.close();
  return 0;
}


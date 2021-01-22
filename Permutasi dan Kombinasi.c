
#include <stdio.h>
#define size = 4;


int factorial(int n) {
  if (n == 1) return 1;
  else return n * factorial(n - 1);
}

int permutasi(int n, int r ) {
  return factorial(n) / factorial(n - r);
}

int kombinasi(int n, int r ) {
  return factorial(n) / ( factorial(n - r) * factorial(r) );
}

int main() {

  printf("Jumlah Permutasi : %d \n", permutasi( 4, 2 ));
  printf("Jumlah Kombinasi : %d \n", kombinasi( 4, 2 ));
  printf("Factorial : %d \n", factorial(3));
  return 0;
}

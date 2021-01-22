
#include <stdio.h>



int fibonacciCounter(int n) {
  if ( n == 0 ) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    printf("n : %d \n", n);
    return fibonacciCounter(n - 1) + fibonacciCounter(n - 2);
  }

}

int main() {
  fibonacciCounter(5);
  return 0;
}

#include "stats.h"

int factorial(int n){
  int product = 1;
  while(n > 1){
    product *= n--;
  }
  return product;
}

int nchoosek(int n, int k){
  return factorial(n) / (factorial(k) * factorial(n - k));
}

#include <iostream>
#include <string>
#include <assert>

//REQUIRES: n >= 0
//EFFECTS: return n!
int factorial(int n){
  assert(n >= 0);
  int product = 1;
  for(; n > 0; --n){
    product *= n;
  }
  return product;
}

//REQUIRES: n >= k >= 0
//EFFECTS: returns n C k
int nchoosek(int n, int k){
  assert(n >= k && k >= 0);
  return factorial(n) / (factorial(k) * factorial(n - k));
}

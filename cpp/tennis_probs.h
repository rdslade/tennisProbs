#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

//REQUIRES: n >= 0
//EFFECTS: return n!
int factorial(int n);

//REQUIRES: n >= k >= 0
//EFFECTS: returns n C k
int nchoosek(int n, int k);

#endif

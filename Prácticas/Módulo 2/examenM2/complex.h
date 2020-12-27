// -------------------------
// ignore estas dos líneas:
#ifndef COMPLEX
#define COMPLEX
// ------------------------

#include <iostream>

using namespace std;

class complex {
  public:
   double real;
   double img;
};


complex csum(complex, complex);

complex cres(complex, complex);

complex cmul(complex, complex);

complex cdiv(complex, complex);

complex cmod(complex, complex);

void cprint(complex);



// -------------------------
// ignore esta línea:
#endif
// ------------------------

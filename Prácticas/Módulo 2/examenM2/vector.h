// -------------------------
// ignore estas dos líneas:
#ifndef VECTOR
#define VECTOR
// ------------------------

#include <iostream>

using namespace std;

class vector {
  public:
   double x;
   double y;
   double z;
};


vector vsum(vector, vector);

vector vres(vector, vector);

vector vmul(vector, vector);

vector vdiv(vector, vector);

vector vmod(vector, vector);

void vprint(vector);



// -------------------------
// ignore esta línea:
#endif
// ------------------------

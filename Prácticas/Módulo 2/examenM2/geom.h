// -------------------------
// ignore estas dos líneas:
#ifndef GEOM
#define GEOM
// ------------------------

#include <iostream>

using namespace std;

class rectangulo {
  public:
   double x, y;
   double w, h;
};

class circulo {
  public:
   double r;
};

class triangulo {
  public:
   double x, y;
   double w, h;
};

double garea(circulo c);

double garea(rectangulo r);


double garea(triangulo r);

// -------------------------
// ignore esta línea:
#endif
// ------------------------

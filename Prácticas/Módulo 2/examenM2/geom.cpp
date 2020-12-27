#include "geom.h"


// -----------------
double garea (circulo m)
{
   const double pi = 3.1415;
   return pi * m.r * m.r;
}


// -----------------
double garea (rectangulo m)
{
   return m.w * m.h;
}


// -----------------
double garea (triangulo m)
{
   return m.w * m.h/2;
}


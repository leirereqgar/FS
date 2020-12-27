#include "dist.h"


// -----------------
double veuclidea(vector a, vector b)
{
   double vx = a.x - b.x;
   double vy = a.y - b.y;

   vx *= vx;
   vy *= vy;

   return sqrt(vx + vy);
}


// -----------------
double vmanhattan(vector a, vector b)
{
   double v1;
   double v2;
   v1 = fabs(a.x - b.x);
   v2 = fabs(a.y - b.y);

   if (v1 > v2)
      return v1;
   else
      return v2;
}



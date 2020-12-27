#include <iostream>
#include "complex.h"
#include "geom.h"
#include "vector.h"
#include "dist.h"


using namespace std;

int main(void)
{
   vector x;
   vector y;
   complex c;
   
   x.x = 10;
   x.y = 20;
   x.z = 30;

   y.x = 30;
   y.y = 20;
   y.z = 10;

   c.real = 4;
   c.img = 2;
   
   for (int i = 0; i < 100; i ++)
   { 
      circulo cr;
      triangulo tr;   
      vector u;
	double dis;
      
      vector z = vsum(x, y);

      cr.r += x.z + c.real;
      tr.w += y.z + c.img;
      tr.h += y.y + c.img;
      u.x = tr.w;
      u.y = tr.h;
      u.z = c.real; 
      c.real --;
	dis = veuclidea(x,u);
      cout << i << " COMPLEJO: " << "-> Triangulo: " << garea(tr) << "-> Distancia : "<< veuclidea(x,u) <<  endl;
      cprint(c);
      cout << endl;
   } 
  

   return 0;
}

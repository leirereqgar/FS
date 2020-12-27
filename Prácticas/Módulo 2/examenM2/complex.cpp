#include "complex.h"


// -----------------
complex csum(complex a, complex b)
{
   complex c;
   c.real = a.real + b.real;
   c.img = a.img + b.img;
   return c;
}


// -----------------
complex cres(complex a, complex b)
{
   complex c;
   c.real = a.real - b.real;
   c.img = a.img - b.img;
   return c;
}


// -----------------
complex cmul(complex a, complex b)
{
   complex c;
   c.real = a.real * b.real;
   c.img = a.img * b.img;
   return c;
}


// -----------------
complex cdiv(complex a, complex b)
{
   complex c;
   c.real = a.real / b.real;
   c.img = a.img  / b.img;
   return c;
}


// -----------------
complex cmod(complex a, complex b)
{
   complex c;
   c.real = (int) a.real % (int) b.real;
   c.img = (int) a.img  % (int) b.img;
   return c;
}


// -----------------
void cprint(complex c)
{
   cout << c.real << " + " << c.img << "i";
}

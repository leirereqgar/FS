#include "vector.h"


// -----------------
vector vsum(vector a, vector b)
{
   vector v;
   v.x = a.x + b.x;
   v.y = a.y + b.y;
   v.y = a.z + b.z;
   return v;
}


// -----------------
vector vres(vector a, vector b)
{
   vector v;
   v.x = a.x - b.x;
   v.y = a.y - b.y;
   v.y = a.z - b.z;
   return v;
}


// -----------------
vector vmul(vector a, vector b)
{
   vector v;
   v.x = a.x * b.x;
   v.y = a.y * b.y;
   v.y = a.z * b.z;
   return v;
}


// -----------------
vector vdiv(vector a, vector b)
{
   vector v;
   v.x = a.x / b.x;
   v.y = a.y / b.y;
   v.y = a.z / b.z;
   return v;
}


// -----------------
vector vmod(vector a, vector b)
{
   vector v;
   v.x = (int) a.x % (int) b.x;
   v.y = (int) a.y % (int) b.y;
   v.y = (int) a.z % (int) b.z;
   return v;
}


// -----------------
void vprint(vector v)
{
   cout << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

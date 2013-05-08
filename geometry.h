#ifndef _GEOMETRY_H
#define _GEOMETRY_H

#include <cmath>

#define sqr(x) ((x) * (x))
  
template<typename T>
struct point {
  T x, y, z;
    
  point() 
    {}
  point(T x, T y, T z = T()) : x(x), y(y), z(z) 
    {}
};
  
template<typename T>
struct vect {
  T x, y, z;
    
  vect() 
    {}
  vect(T x, T y, T z) : x(x), y(y), z(z)
    {}
  vect(point<T> from, point<T> to)
    {x = to.x - from.x; y = to.y - from.y; z = from.z - to.z;}
  vect(const vect<T>& v)
    {x = v.x; y = v.y; z = v.z;}
    
  double length()
    {return sqrt(sqr(x) + sqr(y) + sqr(z));}
    
  vect<T> operator + (const vect<T>& v) const
    {return vect<T>(x + v.x, y + v.y, z + v.z);}
  vect<T> operator - (const vect<T>& v) const
    {return vect<T>(x - v.x, y - v.y, z - v.z);}
  void operator += (const vect<T>& v)
    {x += v.x; y += v.y; z += v.z;}
  void operator -=(const vect<T>& v)
    {x -= v.x; y -= v.y; z -= v.z;}
      
  bool operator == (const vect<T>& v) const
    {return x == v.x && y == v.y && z == v.z;}
  bool operator != (const vect<T>& v) const
    {return !(*this == v);}
  };
  
template<typename T>
double abs(const vect<T>& a)
  {return a.length();}
  
template<typename T>
T scalar_multiply(const vect<T>& a, const vect<T>& b)
  {return a.x * b.x + a.y * b.y + a.z * b.z;}
    
template<typename T>
vect<T> vector_miltiply(const vect<T>& a, const vect<T>& b)
  {return vect<T>(a.y * b.z - a.z * b.y,
                  a.z * b.x - a.x * b.z,
                  a.x * b.y - a.y * b.x);}
                  
#endif

#pragma once
//Version date 12/7/2021

#include <Math.h>		// just for sqrt()
#define abbs(x) ((x)>=0.0?(x):-(x))		// abs() not defined properly in esp32 library

////////////  Vector3  ////////////
template<class T>
class Vector3 {
public:
  Vector3() {}
  Vector3(T xx, T yy, T zz = 0) {x = xx; y = yy; z= zz; }

  Vector3& operator=(const Vector3& a)  { x  = a.x; y  = a.y; z  = a.z; return *this; }
  Vector3& operator=(T Val)             { x  = Val; y  = Val; z  = Val; return *this; }
  Vector3& operator+=(const Vector3& a) { x += a.x; y += a.y; z += a.z; return *this; }
  Vector3& operator-=(const Vector3& a) { x -= a.x; y -= a.y; z -= a.z; return *this; }
  Vector3& operator*=(float f)          { x *=   f; y *=   f; z *=   f; return *this; }
  Vector3 operator+(const Vector3& b) const { return Vector3(x+b.x, y+b.y, z+b.z); }
  Vector3 operator-(const Vector3& b) const { return Vector3(x-b.x, y-b.y, z-b.z); }
  Vector3 operator*(float f)          const { return Vector3(  x*f,   y*f,   z*f); }
  Vector3 operator/(T Val)            const { return Vector3(x/Val, y/Val, z/Val); }
  T operator[](int n) { return elem[n]; }
  float mag()   const { return sqrt(x*x + y*y + z*z); }
  T magSq() const { return (x*x + y*y + z*z); }
  float magxy() const { return sqrt(x*x + y*y); }
  Vector3 normalised() const { return Vector3(*this * (1/mag())); }
  
  bool isInsideBox(const Vector3& vtBox) { return (abbs(x) <= vtBox.x) && (abbs(y) <= vtBox.y) && (abbs(z) <= vtBox.z); }
  void stretchBox(Vector3& vtBox) {
    if (abbs(x) > vtBox.x)
      vtBox.x = abbs(x);
    if (abbs(y) > vtBox.y)
      vtBox.y = abbs(y);
    if (abbs(z) > vtBox.z)
      vtBox.z = abbs(z);
  }
  T volume() const { return abbs(x * y * z); }
  T boxVolume() const { return 8 * volume(); }
  void stretchMin(Vector3& vtMin) {
    if (x < vtMin.x)
      vtMin.x = x;
    if (y < vtMin.y)
      vtMin.y = y;
    if (z < vtMin.z)
      vtMin.z = z;
  }
  void stretchMax(Vector3& vtMax) {
    if (x > vtMax.x)
      vtMax.x = x;
    if (y > vtMax.y)
      vtMax.y = y;
    if (z > vtMax.z)
      vtMax.z = z;
  }

public:
  union {
    T elem[3];
    struct { T x, y, z; };
  };
};



////////////  Vector2  ////////////
template<class T>
class Vector2 {
public:
  Vector2() {}
  Vector2(T xx, T yy) {x = xx; y = yy; }

  Vector2& operator=(const Vector2& a)  { x  = a.x; y  = a.y; return *this; }
  Vector2& operator=(T Val)             { x  = Val; y  = Val; return *this; }
  Vector2& operator+=(const Vector2& a) { x += a.x; y += a.y; return *this; }
  Vector2& operator-=(const Vector2& a) { x -= a.x; y -= a.y; return *this; }
  Vector2& operator*=(float f)          { x *=   f; y *=   f; return *this; }
  Vector2 operator+(const Vector2& b) const { return Vector2(x+b.x, y+b.y); }
  Vector2 operator-(const Vector2& b) const { return Vector2(x-b.x, y-b.y); }
  Vector2 operator*(float f)          const { return Vector2(  x*f,   y*f); }
  Vector2 operator/(T Val)            const { return Vector2(x/Val, y/Val); }
  T operator[](int n) { return elem[n]; }
  float mag()   const { return sqrt(x*x + y*y); }
  T magSq() const { return (x*x + y*y); }
  float magxy() const { return sqrt(x*x + y*y); }
  Vector2 normalised() const { return Vector2(*this * (1/mag())); }
  
  bool isInsideBox(const Vector2& vtBox) { return (abbs(x) <= vtBox.x) && (abbs(y) <= vtBox.y); }
  void stretchBox(Vector2& vtBox) {
    if (abbs(x) > vtBox.x)
      vtBox.x = abbs(x);
    if (abbs(y) > vtBox.y)
      vtBox.y = abbs(y);
  }
  T area() const { return abbs(x * y); }
  T boxArea() const { return 4 * area(); }
  void stretchMin(Vector2& vtMin) {
    if (x < vtMin.x)
      vtMin.x = x;
    if (y < vtMin.y)
      vtMin.y = y;
  }
  void stretchMax(Vector2& vtMax) {
    if (x > vtMax.x)
      vtMax.x = x;
    if (y > vtMax.y)
      vtMax.y = y;
  }

public:
  union {
    T elem[2];
    struct { T x, y; };
  };
};


typedef Vector3<float> Vector3f;
typedef Vector3<int> Vector3i;

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;

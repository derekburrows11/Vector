#ifndef _Vector3Txf_h_
#define _Vector3Txf_h_
//Version date 15/5/2021

#include "Vector3.h"

class Vector3Txf {
public:
  Vector3Txf() {}
  void zeros() { for (int i = 0; i < 9; i++) elemN[i] = 0; }
  void identity() { zeros(); xx = 1; yy = 1; zz= 1; }
  void rotateX(float ang) {
	zeros();
	yy =  cos(ang);
	yz = -sin(ang);
	zy =  sin(ang);
	zz =  cos(ang);
	xx = 1;
  }
  void rotateY(float ang) {
	zeros();
	zz =  cos(ang);
	zx = -sin(ang);
	xz =  sin(ang);
	xx =  cos(ang);
	yy = 1;
  }
  void rotateZ(float ang) {
	zeros();
	xx =  cos(ang);
	xy = -sin(ang);
	yx =  sin(ang);
	yy =  cos(ang);
	zz = 1;
  }
  
  float& operator[](int n) { return elemN[n]; }
  Vector3 operator*(const Vector3& b) {
	  return Vector3(xx*b.x + xy*b.y + xz*b.z, yx*b.x + yy*b.y + yz*b.z, zx*b.x + zy*b.y + zz*b.z); }
  Vector3Txf operator*(const Vector3Txf& b) {
	Vector3Txf res;
	for (int i=0; i<3; i++)
	  for (int j=0; j<3; j++)
		res.elem[i][j] = elem[i][0]*b.elem[0][j] + elem[i][1]*b.elem[1][j] + elem[i][2]*b.elem[2][j];
	return res;
  }


public:
  union {
    float elemN[9];
	float elem[3][3];
    struct { float xx, xy, xz, yx, yy, yz, zx, zy, zz; };
  };
};





#endif

///
/// \file vec2.cpp
/// \brief 2D matrix class
/// \author Joshua A. Levine <josh@email.arizona.edu>
/// \date 10/08/18
///
/// This code defines a simple matrix2x2 class with some of the basic 
/// operations for arithmetic and utility functions.  It builds on the
/// two-dimensional vector class vec2.h
///


/*
 ***********************************************************************
 
 Copyright (C) 2018, Joshua A. Levine
 University of Arizona
 
 Permission is hereby granted, free of charge, to any person obtaining
 a copy of this software and associated documentation files (the
 "Software"), to deal in the Software without restriction, including
 without limitation the rights to use, copy, modify, merge, publish,
 distribute, sublicense, and/or sell copies of the Software, and to
 permit persons to whom the Software is furnished to do so, subject to
 the following conditions:
 
 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 
 ***********************************************************************
 */

#include "matrix2x2.h"

#include <cmath>
#include <cstdio>

matrix2x2::matrix2x2() {
  data[0] = vec2();
  data[1] = vec2();
}

matrix2x2::matrix2x2(const float* m) {
  data[0][0] = m[0];
  data[0][1] = m[1];
  data[1][0] = m[2];
  data[1][1] = m[3];
}



matrix2x2::matrix2x2(const matrix2x2& m) {
  data[0] = m[0];
  data[1] = m[1];
}

matrix2x2& matrix2x2::operator=(const matrix2x2& rhs) {
  data[0] = rhs[0];
  data[1] = rhs[1];

  return *this;
}




vec2& matrix2x2::operator[](int row) {
  return data[row];
}

vec2 matrix2x2::operator[](int row) const {
  return data[row];
}


matrix2x2 matrix2x2::transpose() const {
  matrix2x2 out;

  out.data[0] = vec2(data[0][0], data[1][0]);
  out.data[1] = vec2(data[0][1], data[1][1]);

  return out;
}

void matrix2x2::identity() {
  data[0] = vec2(1,0);
  data[1] = vec2(0,1);
}

void matrix2x2::clear() {
  data[0] = vec2(0,0);
  data[1] = vec2(0,0);
}



matrix2x2 matrix2x2::operator+(const matrix2x2& m) const {
  matrix2x2 out;
  
  out.data[0] = data[0] + m.data[0];
  out.data[1] = data[1] + m.data[1];

  return out;
}

matrix2x2 matrix2x2::operator-(const matrix2x2& m) const {
  matrix2x2 out;

  out.data[0] = data[0] - m.data[0];
  out.data[1] = data[1] - m.data[1];

  return out;
}

matrix2x2 matrix2x2::operator-() const {
  matrix2x2 out;

  out.data[0] = -data[0];
  out.data[1] = -data[1];

  return out;
}

matrix2x2 matrix2x2::operator*(const float f) const {
  matrix2x2 out;

  out.data[0] = data[0]*f;
  out.data[1] = data[1]*f;

  return out;
}
    
matrix2x2 operator*(const float f, const matrix2x2& m) {
  return m*f;
}

matrix2x2 matrix2x2::operator/(const float f) const {
  matrix2x2 out;

  out.data[0] = data[0]/f;
  out.data[1] = data[1]/f;

  return out;
}



vec2 matrix2x2::operator*(const vec2& v) const {
  vec2 out;
  out[0] = (*this)[0].dot(v);
  out[1] = (*this)[1].dot(v);

  return out;
}


matrix2x2 matrix2x2::operator*(const matrix2x2& m) const {
  matrix2x2 out;
  matrix2x2 T = m.transpose();

  out.data[0][0] = (*this)[0].dot(T[0]);
  out.data[0][1] = (*this)[0].dot(T[1]);

  out.data[1][0] = (*this)[1].dot(T[0]);
  out.data[1][1] = (*this)[1].dot(T[1]);

  return out;
}



matrix2x2::operator std::string() const {
  std::string str = (*this)[0];
  str = str + "\n" + (std::string) (*this)[1];
  return str;
}

std::ostream& operator<<(std::ostream& os, const matrix2x2& m)  
{  
    os << (std::string) m; 
    return os;  
} 

///
/// \file vec2.cpp
/// \brief 2D vector class
/// \author Joshua A. Levine <josh@email.arizona.edu>
/// \date 10/08/18
///
/// This code defines a simple vec2 class with some of the basic 
/// operations for arithmetic and utility functions. 
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

#include "vec2.h"
#include <cmath>
#include <cstdio>


vec2::vec2() {
  data[0] = data[1] = 0;
}
  
vec2::vec2(float x, float y) {
  data[0] = x;
  data[1] = y;
}

vec2::vec2(const float* v) {
  data[0] = v[0];
  data[1] = v[1];
}



vec2::vec2(const vec2& v) {
  data[0] = v.data[0];
  data[1] = v.data[1];
}

vec2& vec2::operator=(const vec2& rhs){
  data[0] = rhs.data[0];
  data[1] = rhs.data[1];
  return *this;
}


float& vec2::operator[](int dim) {
  return data[dim];
}

float vec2::operator[](int dim) const {
  return data[dim];
}

float vec2::x() {
  return data[0];
}

float vec2::y() {
  return data[1];
}




float vec2::sum() {
  return data[0]+data[1];
}

float vec2::length() {
  return sqrt(squared_length());
}

float vec2::squared_length() {
  return dot(*this);
}

void vec2::normalize() {
  float len = length();
  if (len != 0) {
    data[0] /= len;
    data[1] /= len;
  }
}

vec2 vec2::normalized() {
  vec2 out = *this;
  float len = length();
  if (len != 0) {
    out[0] /= len;
    out[1] /= len;
  }

  return out;
}



vec2 vec2::operator+(const vec2& v) const {
  vec2 out;
  out.data[0] = data[0] + v.data[0];
  out.data[1] = data[1] + v.data[1];

  return out;
}

vec2 vec2::operator-(const vec2& v) const {
  vec2 out;
  out.data[0] = data[0] - v.data[0];
  out.data[1] = data[1] - v.data[1];

  return out;
}

vec2 vec2::operator-() const {
  vec2 out;
  out.data[0] = -data[0];
  out.data[1] = -data[1];

  return out;
}

vec2 vec2::operator*(const float f) const {
  vec2 out;
  out.data[0] = data[0]*f;
  out.data[1] = data[1]*f;

  return out;
}

vec2 operator*(const float f, const vec2& v) {
  return v*f;
}


vec2 vec2::operator/(const float f) const {
  vec2 out;
  out.data[0] = data[0]/f;
  out.data[1] = data[1]/f;

  return out;
}



float vec2::dot(const vec2& v) const {
  return data[0]*v.data[0] + data[1]*v.data[1];
}





vec2::operator std::string() const {
  char strvec[128];
  sprintf(strvec, "(%.2e,%.2e)", data[0], data[1]);
  return std::string(strvec);
}

std::ostream& operator<<(std::ostream& os, const vec2& v)  
{  
  os << (std::string) v; 
  return os;  
} 

std::istream& operator>>(std::istream& is, vec2& v)  
{ 
  is >> v.data[0] >> v.data[1];
  return is;  
} 






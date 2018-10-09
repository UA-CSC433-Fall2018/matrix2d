///
/// \file vec2.h
/// \brief 2D vector class
/// \author Joshua A. Levine <josh@email.arizona.edu>
/// \date 10/08/18
///
/// This code declares a simple vec2 class with some of the basic 
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

#pragma once

#include <string>
#include <iostream>

class vec2 {
  public:
    vec2();
    vec2(float x, float y);
    vec2(const float* v);

    //copy constructor and assignment operator
    vec2(const vec2& v);
    vec2& operator=(const vec2& rhs);

    //index operator and get members
    float& operator[](int dim);
    float operator[](int dim) const;
    float x();
    float y();

    //special functions
    float sum();
    float length();
    float squared_length();
    void normalize();
    vec2 normalized();

    //arithmetic
    vec2 operator+(const vec2& v) const;
    vec2 operator-(const vec2& v) const;
    vec2 operator-() const;
    vec2 operator*(const float f) const;
    friend vec2 operator*(const float f, const vec2& v);
    vec2 operator/(const float f) const;
    float dot(const vec2& v) const;

    //string/printing
    operator std::string() const;
    friend std::ostream& operator<<(std::ostream& os, const vec2& v);
    friend std::istream& operator>>(std::istream& is, vec2& v);

  private:
    float data[2];
};





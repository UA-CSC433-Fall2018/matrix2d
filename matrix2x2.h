///
/// \file vec2.cpp
/// \brief 2D matrix class
/// \author Joshua A. Levine <josh@email.arizona.edu>
/// \date 10/08/18
///
/// This code declares a simple matrix2x2 class with some of the basic 
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


#pragma once

#include "vec2.h"

#include <string>
#include <iostream>


class matrix2x2 {
  public:
    matrix2x2();
    matrix2x2(const float* m);

    //copy constructor and assignment operator
    matrix2x2(const matrix2x2& m);
    matrix2x2& operator=(const matrix2x2& rhs);

    //get/set through indexing to vectors
    vec2& operator[](int row);
    vec2 operator[](int row) const;

    //special functions
    //returns a copy of the matrix as transposed
    matrix2x2 transpose() const;
    //these are inplace adjustments
    void identity();
    void clear();

    //arithmetic
    matrix2x2 operator+(const matrix2x2& m) const;
    matrix2x2 operator-(const matrix2x2& m) const;
    matrix2x2 operator-() const;
    matrix2x2 operator*(const float f) const;
    friend matrix2x2 operator*(const float f, const matrix2x2& m);
    matrix2x2 operator/(const float f) const;
    
    //matrix-vector and matrix-vector operations
    vec2 operator*(const vec2& v) const;
    matrix2x2 operator*(const matrix2x2& m) const;
    
    //string/printing
    operator std::string() const;
    friend std::ostream& operator<<(std::ostream& os, const matrix2x2& m);

  private:
    vec2 data[2];
};

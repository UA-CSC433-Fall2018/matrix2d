///
/// \file main.cpp
/// \brief 2x2 matrix class example code
/// \author Joshua A. Levine <josh@email.arizona.edu>
/// \date 10/8/18
///
/// This code tests out our 2D vector and matrix class
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
#include <iostream>

#include "matrix2x2.h"

int main(int argc, char** argv) {

  vec2 a(1,0);
  vec2 b(0,1);

  std::cout << "b: " << b << std::endl;

  b[0] = 3;

  std::cout << "b: " << b << std::endl;

  matrix2x2 A;
  A.identity();

  std::cout << "A: " << std::endl << A << std::endl;

  A[0][0] = 5;
  
  std::cout << "A: " << std::endl << A << std::endl;
  std::cout << "A*a: " << std::endl << A*a << std::endl;

  matrix2x2 B;
  B[0][0] = 1;
  B[0][1] = 2;
  B[1][0] = 3;
  B[1][1] = 4;
  
  std::cout << "B: " << std::endl << B << std::endl;
  std::cout << "B^T: " << std::endl << B.transpose() << std::endl;
  std::cout << "A*B: " << std::endl << A*B << std::endl;

  return 0;
}

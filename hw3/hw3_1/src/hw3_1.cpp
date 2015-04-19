////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-1                              //
// hw3_1.cpp                                                                  //
// The main functions                                                         //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "hw3_1.hpp"
#include "token.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace hw3;
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Main function                                                              //
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char *argv[] ) {
  Token eight(8);
  Token mul(kMultiplication);
  Token div(kDivision);

  cout << kBitwiseAND << endl;
  cout << eight << mul << div << endl;
}

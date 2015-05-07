////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 4                                //
// hw4_1.cpp                                                                  //
// The main functions                                                         //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "hw4.hpp"
#include "sample.hpp"
#include "sample_set.hpp"
using namespace hw4;
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Main function                                                              //
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char *argv[] ) {
  SampleSet set;
  ifstream fin;

  // Load sample set from file
  fin.open(argv[1]);
  fin >> set;
  fin.close();

  // Display sample set
  cout << set;

  return 0;
}

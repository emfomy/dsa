////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 5                                //
// system.cpp                                                                 //
// The main functions                                                         //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "computer.hpp"
using namespace std;
using namespace hw5;

////////////////////////////////////////////////////////////////////////////////
// Main function                                                              //
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char *argv[] ) {
  int c; // the number of computers in the system
  int w; // the workload judging parameter for merging

  ios::sync_with_stdio(false);

  // Get parameters
  cin >> c >> w;

  // Create computers
  auto computer = new Computer[c];

  // Read commands
  string str;
  while ( cin >> str ) {
    if ( str == "assign" ) {
      Assign(computer);
    } else if ( str == "execute" ) {
      Execute(computer);
    } else if ( str == "merge" ) {
      Merge(computer, w);
    }
  }

  // Delete computers
  delete[] computer;

  return 0;
}

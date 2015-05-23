////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 5                                //
// system.cpp                                                                 //
// The main functions                                                         //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "binomial_heap.hpp"
using namespace std;
using namespace hw5;

////////////////////////////////////////////////////////////////////////////////
// Main function                                                              //
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char *argv[] ) {
  BinomialHeap<int> bh;
  bh.Insert(4);
  bh.Insert(2);
  bh.Insert(3);
  bh.Insert(1);
  cout << bh.Pop() << endl;
  cout << bh.Pop() << endl;
  bh.Insert(8);
  bh.Insert(3);
  bh.Insert(2);
  bh.Insert(3);
  cout << bh.Pop() << endl;
  cout << bh.Pop() << endl;
  cout << bh.Pop() << endl;
  cout << bh.Pop() << endl;
  cout << bh.Pop() << endl;
  cout << bh.Pop() << endl;

  return 0;
}

////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 4                                //
// hw4_1.cpp                                                                  //
// The main functions                                                         //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "hw4.hpp"
#include "sample.hpp"
using namespace hw4;
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Main function                                                              //
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char *argv[] ) {
  int num_features, idx_ds[kMaxFeatures], idx_sd[kMaxFeatures];
  vector<Sample> sample;
  string str;
  ifstream fin;

  // Initialize index array
  num_features = 0;
  for ( int i = 0; i < kMaxFeatures; i++ ) {
    idx_ds[i] = -1;
  }

  // Load sample from file
  fin.open(argv[1]);
  while ( getline(fin, str) ) {
    sample.emplace_back(str, num_features, idx_ds, idx_sd);
  }
  fin.close();

  // Display sample
  for ( auto it = sample.cbegin(); it != sample.cend(); ++it ) {
    cout << (it->label_ ? "+1 " : "-1 ");
    for ( int i = 0; i < kMaxFeatures; i++ ) {
      int id = idx_ds[i];
      if ( id != -1 && it->features_[id] ) {
        cout << i+1 << ':' << it->features_[id] << ' ';
      }
    }
    cout << endl;
  }

  return 0;
}

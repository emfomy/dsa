////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 4                                //
// sample.cpp                                                                 //
// The class Sample                                                           //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "sample.hpp"
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// The namespace hw4                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw4 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of Sample                                                  //
// Initialize by a string object                                              //
//                                                                            //
// Parameters:                                                                //
// str:       the string object                                               //
// num_trees: the number of trees                                             //
// idx_size:  the size of index array                                         //
// idx_ds:    the index maps dense features to sparse features                //
// idx_sd:    the index maps sparse features to dense features                //
////////////////////////////////////////////////////////////////////////////////
Sample::Sample( const string& str, const int num_trees, int& idx_size,
                int (&idx_ds)[kMaxFeatures+1], int (&idx_sd)[kMaxFeatures] ) {
  char *cstr, *tmp;
  int id;

  // Convert string
  cstr = new char[str.size()+1];
  strncpy(cstr, str.c_str(), str.size()+1);

  // Get label
  tmp = strtok(cstr, " ");
  this->label_ = atoi(tmp);
  tmp = strtok(NULL, ":");

  // Get features
  memset(this->features_, 0.0, sizeof(this->features_));
  while ( tmp != NULL ) {
    id = atoi(tmp);
    if ( idx_ds[id] == kNull ) {
      idx_ds[id] = idx_size;
      idx_sd[idx_size] = id;
      ++idx_size;
    }
    tmp = strtok(NULL, " ");
    this->features_[idx_ds[id]] = atof(tmp);
    tmp = strtok(NULL, ":");
  }

  // Initialize node IDs
  this->id_ = new int[num_trees];
  for ( auto i = 0; i < num_trees; i++ ) {
    this->id_[i] = 1;
  }

  // Delete objects
  delete[] cstr;
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of Sample                                                   //
////////////////////////////////////////////////////////////////////////////////
Sample::~Sample() {
  delete[] this->id_;
}

}

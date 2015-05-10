////////////////////////////////////////////////////////////////////////////////
// SampleSet Structures and Algorithms - Homework 4                           //
// sample_set.cpp                                                             //
// The class SampleSet                                                        //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "sample_set.hpp"
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// The namespace hw4                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw4 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of SampleSet                                               //
////////////////////////////////////////////////////////////////////////////////
SampleSet::SampleSet() {
  memset(this->idx_ds_, kNull, sizeof(this->idx_ds_));
}

////////////////////////////////////////////////////////////////////////////////
// The constructor of SampleSet                                               //
//                                                                            //
// Parameters:                                                                //
// num_trees: the number of trees                                             //
////////////////////////////////////////////////////////////////////////////////
SampleSet::SampleSet( const int num_trees ) {
  memset(this->idx_ds_, kNull, sizeof(this->idx_ds_));
  this->num_trees_ = num_trees;
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of SampleSet                                                //
////////////////////////////////////////////////////////////////////////////////
SampleSet::~SampleSet() {
  for ( auto it = this->samples_.begin(); it != this->samples_.end(); ++it ) {
    delete (*it);
  }
}

////////////////////////////////////////////////////////////////////////////////
// Extract a sample set object from stream                                    //
//                                                                            //
// Parameters:                                                                //
// is:  the istream object                                                    //
// set: the sample set object where the extracted content is stored           //
//                                                                            //
// Return Value:                                                              //
// the istream object                                                         //
////////////////////////////////////////////////////////////////////////////////
istream& operator>>( istream& is, SampleSet& set ) {
  // Load sample
  string str;
  while ( getline(is, str) ) {
    auto ptr = new Sample(str, set.num_trees_, set.num_features_,
                          set.idx_ds_, set.idx_sd_);
    set.samples_.emplace_back(ptr);
  }
  set.num_samples_ = set.samples_.size();
  return is;
}

}

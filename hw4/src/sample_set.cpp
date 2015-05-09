////////////////////////////////////////////////////////////////////////////////
// SampleSet Structures and Algorithms - Homework 4                           //
// sample_set.cpp                                                             //
// The class SampleSet                                                        //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "sample_set.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw4                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw4 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of SampleSet                                               //
////////////////////////////////////////////////////////////////////////////////
SampleSet::SampleSet() {
  for ( int i = 0; i < kMaxFeatures; i++ ) {
    this->idx_ds_[i] = -1;
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
std::istream& operator>>( std::istream& is, SampleSet& set ) {
  // Load sample
  std::string str;
  while ( std::getline(is, str) ) {
    auto ptr = new Sample(str, set.num_features_, set.idx_ds_, set.idx_sd_);
    set.samples_.emplace_back(ptr);
  }
  set.num_samples_ = set.samples_.size();
  return is;
}

}

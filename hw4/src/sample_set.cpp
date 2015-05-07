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
  this->num_features_ = 0;
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
    set.samples_.emplace_back(str, set.num_features_, set.idx_ds_, set.idx_sd_);
  }
  return is;
}

////////////////////////////////////////////////////////////////////////////////
// Insert a sample set object into stream                                     //
//                                                                            //
// Parameters:                                                                //
// os:  the ostream object                                                    //
// set: the sample set object to be inserted into the stream                  //
//                                                                            //
// Return Value:                                                              //
// the ostream object                                                         //
////////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<( std::ostream& os, const SampleSet& set ) {
  for ( auto it = set.samples_.cbegin(); it != set.samples_.cend(); ++it ) {
    os << (it->label_ ? "+1 " : "-1 ");
    for ( int i = 0; i < kMaxFeatures; i++ ) {
      int id = set.idx_ds_[i];
      if ( id != -1 && it->features_[id] ) {
        os << i+1 << ':' << it->features_[id] << ' ';
      }
    }
    os << std::endl;
  }
  return os;
}

}

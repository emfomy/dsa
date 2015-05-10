////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 4                                //
// sample_set.hpp                                                             //
// The header file of SampleSet                                               //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW4_SAMPLE_SET_HPP_

#define HW4_SAMPLE_SET_HPP_

#include <iostream>
#include <string>
#include "hw4.hpp"
#include "sample.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw4                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw4 {

class Tree;

////////////////////////////////////////////////////////////////////////////////
// The class of a sample set                                                  //
////////////////////////////////////////////////////////////////////////////////
class SampleSet {
  friend class Tree;

 private:
  // The vector of samples
  SampleVector samples_;

  // The number of features
  int num_features_ = 0;

  // The number of features
  int num_samples_ = 0;

  // The number of trees
  int num_trees_ = 1;

  // the index maps dense features to sparse features
  int idx_ds_[kMaxFeatures+1];

  // the index maps dense features to sparse features
  int idx_sd_[kMaxFeatures];

 public:
  SampleSet();
  SampleSet( const int );
  ~SampleSet();
  friend std::istream& operator>>( std::istream&, SampleSet& );
  friend std::ostream& operator<<( std::ostream&, const SampleSet& );
};

}

#endif

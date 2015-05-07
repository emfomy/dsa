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

////////////////////////////////////////////////////////////////////////////////
// The class of a sample set                                                  //
////////////////////////////////////////////////////////////////////////////////
class SampleSet {
 private:
  // The vector of samples
  SampleVector samples_;

  // The number of features
  int num_features_;

  // the index maps dense features to sparse features
  // Note that dense index should be subtracted by 1
  int idx_ds_[kMaxFeatures];

  // the index maps dense features to sparse features
  // Note that dense index should be subtracted by 1
  int idx_sd_[kMaxFeatures];

 public:
  SampleSet();
  friend std::istream& operator>>( std::istream&, SampleSet& );
  friend std::ostream& operator<<( std::ostream&, const SampleSet& );
};

}

#endif

////////////////////////////////////////////////////////////////////////////////
// Sample Structures and Algorithms - Homework 4                              //
// sample.hpp                                                                 //
// The header file of Sample                                                  //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW4_SAMPLE_HPP_

#define HW4_SAMPLE_HPP_

#include <cstring>
#include <cstdlib>
#include <string>
#include "hw4.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw4                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw4 {

class Sample {
 public:
  // The label of this sample.
  bool label_;

  // The features of this sample.
  double features_[kMaxFeatures];

 public:
  Sample( std::string&, int&, int(&)[kMaxFeatures], int(&)[kMaxFeatures] );
};

}

#endif

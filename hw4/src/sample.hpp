////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 4                                //
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
#include <vector>
#include "hw4.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw4                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw4 {

class SampleSet;
class Node;
class Tree;

////////////////////////////////////////////////////////////////////////////////
// The class of a sample                                                      //
////////////////////////////////////////////////////////////////////////////////
class Sample {
  friend class SampleSet;
  friend class Node;
  friend class Tree;

 private:
  // The label of this sample.
  int label_;

  // The features of this sample.
  double features_[kMaxFeatures];
  
  // The ID of the node this sample belongs to
  int* id_;

 public:
  Sample( const std::string&, const int, int&,
          int(&)[kMaxFeatures+1], int(&)[kMaxFeatures] );
  ~Sample();
  friend std::ostream& operator<<( std::ostream&, const SampleSet& );
};

////////////////////////////////////////////////////////////////////////////////
// The pointer vector of Sample                                               //
////////////////////////////////////////////////////////////////////////////////
typedef std::vector<Sample*> SampleVector;

}

#endif

////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 4                                //
// forest.hpp                                                                   //
// The header file of Forest                                                  //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW4_FOREST_HPP_

#define HW4_FOREST_HPP_

#include <algorithm>
#include "hw4.hpp"
#include "tree.hpp"
#include "sample_set.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw4                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw4 {

////////////////////////////////////////////////////////////////////////////////
// The class of a forest                                                      //
////////////////////////////////////////////////////////////////////////////////
class Forest {
 private:
  // The trees
  TreeVector trees_;

  // The number of trees
  int num_trees_;

 public:
  Forest( const SampleSet& set, const int );
  ~Forest();
  void Print( const int );
  void PrintTrees();
};

}

#endif

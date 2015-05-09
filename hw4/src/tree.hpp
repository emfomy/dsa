////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 4                                //
// tree.hpp                                                                   //
// The header file of Tree                                                    //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW4_TREE_HPP_

#define HW4_TREE_HPP_

#include <algorithm>
#include "hw4.hpp"
#include "node.hpp"
#include "sample.hpp"
#include "sample_set.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw4                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw4 {

////////////////////////////////////////////////////////////////////////////////
// The class of a tree                                                        //
////////////////////////////////////////////////////////////////////////////////
class Tree {
 private:
  // The root of this tree
  Node* root_;

 public:
  Tree( const SampleSet&, const double );
  ~Tree();

  void Print( const int );
};

}

#endif

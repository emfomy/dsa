////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 4                                //
// node.hpp                                                                   //
// The header file of Node                                                    //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW4_NODE_HPP_

#define HW4_NODE_HPP_

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "hw4.hpp"
#include "sample.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw4                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw4 {

class Tree;

////////////////////////////////////////////////////////////////////////////////
// The class of a node                                                        //
////////////////////////////////////////////////////////////////////////////////
class Node {
  friend class Tree;

 private:
  // The dense index of the feature of this node
  // 'NULL' means this node is a leaf
  int idx_d_ = kNull;

  // The threshold of this node
  double threshold_;

  // the label of this node
  // '0' means random output
  int label_ = 0;

  // The left child of this node
  Node* left_ = nullptr;

  // The right child of this node
  Node* right_ = nullptr;

 public:
  Node( const int, const int, SampleVector*, const double,
        const int, const int, const int, const int, const int* );
  ~Node();
  void Print( const int );

 private:
  inline double Confusion( const double, const double );
  inline double Confusion( const double, const double,
                           const double, const double );
};

}

#endif

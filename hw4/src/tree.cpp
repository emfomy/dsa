////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 4                                //
// tree.cpp                                                                   //
// The class Tree                                                             //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "tree.hpp"
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// The namespace hw4                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw4 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of Tree                                                    //
// Initialize by a sample set                                                 //
//                                                                            //
// Parameters:                                                                //
// set:       the sample set                                                  //
// tolerance: the tolerance of confusion                                      //
////////////////////////////////////////////////////////////////////////////////
Tree::Tree( const SampleSet& set, const double tolerance ) {
  int num_features = set.num_features_;

  // Initialize sample matrix
  SampleVector* matrix = new SampleVector[num_features+1];
  for ( auto i = 0; i < num_features; ++i ) {
    auto& vector = matrix[i];

    // Import samples
    vector = set.samples_;

    // Sort samples
    auto func = [&i](Sample* x, Sample* y)->
                bool{return (x->features_[i] < y->features_[i]);};
    sort(vector.begin(), vector.end(), func);
  }
  matrix[num_features].resize(set.samples_.size(), nullptr);

  // Create nodes
  auto func = [](Sample* x)->bool{return (x->label_ > 0);};
  auto num = count_if(set.samples_.begin(), set.samples_.end(), func);
  this->root_ = new Node(1, matrix, tolerance, num_features,
                         set.samples_.size(), num, 0, set.idx_sd_);

  // Delete sample matrix
  delete[] matrix;
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of Tree                                                     //
////////////////////////////////////////////////////////////////////////////////
Tree::~Tree() {
  delete this->root_;
}

////////////////////////////////////////////////////////////////////////////////
// Insert this tree into standant stream                                      //
//                                                                            //
// Parameters:                                                                //
// indent: the number of indents                                              //
////////////////////////////////////////////////////////////////////////////////
void Tree::Print( const int indent ) {
  this->root_->Print(indent);
}

}

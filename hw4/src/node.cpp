////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 4                                //
// node.cpp                                                                   //
// The class Node                                                             //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "node.hpp"
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// The namespace hw4                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw4 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of Node                                                    //
//                                                                            //
// Parameters:                                                                //
// id:           the id of this node                                          //
// id_tree:      the id of the tree                                           //
// matrix:       the sorted sample matrix                                     //
// tolerance:    the tolerance of confusion                                   //
// num_features: the number of features                                       //
// num_samples:  the number of samples                                        //
// num_positive: the number of positive labled samples                        //
// start:        the starting index                                           //
// idx_sd:       the the index maps dense features to sparse features         //
////////////////////////////////////////////////////////////////////////////////
Node::Node( const int id, const int id_tree, SampleVector* matrix,
            const double tolerance, const int num_features,
            const int num_samples, const int num_positive,
            const int start, const int* idx_sd ) {

  // Check tolerance
  if ( !(Confusion(num_samples, num_positive) > tolerance) ) {
    if ( 2*num_positive > num_samples ) {
      this->label_ = +1;
    } else if ( 2*num_positive < num_samples ) {
      this->label_ = -1;
    } else {
      this->label_ = 0;
    }
    return;
  }

  // Declare variables
  int left_samples;      // the number of samples for left branch
  int left_positive;     // the number of positive labled samples for left branch
  double min_confusion;  // the minimal confusion
  int best_idx_s;        // the sparse feature index with minimal confusion
  double best_threshold; // the threshold with minimal confusion
  int best_samples;      // left_samples with minimal confusion
  int best_positive;     // left_positive with minimal confusion

  int middle;
  int end = start+num_samples;

  // Initialize variables
  min_confusion = INFINITY;
  best_idx_s = 0;
  best_threshold = 0.0;
  best_samples = 0;
  best_positive = 0;

  // Find Threshold
  for ( auto i = 0; i < num_features; ++i ) {
    auto& vector = matrix[i];
    left_samples = 0;
    left_positive = 0;

    // Find minimal confusion
    for ( auto it = vector.begin()+start; it != vector.begin()+end-1; ++it ) {
      ++left_samples;
      left_positive += ((*it)->label_ > 0);
      if ( fabs((*it)->features_[i] - (*(it+1))->features_[i]) < 1e-8 ) {
        continue;
      }
      auto tmp = Confusion(num_samples, left_samples,
                           num_positive, left_positive);
      if ( min_confusion > tmp ) {
        min_confusion = tmp;
        best_idx_s = i;
        best_threshold = ((*it)->features_[i] + (*(it+1))->features_[i]) / 2;
        best_samples = left_samples;
        best_positive = left_positive;
      }
    }
  }

  // Check if this node is inseparable
  if ( !isfinite(min_confusion) ) {
    if ( 2*num_positive > num_samples ) {
      this->label_ = +1;
    } else if ( 2*num_positive < num_samples ) {
      this->label_ = -1;
    } else {
      this->label_ = 0;
    }
    return;
  }

  // Identify the samples
  middle = start+best_samples;
  {
    auto& vector = matrix[best_idx_s];
    for ( auto it = vector.begin()+start; it != vector.begin()+middle; ++it ) {
      (*it)->id_[id_tree] = id*2;
    }
    for ( auto it = vector.begin()+middle; it != vector.begin()+end; ++it ) {
      (*it)->id_[id_tree] = id*2+1;
    }
  }

  // Partition the sample matrix
  {
    auto func = [id, id_tree](Sample* x)->
                bool{return (x->id_[id_tree] == id*2);};
    auto& tmp_vec = matrix[num_features];
    for ( auto i = 0; i < num_features; ++i ) {
      if ( i != best_idx_s ) {
        auto& vector = matrix[i];
        std::partition_copy(vector.begin()+start, vector.begin()+end,
                            tmp_vec.begin(), tmp_vec.begin()+best_samples,
                            func);
        std::copy_n(tmp_vec.begin(), num_samples, vector.begin()+start);
      }
    }
  }

  // Store node properties
  this->idx_d_ = idx_sd[best_idx_s];
  this->threshold_ = best_threshold;

  // Recursive
  this->left_  = new Node(id*2, id_tree, matrix, tolerance, num_features,
                          best_samples, best_positive, start, idx_sd);
  this->right_ = new Node(id*2+1, id_tree, matrix, tolerance, num_features,
                          num_samples-best_samples, num_positive-best_positive,
                          middle, idx_sd);
}

////////////////////////////////////////////////////////////////////////////////
// Compute the confusion                                                      //
//                                                                            //
// Parameters:                                                                //
// sam: the number of total samples                                           //
// pos: the number of total positive labled samples                           //
//                                                                            //
// Return Value:                                                              //
// the confusion value                                                        //
//                                                                            //
// Note:                                                                      //
// the confusion value is defined as                                          //
//  (1 - pos_r^2 - (1-pos_r)^2)                                               //
// which is euqivalent to                                                     //
//  2*pos_r*(1-pos_r)                                                         //
////////////////////////////////////////////////////////////////////////////////
inline double Node::Confusion( const double sam, const double pos ) {
  auto pos_r = pos / sam;

  return (pos_r*(1-pos_r));
}


////////////////////////////////////////////////////////////////////////////////
// Compute the confusion                                                      //
//                                                                            //
// Parameters:                                                                //
// sam_t: the number of total samples                                         //
// sam_l: the number of samples for left branch                               //
// pos_t: the number of total positive labled samples                         //
// pos_l: the number of positive labled samples for left branch               //
//                                                                            //
// Return Value:                                                              //
// the confusion value                                                        //
//                                                                            //
// Note:                                                                      //
// the confusion value is defined as                                          //
//  sam_r*(1 - pos_r^2 - (1-pos_r)^2) + (1-sam_r)*(1 - neg_r^2 - (1-neg_r)^2) //
// which is euqivalent to                                                     //
//  2*((sam_r*pos_r*(1-pos_r) + (1-sam_r)*neg_r*(1-neg_r)))                   //
////////////////////////////////////////////////////////////////////////////////
inline double Node::Confusion( const double sam_t, const double sam_l,
                               const double pos_t, const double pos_l ) {
  auto sam_r = sam_l / sam_t;
  auto pos_r = pos_l / sam_l;
  auto neg_r = (pos_t - pos_l) / (sam_t - sam_l);

  return (sam_r*pos_r*(1-pos_r) + (1-sam_r)*neg_r*(1-neg_r));
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of Node                                                     //
////////////////////////////////////////////////////////////////////////////////
Node::~Node() {
  delete this->left_;
  delete this->right_;
}

////////////////////////////////////////////////////////////////////////////////
// Insert this node into standant stream                                      //
//                                                                            //
// Parameters:                                                                //
// indent: the number of indents                                              //
////////////////////////////////////////////////////////////////////////////////
void Node::Print( const int indent ) {
  if ( this->idx_d_ == kNull ) { // Leaf node
    cout << setw(indent*2) << setfill(' ') << ""
         << "return ";
    if ( this->label_ ) {
      cout << showpos << this->label_ << noshowpos << ';' << endl;
    } else {
      cout << "(rand()%2*2-1);" << endl;
    }
  } else { // Internal node
    cout << setprecision(6) << fixed;

    cout << setw(indent*2) << setfill(' ') << ""
         << "if ( attr[" << this->idx_d_ << "] < "
         << this->threshold_ << " ) {" << endl;
    this->left_->Print(indent+1);
    cout << setw(indent*2) << setfill(' ') << ""
         << "} else {" << endl;
    this->right_->Print(indent+1);
    cout << setw(indent*2) << setfill(' ') << ""
         << "}" << endl;
  }
}

}
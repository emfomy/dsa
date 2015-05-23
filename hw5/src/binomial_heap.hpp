////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 5                                //
// binomial_heap.hpp                                                          //
// The header file of BinomialHeap                                            //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW5_BINOMIAL_HEAP_HPP_

#define HW5_BINOMIAL_HEAP_HPP_

#include <list>
#include <utility>

////////////////////////////////////////////////////////////////////////////////
// The namespace hw5                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw5 {

// The maximum number of binomial trees in a binomial heap
const size_t kMaxTrees = 4;

// The empty heap
struct EmptyHeap: public std::exception {};

////////////////////////////////////////////////////////////////////////////////
// The class of a binomial heap                                               //
////////////////////////////////////////////////////////////////////////////////
template<typename T>
class BinomialHeap {
  class BinomialTree;
  friend class BinomialTree;

  typedef BinomialTree BT;
  typedef BinomialHeap<T> BH;

 private:
  // the size of this heap
  size_t size_;

  // the trees of this heap
  BT* tree_[kMaxTrees];

 public:
  BinomialHeap();
  BinomialHeap( const T& root );

  void Merge( BH*& that );
  void Merge( BT*& a, BT*& b, BT*& c );
  void Merge( BT*& a, BT*& b );
  void Insert( const T& root );
  T& Pop();
};

////////////////////////////////////////////////////////////////////////////////
// The class of a binomial tree                                               //
////////////////////////////////////////////////////////////////////////////////
template<typename T>
class BinomialHeap<T>::BinomialTree {
  friend class BinomialHeap;

 private:
  // the size of this tree
  // the size must be a power of two
  size_t size_;

  // the root of this tree
  T root_;

  // the childern trees of this tree
  std::list<BT*> child_;

 public:
  BinomialTree( const T& root );

  inline int size();

  T& Pop( BH*& heap );
};

////////////////////////////////////////////////////////////////////////////////
// The constructor of BinomialHeap                                            //
////////////////////////////////////////////////////////////////////////////////
template<typename T>
BinomialHeap<T>::BinomialHeap() {
  for ( size_t i = 0; i < kMaxTrees; ++i ) {
    this->tree_[i] = nullptr;
  }
  this->size_ = 0;
}

////////////////////////////////////////////////////////////////////////////////
// The constructor of BinomialHeap                                            //
//                                                                            //
// Parameters:                                                                //
// element: the element                                                       //
////////////////////////////////////////////////////////////////////////////////
template<typename T>
BinomialHeap<T>::BinomialHeap( const T& element ) {
  for ( size_t i = 0; i < kMaxTrees; ++i ) {
    this->tree_[i] = nullptr;
  }
  this->size_ = 1;
  tree_[0] = new BT(element);
}

////////////////////////////////////////////////////////////////////////////////
// The constructor of BinomialTree                                            //
// Initialize by an element                                                   //
//                                                                            //
// Parameters:                                                                //
// element: the element                                                       //
////////////////////////////////////////////////////////////////////////////////
template<typename T>
BinomialHeap<T>::BinomialTree::BinomialTree( const T& element ) {
  this->size_ = 1;
  this->root_ = element;
  this->child_.clear();
}

////////////////////////////////////////////////////////////////////////////////
// Get the size of this tree                                                  //
//                                                                            //
// Return Value:                                                              //
// the size of this tree                                                      //
////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline int BinomialHeap<T>::BinomialTree::size() {
  return (this!=nullptr) ? this->size_ : 0;
}

////////////////////////////////////////////////////////////////////////////////
// Merge binomial heaps                                                       //
//                                                                            //
// Input Parameters:                                                          //
// this:  the operand heap                                                    //
// that:  another operand heap                                                //
//                                                                            //
// Output Parameters:                                                         //
// this:  replaced by the sum heap                                            //
// that:  destructed                                                          //
////////////////////////////////////////////////////////////////////////////////
template<typename T>
void BinomialHeap<T>::Merge( BH*& that ) {
  BT* carry = nullptr;
  for ( size_t i = 0; i < kMaxTrees; ++i ) {
    Merge(this->tree_[i], that->tree_[i], carry);
  }
  this->size_ += that->size_;
  delete that;
  delete carry;
}

////////////////////////////////////////////////////////////////////////////////
// Merge binomial trees which have the same sizes with carry in and carry out //
//                                                                            //
// Input Parameters:                                                          //
// tree_a: the operand tree                                                   //
// tree_b: another operand tree                                               //
// tree_c: the carry in tree                                                  //
//                                                                            //
// Output Parameters:                                                         //
// tree_a: replaced by the sum tree                                           //
// tree_b: destructed                                                         //
// tree_c: replaced by the carry out tree                                     //
//                                                                            //
// Note:                                                                      //
// each of the parameters are either nullptr or a pointer of BinomialTree     //
//   with size equal to a power of two                                        //
////////////////////////////////////////////////////////////////////////////////
template<typename T>
void BinomialHeap<T>::Merge( BT*& tree_a, BT*& tree_b, BT*& tree_c ) {
  if ( tree_a == nullptr ) {
    std::swap(tree_a, tree_c);
  }
  if ( tree_c == nullptr ) {
    std::swap(tree_c, tree_b);
  }
  if ( tree_a == nullptr ) {
    std::swap(tree_a, tree_c);
  }

  Merge(tree_c, tree_a);

  if ( tree_a == nullptr ) {
    std::swap(tree_a, tree_b);
  }
}

////////////////////////////////////////////////////////////////////////////////
// Merge binomial trees which have the same sizes                             //
//                                                                            //
// Input Parameters:                                                          //
// tree_a: the operand tree                                                   //
// tree_b: another operand tree                                               //
//                                                                            //
// Output Parameters:                                                         //
// tree_a: replaced by the sum tree                                           //
// tree_b: destructed                                                         //
//                                                                            //
// Note:                                                                      //
// each of the parameters are either nullptr or a pointer of BinomialTree     //
//   with size equal to a power of two                                        //
////////////////////////////////////////////////////////////////////////////////
template<typename T>
void BinomialHeap<T>::Merge( BT*& tree_a, BT*& tree_b ) {
  // Check feasibility
  if ( tree_a == nullptr || tree_b == nullptr ) {
    return;
  }

  // Merge trees
  if ( tree_a->root_ < tree_b->root_ ) {
    std::swap(tree_a, tree_b);
  }
  tree_a->child_.push_back(tree_b);
  tree_a->size_ += tree_b->size();
  tree_b = nullptr;
}

////////////////////////////////////////////////////////////////////////////////
// Insert an element                                                          //
//                                                                            //
// Parameters:                                                                //
// element: the element                                                       //
////////////////////////////////////////////////////////////////////////////////
template<typename T>
void BinomialHeap<T>::Insert( const T& element ) {
  auto temp = new BinomialHeap<T>(element);
  Merge(temp);
}

////////////////////////////////////////////////////////////////////////////////
// Pop the maximum element                                                    //
//                                                                            //
// Return Value:                                                              //
// the maximum element                                                        //
////////////////////////////////////////////////////////////////////////////////
template<typename T>
T& BinomialHeap<T>::Pop() {
  // Check feasibility
  if ( size_ == 0 ) {
    throw EmptyHeap();
  }

  // Find the tree contains maximum element
  int imax = -1;
  for ( size_t i = 0; i < kMaxTrees; ++i ) {
    if ( tree_[i]->size() != 0 && ( imax == -1
         || tree_[i]->root_ > tree_[imax]->root_ ) ) {
      imax = i;
    }
  }

  // Pop the maximum element from the tree
  BH* heap = nullptr;
  T& max_element = tree_[imax]->Pop(heap);
  size_ -= tree_[imax]->size();
  delete tree_[imax];
  tree_[imax] = nullptr;

  // Merge the remaining elements into this heap
  Merge(heap);

  return max_element;
}

////////////////////////////////////////////////////////////////////////////////
// Pop the maximum element and make other elements a binomial heap            //
//                                                                            //
// Output Parameters:                                                         //
// heap:  replaced by the binomial heap                                       //
//                                                                            //
// Return Value:                                                              //
// the maximum element                                                        //
////////////////////////////////////////////////////////////////////////////////
template<typename T>
T& BinomialHeap<T>::BinomialTree::Pop( BH*& heap ) {
  // Create a temporary heap
  heap = new BH();
  heap->size_ = this->size_-1;

  // Put subtrees into the heap
  size_t i = 0;
  for ( auto& tree : this->child_ ) {
    heap->tree_[i++] = tree;
  }

  return this->root_;
}

}

#endif

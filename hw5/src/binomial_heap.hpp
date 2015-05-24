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
const size_t kMaxTrees = 32;

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

  inline int size();

  void Merge( BH* that );
  void Insert( const T& root );
  T& Top();
  T& Pop();

 private:
  void Merge( BT*& a, BT*& b, BT*& c );
  void Merge( BT*& a, BT*& b );
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
    tree_[i] = nullptr;
  }
  size_ = 0;
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
    tree_[i] = nullptr;
  }
  size_ = 1;
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
  size_ = 1;
  root_ = element;
  child_.clear();
}

////////////////////////////////////////////////////////////////////////////////
// Get the size of this heap                                                  //
//                                                                            //
// Return Value:                                                              //
// the size of this tree                                                      //
////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline int BinomialHeap<T>::size() {
  return (this!=nullptr) ? size_ : 0;
}

////////////////////////////////////////////////////////////////////////////////
// Get the size of this tree                                                  //
//                                                                            //
// Return Value:                                                              //
// the size of this tree                                                      //
////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline int BinomialHeap<T>::BinomialTree::size() {
  return (this!=nullptr) ? size_ : 0;
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
////////////////////////////////////////////////////////////////////////////////
template<typename T>
void BinomialHeap<T>::Merge( BH* that ) {
  BT* carry = nullptr;
  for ( size_t i = 0; i < kMaxTrees; ++i ) {
    Merge(this->tree_[i], that->tree_[i], carry);
  }
  this->size_ += that->size_;
  that->size_ = 0;
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
  delete temp;
}

////////////////////////////////////////////////////////////////////////////////
// Get the maximum element                                                    //
//                                                                            //
// Return Value:                                                              //
// the maximum element                                                        //
////////////////////////////////////////////////////////////////////////////////
template<typename T>
T& BinomialHeap<T>::Top() {
  // Check feasibility
  if ( size_ == 0 ) {
    throw EmptyHeap();
  }

  // Find the tree contains maximum element
  BT* max_tree = nullptr;
  for ( auto& tree : tree_ ) {
    if ( tree->size() != 0 && ( max_tree == nullptr
         || tree->root_ > max_tree->root_ ) ) {
      max_tree = tree;
    }
  }

  return max_tree->root_;
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
  BT** tree_addr = nullptr;
  for ( auto& tree : tree_ ) {
    if ( tree->size() != 0 && ( tree_addr == nullptr
         || tree->root_ > (*tree_addr)->root_ ) ) {
      tree_addr = &tree;
    }
  }
  auto& max_tree = *tree_addr;

  // Pop the maximum element from the tree
  BH* heap = nullptr;
  T& max_element = max_tree->Pop(heap);
  size_ -= max_tree->size();
  delete max_tree;
  max_tree = nullptr;

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
  heap->size_ = size_-1;

  // Put subtrees into the heap
  size_t i = 0;
  for ( auto& tree : child_ ) {
    heap->tree_[i++] = tree;
  }

  return root_;
}

}

#endif

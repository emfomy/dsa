#ifndef HW5_BINOMIAL_HEAP_H_

#define HW5_BINOMIAL_HEAP_H_

#include "src/binomial_heap.hpp"

struct EmptyHeap: public hw5::EmptyHeap{};

template<class T>
class BinomialHeap: private hw5::BinomialHeap<T> {
  public:
    BinomialHeap() {
      hw5::BinomialHeap<T>();
    }
    BinomialHeap(T element) {
      hw5::BinomialHeap<T>();
      hw5::BinomialHeap<T>::Insert(element);
    }
    void merge( BinomialHeap& b ) {
      hw5::BinomialHeap<T>::Merge(&b);
    }
    void insert(const T& element) {
      hw5::BinomialHeap<T>::Insert(element);
    }
    T pop() {
      return hw5::BinomialHeap<T>::Pop();
    }
};

#endif

#ifndef COMPARE_ITERATOR_HPP
#define COMPARE_ITERATOR_HPP
#include <vector>
struct CompareIterator {
  int offset;

  CompareIterator(int chunksize) : offset(chunksize - 1) {};
  bool operator()(std::vector<int>::iterator a, std::vector<int>::iterator b) {
    return (*(a + offset) < *(b + offset));
  }
};
#endif

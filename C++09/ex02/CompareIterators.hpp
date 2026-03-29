#ifndef COMPARE_ITERATOR_HPP
#define COMPARE_ITERATOR_HPP
template <typename Container> struct CompareIterator {
  int offset;

  CompareIterator(int chunksize) : offset(chunksize - 1) {};
  bool operator()(typename Container::iterator a,
                  typename Container::iterator b) const {
    return (*(a + offset) < *(b + offset));
  };
};
#endif

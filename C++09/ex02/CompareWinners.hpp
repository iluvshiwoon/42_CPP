#ifndef COMPARE_WINNERS_HPP
#define COMPARE_WINNERS_HPP
#include <utility>
#include <vector>

typedef std::pair<std::vector<int>::iterator, std::vector<int>::iterator>
    IteratorPair;

struct CompareWinners {
  bool operator()(const IteratorPair &a, const IteratorPair &b) const {
    if (*a.first < *b.first)
      return true;
    return false;
  };
};

#endif

#ifndef JACOBSTHAL_HPP
#define JACOBSTHAL_HPP
#include "CompareIterators.hpp"
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

extern const std::size_t J[];

template <typename Iterator> void printChunk(Iterator start, int chunkSize) {
  std::cout << "[";
  for (int i = 0; i < chunkSize; ++i) {
    std::cout << *(start + i);
    if (i < chunkSize - 1)
      std::cout << " ";
  }
  std::cout << "]";
}

template <typename Container> class PmergeMe {
private:
  Container _toSort;
  bool _debug;

public:
  PmergeMe(const std::string &toSort, bool debug = false) : _debug(debug) {
    if (toSort.find_first_not_of("0123456789+ \t\n\v\f\r") !=
        std::string::npos) {
      throw std::runtime_error("Error: Invalid characters in input\n");
    }

    std::istringstream ss(toSort);

    long long number;

    while (ss >> number) {
      if (number > std::numeric_limits<int>::max()) {
        throw std::runtime_error("Error: Number exceeds INT_MAX\n");
      }

      if (number < 0) {
        throw std::runtime_error("Error: Argument contains negative number\n");
      }

      this->_toSort.push_back(static_cast<int>(number));
      if (this->_toSort.size() > 100000)
        throw std::runtime_error("Error: to many numbers, limit is 100000\n");
    }
  };
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &rhs);
  ~PmergeMe() {};

  Container &getContainer() { return _toSort; };

  void sortPairs(typename Container::iterator begin,
                 typename Container::iterator end, int chunkSize) {
    if (chunkSize >= end - begin)
      return;

    int chunkNumbers = (end - begin) / chunkSize;
    int isOdd = chunkNumbers % 2;
    typename Container::iterator realEnd = end - isOdd * chunkSize;

    if (_debug) {
      std::cout << "\n=== [DEPTH DOWN] Chunk Size: " << chunkSize
                << " ===" << std::endl;
    }

    for (typename Container::iterator it = begin + chunkSize - 1; it < realEnd;
         it += 2 * chunkSize) {
      if (_debug) {
        std::cout << "Comparing: ";
        printChunk(it - (chunkSize - 1), chunkSize);
        std::cout << " vs ";
        printChunk(it + 1, chunkSize);
      }

      if (*it > *(it + chunkSize)) {
        std::swap_ranges(it - (chunkSize - 1), it + 1, it + 1);
        if (_debug)
          std::cout << " -> SWAPPED\n";
      } else {
        if (_debug)
          std::cout << " -> KEPT\n";
      }
    }

    this->sortPairs(begin, end - isOdd * chunkSize, chunkSize * 2);

    std::vector<typename Container::iterator> mainChain;
    std::vector<typename Container::iterator> pends;

    mainChain.push_back(begin);
    for (typename Container::iterator it = begin + chunkSize; it < realEnd;
         it += 2 * chunkSize)
      mainChain.push_back(it);
    for (typename Container::iterator it = begin + 2 * chunkSize; it < realEnd;
         it += 2 * chunkSize)
      pends.push_back(it);
    if (realEnd < end)
      pends.push_back(realEnd);

    if (_debug) {
      std::cout << "\n=== [DEPTH UP] Chunk Size: " << chunkSize
                << " ===" << std::endl;
      std::cout << "MainChain (Winners): ";
      for (std::size_t i = 0; i < mainChain.size(); ++i) {
        printChunk(mainChain[i], chunkSize);
        std::cout << " ";
      }
      std::cout << "\nPends (Losers):      ";
      for (std::size_t i = 0; i < pends.size(); ++i) {
        printChunk(pends[i], chunkSize);
        std::cout << " ";
      }
      std::cout << std::endl;
    }

    if (!pends.empty()) {
      std::size_t n = 3;
      while (true) {
        long long start_index = J[n] - 2;
        long long end_index = J[n - 1] - 2;

        if (start_index >= static_cast<long long>(pends.size()))
          start_index = pends.size() - 1;

        for (long long i = start_index; i > end_index; --i) {
          typename std::vector<typename Container::iterator>::iterator it =
              pends.begin() + i;
          typename std::vector<typename Container::iterator>::iterator
              search_end;

          if (*it + chunkSize < end)
            search_end =
                std::find(mainChain.begin(), mainChain.end(), *it + chunkSize);
          else
            search_end = mainChain.end();
          typename std::vector<typename Container::iterator>::iterator
              insert_here =
                  std::lower_bound(mainChain.begin(), search_end, *it,
                                   CompareIterator<Container>(chunkSize));
          mainChain.insert(insert_here, *it);
        }
        n++;
        if (end_index >= static_cast<long long>(pends.size() - 1))
          break;
      }
    }

    if (_debug) {
      std::cout << "MainChain AFTER insertions: ";
      for (std::size_t i = 0; i < mainChain.size(); ++i) {
        printChunk(mainChain[i], chunkSize);
        std::cout << " ";
      }
      std::cout << "\n----------------------------------------\n";
    }

    Container temp;
    for (std::size_t i = 0; i < mainChain.size(); ++i)
      temp.insert(temp.end(), mainChain[i], mainChain[i] + chunkSize);
    std::copy(temp.begin(), temp.end(), begin);
  };
};
#endif

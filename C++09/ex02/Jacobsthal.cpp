#include "Jacobsthal.hpp"
#include "CompareIterators.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

Jacobsthal::Jacobsthal(const std::string &toSort) {
  std::istringstream ss(toSort);
  int number;

  while (ss >> number) {
    if (number < 0)
      throw std::runtime_error("Argument contains negative number\n");
    this->_toSort.push_back(number);
  }
}

void Jacobsthal::run() {
  for (std::size_t i = 0; i < this->_toSort.size(); ++i) {
    std::cout << this->_toSort[i] << ",";
  }
  std::cout << std::endl;

  this->sortPairs(this->_toSort.begin(), this->_toSort.end(), 1);
}

void Jacobsthal::sortPairs(std::vector<int>::iterator begin,
                           std::vector<int>::iterator end, int chunkSize) {
  std::vector<std::vector<int>::iterator> mainChain;
  std::vector<std::vector<int>::iterator> pends;
  if (chunkSize >= end - begin)
    return;

  int chunkNumbers = (end - begin) / chunkSize;
  std::cout << "chunkNumbers: " << chunkNumbers << std::endl;
  int isOdd = chunkNumbers % 2;
  std::vector<int>::iterator realEnd = end - isOdd * chunkSize;
  std::cout << "isOdd: " << isOdd << std::endl;

  for (std::vector<int>::iterator it = begin + chunkSize - 1; it < realEnd;
       it += 2 * chunkSize) {
    std::cout << "*it: " << *it << std::endl;
    std::cout << "*it + chunkSize: " << *(it + chunkSize) << std::endl;
    if (*it > *(it + chunkSize))
      std::swap_ranges(it - (chunkSize - 1), it + 1, it + 1);
  }
  for (std::size_t i = 0; i < this->_toSort.size(); ++i) {
    std::cout << this->_toSort[i] << ",";
  }
  std::cout << std::endl;

  this->sortPairs(begin, end - isOdd * chunkSize, chunkSize * 2);

  mainChain.push_back(begin);
  for (std::vector<int>::iterator it = begin + chunkSize; it < realEnd;
       it += 2 * chunkSize)
    mainChain.push_back(it);
  for (std::vector<int>::iterator it = begin + 2 * chunkSize; it < realEnd;
       it += 2 * chunkSize)
    pends.push_back(it);
  if (realEnd < end)
    pends.push_back(realEnd);
  std::cout << "mainChain: ";
  for (std::size_t i = 0; i < mainChain.size(); ++i) {
    std::cout << *mainChain[i] << ",";
  }
  std::cout << std::endl;
  std::cout << "pends: ";
  for (std::size_t i = 0; i < pends.size(); ++i) {
    std::cout << *pends[i] << ",";
  }

  if (!pends.empty()) {
    int n = 3;
    while (true) {
      long long start_index = J[n] - 2;
      long long end_index = J[n - 1] - 2;

      if (start_index >= static_cast<long long>(pends.size()))
        start_index = pends.size() - 1;

      for (long long i = start_index; i > end_index; --i) {
        std::vector<std::vector<int>::iterator>::iterator it =
            pends.begin() + i;
        std::vector<std::vector<int>::iterator>::iterator search_end;
        if (*it + chunkSize < end)
          search_end =
              std::find(mainChain.begin(), mainChain.end(), *it + chunkSize);
        else
          search_end = mainChain.end();
        std::vector<std::vector<int>::iterator>::iterator insert_here =
            std::lower_bound(mainChain.begin(), search_end, *it,
                             CompareIterator(chunkSize));
        mainChain.insert(insert_here, *it);
      }
      n++;
      if (end_index >= static_cast<long long>(pends.size() - 1))
        break;
    }
  }

  std::cout << std::endl;
  std::cout << "mainChain AFTER: ";
  for (std::size_t i = 0; i < mainChain.size(); ++i) {
    std::cout << *mainChain[i] << ",";
  }
  std::cout << std::endl;
  std::vector<int> temp;
  for (std::size_t i = 0; i < mainChain.size(); ++i)
    temp.insert(temp.end(), mainChain[i], mainChain[i] + chunkSize);
  std::copy(temp.begin(), temp.end(), begin);
  std::cout << "toSort AFTER: ";
  for (std::size_t i = 0; i < this->_toSort.size(); ++i) {
    std::cout << _toSort[i] << ",";
  }
  std::cout << std::endl;
}
Jacobsthal::~Jacobsthal() {};

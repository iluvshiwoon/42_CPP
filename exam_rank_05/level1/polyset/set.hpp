#pragma once
#include "searchable_bag.hpp"

class set {
private:
  searchable_bag *_bag;

public:
  set(searchable_bag &_bag) : _bag(&_bag) {};
  set(const set &other) : _bag(other._bag) {};
  set &operator=(const set &rhs) {
    if (this != &rhs)
      this->_bag = rhs._bag;
    return *this;
  };
  ~set() {
    if (this->_bag)
      this->_bag->clear();
  };

  bool has(int value) {
    if (this->_bag)
      return _bag->has(value);
    return false;
  }
  void insert(int value) {
    if (this->_bag)
      this->_bag->insert(value);
  }
  void print() {
    if (this->_bag)
      this->_bag->print();
  }
  void insert(int *arr, int n) {
    if (_bag) {
      this->_bag->insert(arr, n);
    }
  };

  void clear() {
    if (this->_bag)
      this->_bag->clear();
  };

  searchable_bag &get_bag() { return *(this->_bag); }
};

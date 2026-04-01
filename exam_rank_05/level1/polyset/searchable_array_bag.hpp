#pragma once

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag {
public:
  searchable_array_bag() : array_bag() {};
  searchable_array_bag(const searchable_array_bag &other) : array_bag(other) {};
  searchable_array_bag &operator=(const searchable_array_bag &rhs) {
    if (this != &rhs)
      array_bag::operator=(rhs);
    return *this;
  }
  ~searchable_array_bag() { this->clear(); };
  virtual bool has(int value) const {
    for (int i = 0; i < this->size; ++i) {
      if (this->data[i] == value)
        return true;
    }
    return false;
  };
};

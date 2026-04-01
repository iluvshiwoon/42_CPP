#pragma once

#include "searchable_bag.hpp"
#include "tree_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag {
public:
  searchable_tree_bag() : tree_bag() {};
  searchable_tree_bag(const searchable_tree_bag &other) : tree_bag(other) {};
  searchable_tree_bag &operator=(const searchable_tree_bag &rhs) {
    if (this != &rhs)
      tree_bag::operator=(rhs);
    return *this;
  }
  ~searchable_tree_bag() { this->clear(); };
  virtual bool has(int value) const {
    node *current = this->tree;
    while (current != nullptr) {
      if (current->value == value)
        return true;
      else if (value < current->value)
        current = current->l;
      else
        current = current->r;
    }
    return false;
  };
};

#pragma once
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

void trim(std::vector<int> &input) {
  while (input.size() > 1 && input.back() == 0)
    input.pop_back();
}

class bigint {
private:
  std::vector<int> _data;

public:
  bigint() { this->_data.push_back(0); };
  bigint(unsigned int value) {
    if (value == 0)
      this->_data.push_back(0);
    while (value) {
      _data.push_back(value % 10);
      value /= 10;
    }
  };

  unsigned int get_int(const bigint &a) {
    unsigned int res = 0;
    for (int i = 0; i < a._data.size(); ++i)
      res = res * 10 + a._data[i];
    return res;
  }

  bigint(const bigint &other) : _data(other._data) {};
  bigint &operator=(const bigint &rhs) {
    if (this != &rhs)
      this->_data = rhs._data;
    return *this;
  };
  ~bigint() {};

  const std::vector<int> &get_vector() const { return this->_data; };

  bigint &operator+=(const bigint &rhs) {
    int carry = 0;
    int res = 0;
    int a = 0;
    int b = 0;
    size_t max_len = std::max(this->_data.size(), rhs._data.size());
    for (size_t i = 0; i < max_len || carry; ++i) {
      if (i >= this->_data.size()) {
        this->_data.push_back(0);
        b = rhs._data[i];
      } else if (i >= rhs._data.size())
        b = 0;
      else
        b = rhs._data[i];
      a = this->_data[i];
      res = a + b + carry;
      this->_data[i] = res % 10;
      carry = res / 10;
    }
    return *this;
  }

  bigint operator+(const bigint &rhs) const {
    bigint rvalue(*this);
    rvalue += rhs;
    return rvalue;
  }

  bigint operator++(int) {
    bigint temp(*this);
    ++(*this);
    return temp;
  };

  bigint &operator++() {
    *this += bigint(1);
    return *this;
  }

  bigint &operator<<=(unsigned int n) {
    if (this->_data.size() == 1 && this->_data[0] == 0)
      return *this;
    this->_data.insert(this->_data.begin(), n, 0);
    return *this;
  }

  bigint operator<<(unsigned int n) {
    bigint temp(*this);
    return temp <<= n;
  }

  bigint &operator>>=(unsigned int n) {
    if (this->_data.size() == 1 && this->_data[0] == 0)
      return *this;
    this->_data.erase(this->_data.begin(), this->_data.begin() + n);
    return *this;
  }

  bigint operator>>(unsigned int n) {
    bigint temp(*this);
    return temp >>= n;
  }

  bigint &operator>>=(const bigint &a) { return *this >>= get_int(a); }

  bigint &operator<<=(const bigint &a) { return *this <<= get_int(a); }

  bigint operator>>(const bigint &a) {
    bigint temp(*this);
    return temp >>= a;
  }

  bigint operator<<(const bigint &a) {
    bigint temp(*this);
    return temp <<= a;
  }

  bool operator<(const bigint &rhs) const {
    if (_data.size() != rhs._data.size())
      return (_data.size() < rhs._data.size());
    for (int i = _data.size() - 1; i >= 0; --i)
      if (_data[i] != rhs._data[i])
        return _data[i] < rhs._data[i];
    return false;
  }

  bool operator>(const bigint &rhs) const { return rhs < *this; }

  bool operator==(const bigint &rhs) const {
    return (this->_data == rhs._data);
  }

  bool operator>=(const bigint &rhs) const { return !(*this < rhs); }
  bool operator<=(const bigint &rhs) const { return !(*this > rhs); }

  bool operator!=(const bigint &rhs) const { return !(*this == rhs); }
};

std::ostream &operator<<(std::ostream &os, const bigint &a) {
  std::vector<int> b = a.get_vector();
  trim(b);
  for (int i = 1; i <= b.size(); ++i)
    std::cout << b[b.size() - i];
  return os;
}

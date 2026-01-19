#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstddef>
#include <exception>

template <typename T> class Array {
private:
  size_t _size;
  T *_data;

public:
  Array();
  explicit Array(unsigned int n);
  Array(const Array &other);
  Array &operator=(const Array &rhs);
  ~Array();

  T &operator[](const size_t i);
  const T &operator[](const size_t i) const;
  size_t size() const;
};

template <typename T> Array<T>::Array() : _size(0), _data(NULL) {}
template <typename T> Array<T>::~Array() { delete[] _data; }

template <typename T> Array<T>::Array(unsigned int n) : _size(0), _data(NULL) {
  _data = new T[n]();
  _size = n;
}

template <typename T>
Array<T>::Array(const Array &other) : _size(0), _data(NULL) {
  *this = other;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other) {
  if (this != &other) {
    T *temp;
    if (other._data) {
      temp = new T[other._size]();
      for (size_t i = 0; i < other._size; i++)
        temp[i] = other._data[i];
      this->_size = other._size;
      delete[] this->_data;
      this->_data = temp;
    } else {
      delete[] this->_data;
      this->_data = NULL;
      this->_size = 0;
    }
  }
  return *this;
}

template <typename T> T &Array<T>::operator[](const size_t i) {
  if (i >= this->_size)
    throw std::exception();
  return this->_data[i];
}

template <typename T> const T &Array<T>::operator[](const size_t i) const {
  if (i >= this->_size)
    throw std::exception();
  return this->_data[i];
}

template <typename T> size_t Array<T>::size() const { return this->_size; }

#endif

// #ifndef JACOBSTHAL_HPP
// #define JACOBSTHAL_HPP
// #include "CompareWinners.hpp"
// #include <string>
// static double Jn[] = {
//     0,           1,           1,           3,           5,
//     11,          21,          43,          85,          171,
//     341,         683,         1365,        2731,        5461,
//     10923,       21845,       43691,       87381,       174763,
//     349525,      699051,      1.3981e+06,  2.7962e+06,  5.5924e+06,
//     1.11848e+07, 2.23696e+07, 4.47392e+07, 8.94785e+07, 1.78957e+08,
//     3.57914e+08, 7.15828e+08, 1.43166e+09, 2.86331e+09};
//
// class Jacobsthal {
// private:
//   std::vector<int> _toSort;
//   std::vector<IteratorPair> _pairs;
//
// public:
//   Jacobsthal(const std::string &toSort);
//   Jacobsthal(const Jacobsthal &other);
//   Jacobsthal &operator=(const Jacobsthal &rhs);
//   ~Jacobsthal();
// };
// #endif
#include "Jacobsthal.hpp"
#include <sstream>

Jacobsthal::Jacobsthal(const std::string &toSort) {
  std::istringstream ss(toSort);
  std::string number;

  while (ss >> number) {
  }
}

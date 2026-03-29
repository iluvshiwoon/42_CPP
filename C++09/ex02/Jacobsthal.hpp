#ifndef JACOBSTHAL_HPP
#define JACOBSTHAL_HPP
#include <string>
#include <vector>

static std::size_t J[] = {
    0,        1,         1,         3,         5,         11,       21,
    43,       85,        171,       341,       683,       1365,     2731,
    5461,     10923,     21845,     43691,     87381,     174763,   349525,
    699051,   1398101,   2796203,   5592405,   11184811,  22369621, 44739243,
    89478485, 178956971, 357913941, 715827883, 1431655765};

class Jacobsthal {
private:
  std::vector<int> _toSort;

public:
  Jacobsthal(const std::string &toSort);
  Jacobsthal(const Jacobsthal &other);
  Jacobsthal &operator=(const Jacobsthal &rhs);
  ~Jacobsthal();

  void run();
  void sortPairs(std::vector<int>::iterator begin,
                 std::vector<int>::iterator end, int chunkSize);
};
#endif

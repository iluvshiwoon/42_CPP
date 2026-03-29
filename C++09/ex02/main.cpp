#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <sys/time.h>

long long getTimeMicroseconds() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (tv.tv_sec * 1000000LL) + tv.tv_usec;
}

template <typename Container>
void printContainer(const std::string &prefix, Container &c) {
  std::cout << prefix;
  for (typename Container::iterator it = c.begin(); it != c.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Error: No numbers provided.\nUsage ./PmergeMe \"<numbers\""
              << std::endl;
    return 1;
  }

  bool debugMode = false;

  try {
  PmergeMe<std::vector<int> > vecSorter(std::string(argv[1]), debugMode);
  PmergeMe<std::deque<int> > deqSorter(std::string(argv[1]), false);
  

  printContainer("Before: ", vecSorter.getContainer());

  long long startVec = getTimeMicroseconds();
  vecSorter.sortPairs(vecSorter.getContainer().begin(),
                      vecSorter.getContainer().end(), 1);
  long long endVec = getTimeMicroseconds();

  long long startDeq = getTimeMicroseconds();
  deqSorter.sortPairs(deqSorter.getContainer().begin(),
                      deqSorter.getContainer().end(), 1);
  long long endDeq = getTimeMicroseconds();

  printContainer("\nAfter:  ", vecSorter.getContainer());

  if (debugMode == false)
  {
  std::cout << "\nTime to process a range of " << vecSorter.getContainer().size()
            << " elements with std::vector : " << (endVec - startVec) << " us"
            << std::endl;

  std::cout << "Time to process a range of " << deqSorter.getContainer().size()
            << " elements with std::deque  : " << (endDeq - startDeq) << " us"
            << std::endl;
  }
} catch (std::exception &e) {
      std::cerr << e.what();
  }
  return 0;
}

#include <algorithm>
#include <stdexcept>
template <typename T> typename T::iterator easyfind(T &container, int value) {
  typename T::iterator it;

  it = std::find(container.begin(), container.end(), value);
  if (it == container.end())
    throw std::runtime_error("Value not find");
  return it;
}

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP
#include "Data.h"
#include <stdint.h>

class Serialize {
private:
  Serialize();
  Serialize(const Serialize &other);
  Serialize &operator=(const Serialize &rhs);
  ~Serialize();

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};
#endif

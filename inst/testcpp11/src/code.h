#include <cpp11/doubles.hpp>
#include <cstdlib>

class Random {
  public:
    virtual cpp11::doubles uniform(size_t size) const {
      auto values = cpp11::writable::doubles(size);
      for (auto i = 0l; i < size; ++i) {
        values[i] = ((double) std::rand() / (RAND_MAX)) + 1;
      }
      return values;
    };
};

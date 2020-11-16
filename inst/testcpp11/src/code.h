#include <cpp11/doubles.hpp>
#include <cstdlib>

class Random {
  public:
    virtual cpp11::doubles uniform(size_t size) const {
      auto values = cpp11::writable::doubles(size);
      // Newer GCC builds (Mac OS and Linux can use auto i = 0
      // Older windows builds need to specify a type to avoid ambiguity errors 3/11/20 R 4.0.3
      for (cpp11::writable::doubles::size_type i = 0; i < size; ++i) {
        values[i] = ((double) std::rand() / (RAND_MAX)) + 1;
      }
      return values;
    };
};

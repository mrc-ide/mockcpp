#include <cpp11/doubles.hpp>
#include <testthat.h>
#include <mockcpp.h>
#include "code.h"

class MockRandom : public Random {
  MAKE_CONST_MOCK1(uniform, cpp11::doubles(size_t), override);
};

using trompeloeil::_;

context("Can mock an RNG") {
  
  test_that("you can change the return value") {
    MockRandom rng;
    auto mock_values = cpp11::writable::doubles{1, .2, .3, .4, .5};
    auto size = mock_values.size();
    REQUIRE_CALL(rng, uniform(_)).RETURN(mock_values);
    auto actual = rng.uniform(size);
    // Newer GCC builds (Mac OS and Linux can use auto i = 0
    // Older windows builds need to specify a type to avoid ambiguity errors 3/11/20 R 4.0.3
    for (cpp11::writable::doubles::size_type i = 0; i < size; ++i) {
      expect_true(actual[i] == mock_values[i] );
    }
  }

}

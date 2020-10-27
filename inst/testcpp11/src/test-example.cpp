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
    for (auto i = 0l; i < size; ++i) {
      expect_true(actual[i] == mock_values[i]);
    }
  }

}

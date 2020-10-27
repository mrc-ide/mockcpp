#include <Rcpp.h>
#include <testthat.h>
#include <mockcpp.h>
#include "code.h"

class MockRandom : public Random {
  MAKE_CONST_MOCK1(uniform, Rcpp::NumericVector(size_t), override);
};

using trompeloeil::_;

context("Can mock an RNG") {
  
  test_that("you can change the return value") {
    MockRandom rng;
    auto mock_values = Rcpp::NumericVector::create(.1, .2, .3, .4, .5);
    REQUIRE_CALL(rng, uniform(_)).RETURN(mock_values);
    expect_true(Rcpp::is_true(Rcpp::all(rng.uniform(5) == mock_values)));
  }

}

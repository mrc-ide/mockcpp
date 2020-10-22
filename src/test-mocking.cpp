#include <testthat.h>
#include "../inst/include/mockcpp.h"

class Adder {
  public:
    virtual int add(int a, int b) const {
      return a + b;
    };
    virtual int add(int a, int b, int c) const {
      return a + b + c;
    };
    virtual double add(double a, double b) const {
      return a + b;
    };
};

class MockAdder : public Adder {
  MAKE_CONST_MOCK2(add, int(int, int), override);
  MAKE_CONST_MOCK3(add, int(int, int, int), override);
  MAKE_CONST_MOCK2(add, double(double, double), override);
};

using trompeloeil::_;

context("Can mock a virtual method") {
  
  test_that("you can change the return value") {
    MockAdder adder;
    REQUIRE_CALL(adder, add(1, 2)).RETURN(4);
    expect_true(adder.add(1, 2) == 4);
  }

  test_that("you can test the first argument") {
    MockAdder adder;
    REQUIRE_CALL(adder, add(5, _)).RETURN(4);
    adder.add(5, 6);
  }

  test_that("you can test the third argument") {
    MockAdder adder;
    REQUIRE_CALL(adder, add(_, _, 7)).RETURN(4);
    adder.add(5, 6, 7);
  }

  test_that("you can test approximate arguments") {
    MockAdder adder;
    REQUIRE_CALL(adder, add(_, 6.)).WITH(Approx(_1) == 5).RETURN(4);
    adder.add(5.00000001, 6.);
  }

  test_that("you can mock a method several times") {
    MockAdder adder;
    REQUIRE_CALL(adder, add(1, 2)).RETURN(4).TIMES(3);
    adder.add(1, 2);
    adder.add(1, 2);
    adder.add(1, 2);
  }
}

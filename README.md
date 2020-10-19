
# mockcpp

<!-- badges: start -->
<!-- badges: end -->

The goal of mockcpp is to package up a testthat integration of (trompeloeil)[https://github.com/rollbear/trompeloeil]

Trompeloeil is...
> A thread-safe header-only mocking framework for C++11/14 using the Boost Software License 1.0

## Setup

1. Set up your R package to test C++ using testthat:

```r
usethis::use_testthat() # set up your package for testthat
testthat::use_catch() # set up your package to test C++ using catch and testthat
```

2. Add `mockcpp` to your package:

You should add it to your DESCRIPTION:

```
Remotes:
  ...
  mrc-ide/mockcpp
Imports:
  ...
  mockcpp
LinkingTo:
  ...
  Rcpp,
  testthat,
  mockcpp
```

## Example

You can then mock your C++ classes like this:

``` cpp
#include <testthat.h>
#include <mockcpp.h> //It is important that mockcpp.h is included *after* testthat.h

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

context("Can mock a virtual method") {

  test_that("you can change the return value") {
    MockAdder adder;
    REQUIRE_CALL(adder, add(1, 2)).RETURN(4);
    expect_true(adder.add(1, 2) == 4);
  }
  
}
```

For basic examples, please refer to: `src/test-mocking.cpp`

For more advanced examples please refer to the [trompeloeil documentation](https://github.com/rollbear/trompeloeil#documentation)

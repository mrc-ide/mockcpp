
# mockcpp

<!-- badges: start -->
[![R build status](https://github.com/mrc-ide/mockcpp/workflows/R-CMD-check/badge.svg)](https://github.com/mrc-ide/mockcpp/actions)
<!-- badges: end -->

The goal of mockcpp is to package up a testthat integration of [trompeloeil](https://github.com/rollbear/trompeloeil)

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
  testthat,
  mockcpp
```

3. Make sure you are compiling against the C++14 standard

You should add the following to your Makevars:

```
CXX_STD = CXX14
```

## Example

For basic examples, please refer to: `vignettes/Examples.Rmd` or `src/test-mocking.cpp`

For more advanced examples please refer to the [trompeloeil documentation](https://github.com/rollbear/trompeloeil#documentation)

## License

This R package is licenced under MIT but is mostly made of the Boost licensed
trompeloeil library. (Full license at [inst/LICENSE.bsl-1](https://github.com/mrc-ide/mockcpp/blob/master/inst/LICENSE.bsl-1))

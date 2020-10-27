#include <Rcpp.h>

class Random {
  public:
    virtual Rcpp::NumericVector uniform(size_t size) const {
      return Rcpp::runif(size);
    };
};

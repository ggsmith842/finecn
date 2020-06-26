
# finecn

<!-- badges: start -->
<!-- badges: end -->

The goal of finecn is to provide a user friendly r-package that allows quick calculations commonly used in 
basic finance. Additionally, two analytical methods are provided: 
 * CAPM for analyzing stock returns and predicting future changes in price/return
 * Momentum for analyzing trends using moving averages

This package uses c++ code for most calculations and also makes use of plotly to provide interactive graphs.

**Important Note**

*Some understanding of basic finance is required to use this package*

*For example, a good understaning of beta, risk-free rate, and market premium are needed to use `capm`*

## Installation

You can install the released version of finecn with
```
devtools::install_github("ggsmith842/finecn")
```

``` r
install.packages("finecn")
```

Here are some examples to get you started.
``` r
library(finecn)

#calculate the present value needed to obtain a future value at a specified interest rate
pv(1595.35,.05,5)
#[1] 1250

#find the expected return of a stock using CAPM 
capm(.01,2.3,.08)
#[1] 19.4

#determine if a stock is over/under valued based on CAPM a
capmValue(19.4,11.2)
#The stock is overvalued
```


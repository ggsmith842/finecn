#' @importFrom magrittr %>%
#' @importFrom plotly layout
#' @importFrom plotly plot_ly
#' @importFrom plotly add_lines
#'
#' @aliases NULL
#' @details
#' Financial formulas and minor analysis
"_PACKAGE"


#' Calculate the moving average for a set of prices
#'
#' Provide a vector of stock prices and the desired interval to get the nth day moving average
#'
#' @param prices a vector of stock prices
#' @param y the interval used
#' @return the nth-day moving average
#'
#' @export
#' @examples
#' prices<-round(rnorm(50,10.00),2)
#' mabar(prices,20)
#'
mabar <- function(prices, y) {
  ma <-numeric()
  j <- 0
  for (i in seq_along(prices)) {
    x <- seq(y) + j
    if (anyNA(prices[x])) {
      break
    }
    else {
      (y <- prices[x])
    }
    j<-j + 1
    ma[i]<- mean(y)
  }
  ma<-round(ma,2)
  return(ma)
}

#' Technical Analysis Moving Averages
#'
#' Provide a vector of stock prices and the desired interval to pot the long and short moving averages
#' When the short moving average crosses the long moving average from below, this is a buy signal
#' When the short moving average corsses the long moving average from aboce, this is a sell signal
#'
#' @param prices a vector of stock prices
#' @param short the interval used for the short moving average
#' @param long the interval used for the long moving average
#'
#' @return interactive plot
#'
#' @export
#' @examples
#' prices<-round(rnorm(50,10.00),2)
#' MAplot(prices,3,20)
MAplot <-function(prices,short,long){
  ma1<-mabar(prices,short)
  ma2<-mabar(prices,long)
  a<-data.frame(ma=ma1,t=seq_along(ma1))
  b<-data.frame(ma=ma2,t=seq_along(ma2))
  plot_ly(data=a,x=~t,y=~ma,name="short moving avg") %>%
    add_lines() %>%
    add_lines(data=b,x=~t,y=~ma,name="long moving avg") %>%
    layout(xaxis = list(range = c(0,nrow(b))))
}

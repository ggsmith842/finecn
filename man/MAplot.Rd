% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/finecn.R
\name{MAplot}
\alias{MAplot}
\title{Technical Analysis Moving Averages}
\usage{
MAplot(prices, short, long)
}
\arguments{
\item{prices}{a vector of stock prices}

\item{short}{the interval used for the short moving average}

\item{long}{the interval used for the long moving average}
}
\value{
interactive plot
}
\description{
Provide a vector of stock prices and the desired interval to pot the long and short moving averages
When the short moving average crosses the long moving average from below, this is a buy signal
When the short moving average corsses the long moving average from aboce, this is a sell signal
}
\examples{
prices<-round(rnorm(50,10.00),2)
MAplot(prices,3,20)
}

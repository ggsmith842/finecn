#include <Rcpp.h>
using namespace Rcpp;

//'Future Value of a cash flow
//'
//'Provide the present value, interest rate, and number of periods
//'
//'@name fv
//'
//'
//'@param pv the present value of a cash flow
//'@param i the annual interest rate
//'@param n the number of periods
//'
//'@return Future Value
//'
//'
//'@export fv
// [[Rcpp::export]]
double fv(double pv,double i,int n){
  double fv = pv*pow((1+i),n);
  return  fv;
}

//'Present Value of a cash flow
//'
//'Provide the future value, interest rate, and number of periods to get the present value needed
//'
//'@name pv
//'
//'
//'@param fv the future value of a cash flow
//'@param i the annual interest rate
//'@param n the number of periods
//'
//'@return Present Value
//'
//'
//'@export pv
// [[Rcpp::export]]
double pv(double fv,double i,int n){
  double pv = fv/pow((1.0+i),n);
  return pv;
}

//'Future Value of an ordinary annuity
//'
//'Provide the cash flow, interest rate, and number of periods
//'
//'@name fvannuity
//'
//'
//'@param cf the present value of a cash flow
//'@param i the annual interest rate
//'@param n the number of years
//'@param m the number of periods in a year
//'@param p an optional parameter to divide the number of
//'
//'@return Future Value
//'
//'
//'@export fvannuity
// [[Rcpp::export]]
double fvannuity(double cf,int n,double m, double i,double p=1.0){
  double fv=(cf/m)*(pow((1+i/m),m*n)-1)/(i/m);
  return fv/p;
}

//'Present Value of an ordinary annuity
//'
//'Provide the cash flow, interest rate, and number of periods
//'
//'@name fvannuity
//'
//'
//'@param cf the present value of a cash flow
//'@param i the annual interest rate
//'@param n the number of years
//'
//'@return Present Value
//'
//'
//'@export pvannuity
// [[Rcpp::export]]
double pvannuity(double cf,double i,int n){
  double pv = cf*((1-pow(1+i,-n))/i);
  return pv;
}

//'Expected return of a stock based on capm
//'
//'Provide the risk-free rate of return, beta, and market premium to calculate the expected market return
//'
//'@name capm
//'
//'
//'@param rf the risk free rate of return
//'@param b beta for the interested stock
//'@param mp the market premium rate
//'
//'@return capm expected return
//'
//'
//'@export capm
// [[Rcpp::export]]
double capm(double rf,double b,double mp){
  double exp_return = (rf + b*mp)*100;
  return exp_return;
}

//'Value of a stock based on capm analysis
//'
//'Provide the expected return and the capm return to determine the value of a stock using fundamental analysis
//'
//'@name capmValue
//'
//'
//'@param capm the return according to capm
//'@param expR the expected return for the stock
//'
//'@return the stock's position
//'
//'
//'@export capmValue
// [[Rcpp::export]]
void capmValue(double capm,double expR){
  if(capm > expR){
    Rcout << "The stock is overvalued" << std::endl;
  }
  if(capm < expR) {
    Rcout << "The stock is undervalued" << std::endl;
  }
  if(capm == expR){
    Rcout << "The stock falls on the security market line" <<std::endl;
  }
}


//'Expected return of a stock based on the geometric mean
//'
//'Provide the percentage change in the price of a stock to calculate the expected geometric return
//'
//'@name geom_Bar
//'
//'
//'@param x a vector containing the daily percent changes in price for a stock
//'
//'@return expected return of a stock
//'
//'
//'@export geom_Bar
// [[Rcpp::export]]
double geom_Bar(NumericVector x){ //x is percent changes
  double mult=1.0;
  int n=x.size();
  for(int i=0;i<n;i++){
    mult = mult*(1+x[i]);
  }
  double gbar = pow(mult,(1.0/n))-1;
  return gbar;
}

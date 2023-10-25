#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
  return exp(x);
}

double line_area(double a,double b,int n){
  double x;
  double h = (b - a) / n;
  double sum = 0.5 * (f(a) + f(b));

  for (int i = 1; i < n; i++) {
    double x = a + i * h;
    sum += f(x);
  }

  return h * sum;
}

int main(){
  double a,b,result;
  int n;
  n = 10000000; 
  a = 0.0;
  b = 1.0;

  result = line_area(a,b,n);
  printf("%lf",result);
}

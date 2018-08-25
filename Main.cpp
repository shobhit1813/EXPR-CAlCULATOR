#include<iostream>
#include "exprSolver.c";
using namespace std;

int main()
{
  char expr[100];
  cout<<"Enter the expression to evaluate:\n"; 
  cin>>expr;
  int result = solve(expr);
  return 0;
}

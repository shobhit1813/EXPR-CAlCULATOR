#include<iostream>
#include "exprSolver.cpp"
using namespace std;

int main()
{
  char expr[100];
  cout<<"Enter the expression to evaluate:\n"; 
  cin>>expr;
  int result = solve(expr);
  cout<<"Ans is"<<result;
  return 0;
}

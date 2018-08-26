#include<iostream>
#include "exprSolver.cpp"
using namespace std;

int main()
{
  char expr[100];
  cout<<"Enter the expression to evaluate:\n"; 
  cin.getline(expr,100);
  int result = solve(expr);
  cout<<"Ans is"<<result;
  return 0;
}

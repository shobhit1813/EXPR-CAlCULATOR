#include<iostream>
#include<cctype>
#include "exprSolver.hpp";
#include "Stack.cpp";
x
using namespace std;

int solve(char expr)
{
	Stack oper;
	Stack eval;
	int i;
	while(expr[i] != '\0')
	{
		  if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '%' || expr[i] == '^' || expr[i] == ')' || expr[i] == '!') ops.push(expr[i]);
		  else if(expr[i] == '(')
		  {
				
		  }
		  else if(isdigit(expr[i])) eval.push(expr[i]);
		  else if(expr[i] == ' ') continue;
		  else cout<<"You Entered an invalid symbol";		
	}
}

void retrieve()
{
  
}

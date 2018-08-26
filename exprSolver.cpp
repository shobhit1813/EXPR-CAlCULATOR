#include<iostream>
#include<cctype>
#include<string>
#include "exprSolver.hpp";
#include "Stack.cpp";

using namespace std;

int solve(char expr)
{
	Stack oper = NULL;
	Stack val = NULL;
	int i;
	for(i = 0; i < expr.length(); i++)
	{
		  if(expr[i] == '(') push(oper,expr[i]);	
		  else if(isdigit(expr[i]))
		  {
		  	int value = 0;
		  	//if there are more than one digit
		  	while(i < expr.length() && isdigit(expr[i]))
		  	{
		  		value = value * 10 + (expr[i] - '0');
		  		i++;
		  	}
		  	push(val,value);
		  }
		  else if( expr[i] == ')')
		  {
			while(!isempty(oper)&& expr[i] != '(')
			{
			  int val1 = top(val);
			  pop(val);
			  int val2 = top(val);
			  pop(val);
			  char op = top(oper);
			  pop(oper);
			  int insert_res = calculate(val1,val2,op);
			  push(val,insert);
			}
		  }
		  else if(expr[i] == ' ') continue;
		  else 
		  {
		  	if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '%' || expr[i] == '^'  || expr[i] == '!') 
		  	{
		  		while(!isempty(oper) && preceed(top(oper)) >= preceed(expr[i]))
		  		{

		  		}
		  	}
		  
		  }
	}
}

int calculate(int v1, int v2, char op)
{
	switch(op)
	{
		case '+': return v1 +  v2;
		case '-': return v1 -  v2;
		case '*': return v1 *  v2;
		case '/': return v1 /  v2;
		case '%': return v1 %  v2;
	}
}

int preceed(char op)
{
		if(op == '*' || op == '/') return 2;
		else if(op  == '+' || op == '-') return 1;
		else return 0; 
	
}
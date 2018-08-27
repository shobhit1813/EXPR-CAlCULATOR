#include<iostream>
#include<cctype>
#include<string>
#include "exprSolver.h"
#include "Stack.cpp"

using namespace std;

int solve(char* expr)
{

	opStack* oper = NULL;
	valStack* val = NULL;
	int i;
	int len = exprLen(expr);
	int insert_res = 0;
	for(i = 0; i < len; i++)
	{
		if(expr[i] == ' ') continue;
		else if(isdigit(expr[i]))	
		{
			int value = 0;
			while(i < len && isdigit(expr[i]))
			{
				value = value * 10 + (expr[i] - '0');
				i++;
			}
			valpush(val, value);
		}
		else if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^' || expr[i] == '%' )
		{
			while( !opisEmpty(oper) &&  preceed(optop(oper)) >= preceed(expr[i]) )
			{
				int val1 = valtop(val);
				valpop(val);

				int val2 = valtop(val);
				valpop(val);


				char op = optop(oper);
				oppop(oper);
				valpush(val, calculate(val1, val2, op));
			}
			oppush(oper, expr[i]);
		}	
		else if(expr[i] =='(') oppush(oper, expr[i]);
		else if(expr[i] == ')')
		{
			while(!opisEmpty(oper) && optop(oper) != '(')
			{
				int val1 = valtop(val);
				valpop(val);

				int val2 = valtop(val);
				valpop(val);


				char op = optop(oper);
				oppop(oper);

				valpush(val, calculate(val1, val2, op));

			}
			  oppop(oper);
		}

	}

	while(!opisEmpty(oper))
	{

		int val1 = valtop(val);
		valpop(val);

		int val2 = valtop(val);
		valpop(val);


		char op = optop(oper);
		oppop(oper);
		valpush(val, calculate(val1, val2, op));
	}
  return valtop(val);
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
		default: return INT_MIN;
		//case 'sq': return calSqroot()
	}
}

int preceed(char op)
{
		if(op == '*' || op == '/') return 2;
		else if(op  == '+' || op == '-') return 1;
		else return 0; 
	
}

int exprLen(char *expr)
{
	int len = 0, i = 0;
	while(expr[i] != '\0')
	{
		len++;
		i++;
	}
	return len;
}
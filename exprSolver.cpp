#include<iostream>
#include<cctype>
#include<string>
#include "exprSolver.h"
#include "Stack.cpp"

using namespace std;

opStack* oper = NULL;
valStack* val = NULL;
char uni = 's';

int solve(char* expr)
{
	int i;
	int len = exprLen(expr);
	int insert_res = 0;
	for(i = 0; i < len; i++)
	{
		if(expr[i] == ' ') continue;
		else if(isdigit(expr[i]))	
		{
			pushDigit(expr, len, i);
		}
		else if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^' || expr[i] == '%' )
		{
			int j = i;
			if(expr[i + 1] == ' ')
			{
				for(j = i + 1; expr[j] != ' '; j++);
			}
			if(expr[i] == expr[j] || (expr[i] == '+' && expr[j] == '-') || (expr[i] == '-' && expr[j] == '+') )
			{
				i = j;
				sepUniandbin(expr[i], expr[j]);
			}
			else
			{
					while( !opisEmpty(oper) &&  preceed(optop(oper)) >= preceed(expr[i]) )
					{
						int val1 = valtop(val);
						valpop(&val);

						int val2 = valtop(val);
						valpop(&val);


						char op = optop(oper);
						oppop(&oper);
						valpush(&val, calculate(val1, val2, op));
					}
					oppush(&oper, expr[i]);
				}	
		}
		else if(expr[i] =='(') oppush(&oper, expr[i]);
		else if(expr[i] == ')')
		{
			while(!opisEmpty(oper) && optop(oper) != '(')
			{
				int val1 = valtop(val);
				valpop(&val);

				int val2 = valtop(val);
				valpop(&val);


				char op = optop(oper);
				oppop(&oper);

				valpush(&val, calculate(val1, val2, op));

					}
					  oppop(&oper);
				}
		}

	while(!opisEmpty(oper))
	{

		int val1 = valtop(val);
		valpop(&val);

		int val2 = valtop(val);
		valpop(&val);


		char op = optop(oper);
		oppop(&oper);
		valpush(&val, calculate(val1, val2, op));
	}
  return valtop(val);
}

int calculate(int v1, int v2, char op)
{
	cout<<"operator: "<<op<<endl;
	switch(op)
	{
		case '+': return v2 +  v1;
		case '-': return v2 -  v1;
		case '*': return v2 *  v1;
		case '/': return v2 /  v1;
		case '%': return v2 %  v1;
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

void sepUniandbin(char c, char d)
{
	oppush(&oper,c);
	if(d == '-') uni = d;
	return;
}
void pushDigit(char* expr, int len, int i)
{
	int value = 0;
	while(i < len && isdigit(expr[i]))
	{
		value = value * 10 + (expr[i] - '0');
		i++;
	}
	switch(uni)
	{
		case '-': value = value * (-1);
					uni == ' ';
					break;
		case '+': value = value;
					uni == ' ';
					break;
		case '*': value = value * (-1);
					uni == ' ';
					break;
		case '/': value = value * (-1);
					uni == ' ';
					break;
		case '%': value = value * (-1);
					uni == ' ';
					break;
		case '^': value = value * (-1);
					uni == ' ';
		
		//default: cout<<"Error in expression"<<endl;			
	}
	valpush(&val, value);
}
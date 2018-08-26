#include<iostream>
#include "Stack.h";
using namespace std;

sturct node
{
	char data;
	struct node* next;
};

void push(struct node* top, char c)
{
	struct node* newnode = new node;
	newnode->data = c;
	if(top == NULL)
	{

	}
}

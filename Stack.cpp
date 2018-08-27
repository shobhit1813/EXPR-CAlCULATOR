#include<iostream>
#include<climits>
#include "Stack.h"
using namespace std;


void oppush(opStack* top, char c)
{
	opStack* newnode = new node1;
	newnode->data = c;
	newnode->next = NULL;
	if(top == NULL) top = newnode;
	else
	{
		newnode->next = top;
		top = newnode;
	}
	return;
}

int optop(opStack* head)
{
	return head->data;
}

int oppop(opStack* top)
{
	if(opisEmpty(top)) return INT_MIN;
	opStack *tmp = top;
	top = top->next;
	int popped = tmp->data;
	free(tmp);
	return popped;
}

bool opisEmpty(opStack* top)
{
	return !top;
}


void valpush(valStack* top, char c)
{
	cout<<"pushed"<<endl;
	valStack* newnode = new node2;
	newnode->data = c;
	newnode->next = NULL;
	if(top == NULL) top = newnode;
	else
	{
		newnode->next = top;
		top = newnode;
	}
	return;
}

int valtop(valStack* head)
{
	return head->data;
}

int valpop(valStack* top)
{
	if(valisEmpty(top)) return INT_MIN;
	valStack* tmp = top;
	top = top->next;
	int popped = tmp->data;
	free(tmp);
	return popped;
}

bool valisEmpty(valStack* top)
{
	return !top;
}
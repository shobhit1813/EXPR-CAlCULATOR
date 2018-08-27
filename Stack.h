#ifndef _Stack
#define _Stack
#endif

typedef struct node1
{
	char data;
	struct node1* next;
}opStack;

typedef struct node2
{
	int data;
	struct node2* next;
}valStack;

int optop(struct node1*);
int oppop(struct node1**);
void oppush(struct node1**, char);
bool opisEmpty(struct node1*);

int valtop(struct node2*);
int valpop(struct node2**);
void valpush(struct node2**, char);
bool valisEmpty(struct node2*);
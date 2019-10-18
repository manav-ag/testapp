#include <stdio.h>
#include<stdlib.h>
typedef struct stack1
{
	int ch;
	struct stack1 * next;
}stack;
stack * push(stack * root,int ch)
{
	stack* temp=malloc(sizeof(stack));
	temp->ch=ch;
	if(root==NULL)
	{
		root=temp;
		temp->next=NULL;
		return(root);
	}
	temp->next=root;
	root=temp;
	return(root);
}
int peek(stack * root)
{
	if(root!=NULL)
		return(root->ch);
}
stack * pop(stack * root)
{	
	if(root==NULL)
		return(root);
	root=root->next;
	return(root);
}
void main(int argc,char * argv)
{
	int n;
	printf("Enter the number:");
	scanf("%d",&n);
	int x=0;
	stack * root=malloc(sizeof(stack));
	while(x!=32)
	{
		root=push(root,n%2);
		x=x+1;
		n=n/2;
	}
	x=0;
	while(x!=32)
	{
		int a=root->ch;
		printf("%d",a);
		root=pop(root);
		x=x+1;
	}
}

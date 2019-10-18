#include<stdio.h>
#include<stdlib.h>
typedef struct qnode
{
	int key;
	struct qnode * next;
}qnode;
typedef struct queue
{
	qnode * front,* rear;
}queue;
qnode * newNode(int key)
{
	qnode * temp=malloc(sizeof(qnode));
	temp->key=key;
	temp->next=NULL;
}
queue * createqueue(void)//good programming practice to pass void
{
	queue * new=malloc(sizeof(queue));
	new->front=NULL;
	new->rear=NULL;
}
void enqueue(queue * q,int value)
{
	qnode * temp=newNode(value);
	if(q->front==NULL)
	{
		q->front=temp;
		q->rear=temp;
		return;
	}
	q->rear->next=temp;
	q->rear=temp;
	return;
}
qnode * dequeue(queue * q)
{
	if(q->front==NULL)
		return(NULL);
	qnode * temp=q->front;
	q->front=q->front->next;
	return(temp);
}
void show_queue(queue * q)
{
	qnode  * temp=q->front;
	if(q->front==NULL)
	{
		printf("Empty\n");
		return;
	}
	while(temp!=q->rear)
	{
		printf(" %d ",temp->key);
		temp=temp->next;
	}
	printf(" %d \n",temp->key);
}
void delete_queue(queue * q)
{
	free(q);
}
int main(int argc,char * argv)
{
	queue * q=createqueue();
	char choice;
	int value;
	qnode * temp;
	if(q==NULL)
	{
		printf("Unable to create queue");
		exit(2);
	}
	while(1)
	{
		printf("Key in your choice i-insert d-delete s-show q-quit:");
		scanf(" %c",&choice);
		if(choice=='q')
			break;
		switch(choice)
		{
			case'i':
				printf("Key in the value:");
				scanf("%d",&value);
				enqueue(q,value);
				break;
			case'd':
				if((temp=dequeue(q))!=NULL)
				{
					printf("The key value is: %d\n",temp->key);
					free(temp);
				}
				break;
			case's':
				show_queue(q);
				break;
			default:
				break;
		}
	}
	delete_queue(q);
	return(0);
}

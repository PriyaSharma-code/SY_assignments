#include<stdio.h>
#include<stdlib.h>
struct pizza
{
	int id, qnt;
	char name[50];
	char add[100];
};
struct pizza p[3];
int rear = -1;
int front = -1;
int id = 1;
int is_empty()
{
	if (rear == front)
		return 1;
	else
		return 0;
}
int is_full()
{
	if (rear == 2)
		return 1;
	else
		return 0;
}
void place()
{
	if (is_full() == 0)
	{
		rear++;
		p[rear].id = id++;
		printf("\nEnter name : ");
		scanf(" %s", p[rear].name);
		printf("\nEnter Address : ");
		scanf(" %s", p[rear].add);
		printf("\nEnter Quantity : ");
		scanf("%d", &p[rear].qnt);
	}
	else
	{
		printf("\nOrder queue is full ! ! !");
	}
}
void dispatch()
{
	if (is_empty() == 0)
	{
		front++;
		printf("\nDispatched order is : ");
		printf("\nID : %d", p[front].id);
		printf("\nName : %s", p[front].name);
		printf("\nAddress : %s", p[front].add);
		printf("\nQuantity : %d", p[front].qnt);
	}
	else
	{
		printf("\nNo Order in queue to Dispatch");
	}
}
void disp()
{
	printf("\n The Queue is : ");
	int i;
	for (i = front + 1; i <= rear; i++)
	{
		printf("\nID : %d", p[i].id);
		printf("\nName : %s", p[i].name);
		printf("\nAddress : %s", p[i].add);
		printf("\nQuantity : %d", p[i].qnt);
	}
}
int main()
{
	int c = 0;
	while (1)
	{
		printf("\n\n1.Place Order\n2.Dispatch order\n3.Display pending orders\n4.Exit\n\nEnter your choice : ");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
		{
			place();
			break;
		}
		case 2:
		{
			dispatch();
			break;
		}
		case 3:
		{
			if (is_empty() == 0)
				disp();
			else
			{
				printf("\nNo Order Pending");
			}
			break;
		}
		case 4:
		{
			exit(0);
		}
		default:
		{
			printf("\nWrong choice Try again\n");
			break;
		}
		}
	}
	return 0;
}

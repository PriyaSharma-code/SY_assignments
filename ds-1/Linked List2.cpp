#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
struct Node* p, * temp;
void createFirstLinkedList(struct Node* head)
{
	int i, n, item;
	printf("Enter the number of nodes:");
	scanf_s("%d", &n);
	p = head;
	for (i = 0; i < n; i++)
	{
		printf("Enter the value of node:");
		scanf_s("%d", &item);
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = item;
		temp->next = NULL;
		p->next = temp; //Link the nodes
		p = p->next; //jump to the current node
	}
}
void createSecondLinkedList(struct Node* head)
{
	int i, n, item;
	printf("Enter the number of nodes:");
	scanf_s("%d", &n);
	p = head;
	for (i = 0; i < n; i++)
	{
		printf("Enter the value of node:");
		scanf_s("%d", &item);
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = item;
		temp->next = NULL;
		p->next = temp; //Link the nodes
		p = p->next; //jump to the current node
	}
}
void displayList(struct Node* head)
{
	p = head->next;
	while (p != NULL)
	{
		printf("Node Element: %d\n", p->data);
		p = p->next;
	}
}
int getCount(struct Node* head)
{
	int count = 0; // Initialize count
	struct Node* current = head->next; // Initialize current
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}
void insertByLocation(struct Node* head)
{
	int i = 1, pos;
	temp = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter the position:");
	scanf_s("%d", &pos);
	if (pos > getCount(head))
	{
		printf("Invalid Position");
	}
	else {
		p = head->next;
		while (i < pos)
		{
			p = p->next;
			i++;
		}
		printf("Enter Data:");
		scanf_s("%d", &temp->data);
		temp->next = p->next;
		p->next = temp;
	}
}
void deleteByLocation(struct Node* head)
{
	struct Node* nextNode;
	int pos, i = 1;
	temp = head->next;
	printf("Enter the position:");
	scanf_s("%d", &pos);
	while (i < pos - 1)
	{
		temp = temp->next;
		i++;
	}
	nextNode = temp->next;
	temp->next = nextNode->next;
	free(nextNode);
}
struct Node* sort(struct Node* head)
{
	struct Node* ptr, * cpt;
	int temp;
	ptr = head->next;
	while (ptr->next != NULL)
	{
		cpt = ptr->next;
		while (cpt != NULL)
		{
			if (ptr->data > cpt->data)
			{
				temp = ptr->data;
				ptr->data = cpt->data;
				cpt->data = temp;
			}
			cpt = cpt->next;
		}
		ptr = ptr->next;
	}
	return head;
}
void reverseList(struct Node* head)
{
	struct Node* prevNode, * currentNode, * nextNode;
	prevNode = NULL;
	currentNode = head->next;
	while (currentNode != NULL)
	{
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}
	head->next = prevNode;
	printf("Reversed List is:\n\n");
	displayList(head);
}
void mergeLists(struct Node* head1, struct Node* head2)
{
	struct Node* curr1, * curr2;
	head1 = sort(head1);
	head2 = sort(head2);
	int flag;
	curr1 = head1->next;
	curr2 = head2->next;
	if (curr1->data < curr2->data)
	{
		temp = head1;
		flag = 1;
	}
	else
	{
		temp = head2;
		flag = 0;
	}
	while (curr1 != NULL && curr2 != NULL)
	{
		if (curr1->data < curr2->data)
		{
			temp->next = curr1;
			temp = curr1;
			curr1 = curr1->next;
		}
		else
		{
			temp->next = curr2;
			temp = curr2;
			curr2 = curr2->next;
		}
	}
	if (curr1 == NULL)
	{
		temp->next = curr2;
	}
	if (curr2 == NULL)
	{
		temp->next = curr1;
	}
	if (flag == 1)
	{
		displayList(head1);
	}
	else
	{
		displayList(head2);
	}
}
int main()
{
	struct Node* head1, * head2;
	head1 = (struct Node*)malloc(sizeof(struct Node));
	head2 = (struct Node*)malloc(sizeof(struct Node));
	int ch, c;
	while (1)
	{
		printf("********");
		printf("\nMenu:");
		printf("\n1.Create First Linked List\n2.Create Second Linked List\n3.Display List\n4.Insert Node At Given Position\n5.Delete Node From Specific Location\n6.Sort List\n7.Reverse List\n8.Merge Lists\n9.Get Length of List\n");
			printf("Enter your choice: ");
		scanf_s("%d", &ch);
		printf("********\n");
		switch (ch)
		{
		case 1: createFirstLinkedList(head1);
			break;
		case 2: createSecondLinkedList(head2);
			break;
		case 3:displayList(head1);
			break;
		case 4:insertByLocation(head1);
			break;
		case 5:deleteByLocation(head1);
			break;
		case 6:sort(head1);
			displayList(head1);
			break;
		case 7:reverseList(head1);
			break;
		case 8:mergeLists(head1, head2);
			break;
		case 9:printf("The Length of linked list is: %d", getCount(head1));
			break;
		}
		printf("\n Do you want to continue(1/0)");
		scanf_s("%d", &c);
	}
	return 0;
}

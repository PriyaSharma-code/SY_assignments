#include<iostream>
#include <stdlib.h>
using namespace std;


// Create a node
struct Node {
    int item;
    struct Node* next;
};

void insertAtBeginning(struct Node** ref, int data) {
    // Allocate memory to a node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // insert the item
    new_node->item = data;
    new_node->next = (*ref);

    // Move head to new node
    (*ref) = new_node;
}


void insertAtEnd(struct Node** ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *ref;
    struct Node* save;
    new_node->item = data;
    new_node->next = NULL;

    if (*ref == NULL) {
        *ref = new_node;
        return;
    }
    else {
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
    }
    return;
}

void deleteNode(struct Node** ref) {
    struct Node* temp = *ref;
    struct Node* prev = NULL;
    // If the key is not present
    if (temp == NULL)
    {
        return;
    }
    else {
        if (temp->next == NULL) {
            free(temp);
            return;
        }
        else {
            while (temp->next->next != NULL) {
                temp = temp->next;
            }

            // Remove the node
            prev = temp->next;
            temp->next = NULL;
            free(prev);
            return;
        }
    }
    return;
}

// Print the linked list
void printList(struct Node** node) {
    struct Node* temp = *node;
    if (temp == NULL) {
        printf("\nLinked List is empty");
        return;
    }
    else {
        while (temp->next != NULL) {
            printf(" %d --->", temp->item);
            temp = temp->next;
        }
        printf(" %d --->", temp->item);
        return;
    }
    return;
}

// Driver program
int main() {
    struct Node* head = NULL;
    int a=0;
    int n=0;
    while (n != 5) {
        printf("\nMenu:\n");
         printf("1.Insert Node in Begining\n");
         printf("2.Insert node at End\n");
         printf("3.Display Linked List\n");
         printf("4.Delete Node \n");
         printf("5.Exit\n");
         printf("Enter your choice:\n");
         scanf_s("%d", &n);

        switch (n) {

        case 1:
            printf("Enter element to insert:\n");
            scanf_s("%d", &a);
            insertAtBeginning(&head, a);
            break;
        case 2:
            printf("Enter element to insert:\n");
            scanf_s("%d", &a);
            insertAtEnd(&head, a);
            break;
        case 3:
            printf("Linked list: \n");
            printList(&head);
            break;
        case 4:
            printf("\nLast element deleted ");
            deleteNode(&head);
            break;
        case 5:
            exit(1);
        }
    }

}

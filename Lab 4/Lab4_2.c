// Write a function to insert a node in the linked list a) at beginning b) at end c) at specific position (in btw).

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int ndata)
{
    struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
    nnode->data = ndata;
    nnode->next = (*head);
    (*head) = nnode;
}

void insertAtEnd(struct Node **head, int ndata)
{
    struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head;
    nnode->data = ndata;
    nnode->next = NULL;

    if (*head == NULL)
    {
        *head = nnode;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = nnode;
}

void insertAtPosition(struct Node **head, int ndata, int position)
{
    if (position < 1)
    {
        printf("Position should be >= 1.\n");
        return;
    }

    struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
    nnode->data = ndata;

    if (position == 1)
    {
        nnode->next = *head;
        *head = nnode;
        return;
    }

    struct Node *temp = *head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position is greater than the number of nodes.\n");
        return;
    }
    
    nnode->next = temp->next;
    temp->next = nnode;
}
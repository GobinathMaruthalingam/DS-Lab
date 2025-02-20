// Create 2 linked lists, concatenate these 2 lists and create a 3rd linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
    nnode->data = data;
    nnode->next = NULL;
    return nnode;
}

// Function to append a node to the end of the list
void appendNode(struct Node **head, int data)
{
    struct Node *nnode = createNode(data);

    if (*head == NULL)
    {
        *head = nnode;
    }

    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nnode;
    }
}

// Concatenating two lists
struct Node *concatenateLists(struct Node *head1, struct Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    struct Node *temp = head1;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head2;
    return head1;
}

// Printing the list
void printList(struct Node *head)
{
    struct Node *temp = head;
    
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    struct Node *concatenatedList = NULL;

    // Create first linked list
    appendNode(&list1, 1);
    appendNode(&list1, 2);
    appendNode(&list1, 3);

    // Create second linked list
    appendNode(&list2, 4);
    appendNode(&list2, 5);
    appendNode(&list2, 6);

    // Concatenating the two lists
    concatenatedList = concatenateLists(list1, list2);

    // Final Print
    printList(concatenatedList);

    return 0;
}
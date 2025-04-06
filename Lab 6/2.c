// 2) Write a program to delete and insert a node in doubly liked list a) at beginning b) at end c) at specific point

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* nNode = (Node*)malloc(sizeof(Node));
    nNode->data = value;
    nNode->prev = NULL;
    nNode->next = NULL;
    return nNode;
}

// Insert at beginning
Node* insertAtBeg(Node* head, int value) {
    Node* nNode = createNode(value);
    if (head != NULL) {
        nNode->next = head;
        head->prev = nNode;
    }
    return nNode;
}

// Insert at end
Node* insertAtEnd(Node* head, int value) {
    Node* nNode = createNode(value);
    if (head == NULL) {
        return nNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nNode;
    nNode->prev = temp;
    return head;
}

// Insert at specific position
Node* insertAtPosition(Node* head, int pos, int value) {
    if (pos <= 1) return insertAtBeg(head, value);

    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        return insertAtEnd(head, value);
    }

    Node* nNode = createNode(value);
    nNode->next = temp->next;
    nNode->prev = temp;
    temp->next->prev = nNode;
    temp->next = nNode;

    return head;
}

// Delete from beginning
Node* deleteFromBeg(Node* head) {
    if (head == NULL) return NULL;

    Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
    return head;
}

// Delete from end
Node* deleteFromEnd(Node* head) {
    if (head == NULL) return NULL;

    Node* temp = head;
    if (temp->next == NULL) {
        free(temp);
        return NULL;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    return head;
}

// Delete from specific position
Node* deleteFromPosition(Node* head, int pos) {
    if (pos <= 1) return deleteFromBeg(head);

    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return head;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    return head;
}

// Display the list
void displayList(Node* head) {
    printf("List: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, value, pos;

    while (1) {
        printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n");
        printf("4.Delete from beginning\n5.Delete from end\n6.Delete from position\n");
        printf("7.Display\n8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            head = insertAtBeg(head, value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            head = insertAtEnd(head, value);
            break;
        case 3:
            printf("Enter position and value: ");
            scanf("%d %d", &pos, &value);
            head = insertAtPosition(head, pos, value);
            break;
        case 4:
            head = deleteFromBeg(head);
            break;
        case 5:
            head = deleteFromEnd(head);
            break;
        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            head = deleteFromPosition(head, pos);
            break;
        case 7:
            displayList(head);
            break;
        case 8:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

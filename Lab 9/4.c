/*
4) Reconstruct a Binary tree for the given Inorder, Preorder (or Postorder).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node *nNode(char data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int findIndex(char arr[], int start, int end, char value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

Node *usingPre(char in[], char pre[], int start, int end, int *index) {
    if (start > end)
        return NULL;

    char curr = pre[(*index)++];
    Node *root = nNode(curr);

    if (start == end)
        return root;

    int mid = findIndex(in, start, end, curr);
    root->left = usingPre(in, pre, start, mid - 1, index);
    root->right = usingPre(in, pre, mid + 1, end, index);

    return root;
}

Node *usingPost(char in[], char post[], int start, int end, int *index) {
    if (start > end)
        return NULL;

    char curr = post[(*index)--];
    Node *root = nNode(curr);

    if (start == end)
        return root;

    int mid = findIndex(in, start, end, curr);
    root->right = usingPost(in, post, mid + 1, end, index);
    root->left = usingPost(in, post, start, mid - 1, index);

    return root;
}

void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

int main() {
    char inord[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char preord[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    char postord[] = {'D', 'E', 'B', 'F', 'C', 'A'};
    int len = 6;
    int choice;

    while (1) {
        printf("\n--- Tree Reconstruction ---\n");
        printf("1. Build from Inorder + Preorder\n");
        printf("2. Build from Inorder + Postorder\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        Node *root = NULL;

        if (choice == 1) {
            int preIndex = 0;
            root = usingPre(inord, preord, 0, len - 1, &preIndex);
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
        }
        else if (choice == 2) {
            int postIndex = len - 1;
            root = usingPost(inord, postord, 0, len - 1, &postIndex);
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
        }
        else if (choice == 3) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

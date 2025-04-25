// Given a BST and a target value, Find two nodes whose sum is the target value.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* nNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int data) {
    if (root == NULL) return nNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// In-order traversal to store BST elements in array
void storeInorder(Node* root, int arr[], int* index) {
    if (root == NULL) return;
    storeInorder(root->left, arr, index);
    arr[(*index)++] = root->data;
    storeInorder(root->right, arr, index);
}

void findNodes(Node* root, int target) {
    int arr[1000], index = 0;
    storeInorder(root, arr, &index);

    int i = 0, j = index - 1;
    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == target) {
            printf("Pair found: %d + %d = %d\n", arr[i], arr[j], target);
            return;
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }

    printf("No such pair found.\n");
}

int main() {
    Node* root = NULL;
    int n, data, target;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

    findNodes(root, target);

    return 0;
}

/*
Output:
Enter number of nodes: 6
Enter node values:
9 7 6 4 2 5
Enter target sum: 12
Pair found: 5 + 7 = 12
*/
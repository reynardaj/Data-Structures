#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for binary tree node
struct Node
{
    int data;
};

// Function to create a new node with given data
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    return newNode;
}

// Function to insert a node into the binary tree represented as an array
void insertNode(struct Node *tree[], int data, int index)
{
    struct Node *newNode = createNode(data);
    tree[index] = newNode;
}

// Function to display the binary tree represented as an array
void displayTree(struct Node *tree[], int size)
{
    printf("Binary Tree:\n");
    for (int i = 0; i < size; i++)
    {
        if (tree[i] != NULL)
        {
            printf("%d ", tree[i]->data);
        }
        else
        {
            printf("- ");
        }
    }
    printf("\n");
}

int main()
{
    // Array to represent the binary tree
    struct Node *tree[MAX_SIZE] = {NULL};

    // Inserting nodes into the binary tree
    insertNode(tree, 1, 0); // Root
    insertNode(tree, 2, 1); // Left child of root
    insertNode(tree, 3, 2); // Right child of root
    insertNode(tree, 4, 3); // left child of left child
    insertNode(tree, 5, 4); // Right child of left child

    // Displaying the binary tree
    displayTree(tree, 5);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

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
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(int data, int index)
{
}

// traversal
void preorder(Node *curr)
{
    if (!curr)
    {
        return;
    }

    printf("%d,", curr->data);
    preorder(curr->left);
    preorder(curr->right);
}
void inorder(Node *curr)
{
    if (!curr)
    {
        return;
    }

    inorder(curr->left);
    printf("%d,", curr->data);
    inorder(curr->right);
}
void postorder(Node *curr)
{
    if (!curr)
    {
        return;
    }

    postorder(curr->left);
    postorder(curr->right);
    printf("%d,", curr->data);
}

int main(int argc, char const *argv[])
{

    return 0;
}

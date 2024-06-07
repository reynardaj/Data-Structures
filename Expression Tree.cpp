#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} Node;

Node *root = NULL;

Node *createNewNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        puts("Memory allocation failed");
        return NULL;
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isOp(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void insert(Node *curr, int index)
{
    if (/* condition */)
    {
        /* code */
    }
}

int main(int argc, char const *argv[])
{
    char exp[] = "*32";
    root = createNewNode(exp[0]);
    return 0;
}

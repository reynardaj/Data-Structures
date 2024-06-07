#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_new_node(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node *insert_node(Node *root, int value)
{
    // Base case
    if (!root)
    {
        return create_new_node(value);
    }

    // Duplicate handling
    if (value == root->value)
    {
        return NULL;
    }

    // Less than or Greater than values
    if (value < root->value)
    {
        root->left = insert_node(root->left, value);
    }
    else
    {
        root->right = insert_node(root->right, value);
    }
    return root;
}

void visualizeBST(Node *root, int depth)
{
    if (root == NULL)
    {
        return;
    }

    // Print the right subtree
    visualizeBST(root->right, depth + 1);

    // Print current node with indentation
    for (int i = 0; i < depth; i++)
    {
        printf("    ");
    }
    printf("%d\n", root->value);

    // Print the left subtree
    visualizeBST(root->left, depth + 1);
}

void visualize_bst_topdown(struct Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    // Print current node with proper indentation
    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }
    printf("%d\n", root->value);

    // Visualize the left and right subtrees at the next level
    visualize_bst_topdown(root->left, level + 1);
    visualize_bst_topdown(root->right, level + 1);
}

Node *search(Node *root, int key)
{
    // Base cases
    // Key not found
    if (!root)
    {
        return NULL;
    }
    // Found key
    if (root->value == key)
    {
        return root;
    }

    // Continue searching
    if (key < root->value)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}
Node *findLeast(Node *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

Node *delNode(Node *root, int key)
{
    // Base case: empty tree
    if (!root)
    {
        return NULL;
    }

    // Find node to delete
    if (key < root->value)
    {
        root->left = delNode(root->left, key);
    }
    else if (key > root->value)
    {
        root->right = delNode(root->right, key);
    }
    else
    { // Node with the key found

        // Case 1: No child or only right child
        if (!root->left)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right)
        { // Case 2: Only left child
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        { // Case 3: Both children are present
            Node *successor = findLeast(root->right);
            root->value = successor->value;
            root->right = delNode(root->right, successor->value);
        }
    }
    return root;
}

int main(int argc, char const *argv[])
{
    Node *root = create_new_node(7);
    // Insert
    insert_node(root, 9);
    insert_node(root, 3);
    insert_node(root, 5);
    insert_node(root, 12);

    // visualize_bst_topdown(root, 0);
    visualizeBST(root, 0);
    puts("");

    // Search
    // Node *value = search(root, 6);
    // printf("%s\n", value ? "Found" : "Not found");

    // Delete
    puts("After deletion 1");
    delNode(root, 5);
    visualizeBST(root, 0);

    puts("After deletion 2");
    delNode(root, 9);
    visualizeBST(root, 0);

    puts("After deletion 3");
    delNode(root, 7);
    visualizeBST(root, 0);
    return 0;
}

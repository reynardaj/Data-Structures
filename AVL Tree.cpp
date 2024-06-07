#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    Node *left, *right;
    int height;
} Node;

Node *create_new_node(int key)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = key;
    new_node->left = new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

int getHeight(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return root->height;
}

int getBalance(Node *root)
{
    if (!root)
    {
        return 0;
    }

    return getHeight(root->left) - getHeight(root->right);
}

Node *leftRotate(Node *root)
{
    if (!root)
    {
        return NULL;
    }

    Node *newParent = root->right;
    Node *newLeftSubtree = newParent->left;

    newParent->left = root;
    root->right = newLeftSubtree;

    root->height = getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) + 1 : getHeight(root->right) + 1;
    newParent->height = getHeight(newParent->left) > getHeight(newParent->right) ? getHeight(newParent->left) + 1 : getHeight(newParent->right) + 1;

    return newParent;
}

Node *rightRotate(Node *root)
{
    if (!root)
    {
        return NULL;
    }

    Node *newParent = root->left;
    Node *newRightSubtree = newParent->right;

    newParent->right = root;
    root->left = newRightSubtree;

    root->height = getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) + 1 : getHeight(root->right) + 1;
    newParent->height = getHeight(newParent->left) > getHeight(newParent->right) ? getHeight(newParent->left) + 1 : getHeight(newParent->right) + 1;

    return newParent;
}

Node *insert(Node *root, int key)
{
    if (!root)
    {
        return create_new_node(key);
    }

    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root;
    }

    root->height = getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) + 1 : getHeight(root->right) + 1;

    int balance = getBalance(root);
    // case 1 (LL)
    if (balance > 1 && key < root->left->key)
    {
        return rightRotate(root);
    }
    // case 2 (RR)
    else if (balance < -1 && key > root->right->key)
    {
        return leftRotate(root);
    }
    // case 3 (RL)
    else if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // case 4 (LR)
    else if (balance > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    return root;
}

Node *delNode(Node *root, int key)
{
    if (!root)
    {
        return NULL;
    }

    if (key < root->key)
    {
        root->left = delNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = delNode(root->right, key);
    }
    else
    {
        if (!root->left)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            Node *predecessor = root->left;
            while (predecessor->right)
            {
                predecessor = predecessor->right;
            }

            root->key = predecessor->key;
        }
    }

    root->height = getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) + 1 : getHeight(root->right) + 1;

    int balance = getBalance(root);
    // case 1 (LL)
    if (balance > 1 && key < root->left->key)
    {
        return rightRotate(root);
    }
    // case 2 (RR)
    else if (balance < -1 && key > root->right->key)
    {
        return leftRotate(root);
    }
    // case 3 (RL)
    else if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // case 4 (LR)
    else if (balance > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    return root;
}

void visualizeAVL(Node *root, int depth)
{
    if (root == NULL)
    {
        return;
    }

    // Print the right subtree
    visualizeAVL(root->right, depth + 1);

    // Print current node with indentation
    for (int i = 0; i < depth; i++)
    {
        printf("    ");
    }
    printf("%d\n", root->key);

    // Print the left subtree
    visualizeAVL(root->left, depth + 1);
}

int main(int argc, char const *argv[])
{
    Node *root = create_new_node(1);
    root = insert(root, 2);
    puts("insert 2");
    visualizeAVL(root, 0);
    puts("");

    root = insert(root, 3);
    puts("insert 3");
    visualizeAVL(root, 0);
    puts("");

    root = insert(root, 6);
    puts("insert 6");
    visualizeAVL(root, 0);
    puts("");

    root = insert(root, 5);
    puts("insert 5");
    visualizeAVL(root, 0);
    puts("");

    return 0;
}

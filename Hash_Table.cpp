#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
*** Hash table using linear probing ***
Hashing function : Mid-square
*/

#define MAX_STR_LEN 50
#define TABLE_LEN 10

typedef struct Node
{
    char name[MAX_STR_LEN];
} Node;

Node *hash_table[TABLE_LEN] = {NULL};

int hash(char name[])
{
    long long int sum = 0;
    for (int i = 0; i < strlen(name); i++)
    {
        sum += name[i];
    }
    return sum / 100 % TABLE_LEN;
}

void insert(char name[])
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    int key = hash(name);
    // kalo kosong
    if (!hash_table[key])
    {
        hash_table[key] = new_node;
    }
    else
    {
        while (hash_table[key])
        {
            key++;
            key %= TABLE_LEN;
        }
        hash_table[key] = new_node;
    }
}

int search(char name[])
{
    int key = hash(name);
    if (hash_table[key] && strcmp(hash_table[key]->name, name) == 0)
    {
        return key;
    }
    else
    {
        for (int i = 0; i < TABLE_LEN - 1; i++)
        {
            int new_key = (key + i + 1) % TABLE_LEN;
            if (!hash_table[new_key])
            {
                continue;
            }

            if (strcmp(hash_table[new_key]->name, name) == 0)
            {
                return new_key;
            }
        }
        return -1;
    }
}

void del(char name[])
{
    int searchIdx = search(name);
    if (searchIdx != -1)
    {
        free(hash_table[searchIdx]);
        hash_table[searchIdx] = NULL;
    }
    else
    {
        puts("name doesn't exist");
    }
}

void view_table()
{
    for (int i = 0; i < TABLE_LEN; i++)
    {
        printf("%d: %s\n", i, hash_table[i] ? hash_table[i]->name : "-");
    }
}

void view_table_elems()
{
    for (int i = 0; i < TABLE_LEN; i++)
    {
        printf("%d\n", hash_table[i]);
    }
}

int main(int argc, char const *argv[])
{
    insert("Andy");
    insert("Andrew");
    insert("Kelson");
    insert("Steven");
    insert("Reynard");
    insert("Gio");
    insert("Jonathan");
    view_table();

    int foundIdx = search("Jonatin");
    printf("found %s in index %d\n", foundIdx != -1 ? hash_table[foundIdx]->name : "nothing", foundIdx);

    puts("After deletion");
    del("Jonathan");
    del("Andrew");
    del("Gio");
    del("Kelson");
    del("Steven");
    del("Reynard");
    del("Andy");
    view_table();

    return 0;
}

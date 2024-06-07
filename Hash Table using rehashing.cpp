#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
sering keluar : mid square, division, folding
                linear probing
*/

#define LOAD_FACTOR 0.7
#define STR_LEN 50
#define TABLE_SIZE 7

typedef struct Bucket
{
    char key[STR_LEN];
    char value[STR_LEN];
    struct Bucket *next;
} Bucket;

Bucket *hashTable[TABLE_SIZE] = {NULL};

Bucket *createNewBucket(char key[], char value[])
{
    Bucket *newBucket = (Bucket *)malloc(sizeof(Bucket));
    strcpy(newBucket->key, key);
    strcpy(newBucket->value, value);
    newBucket->next = NULL;
    return newBucket;
}

int hash(char key[])
{
    int len = strlen(key);
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

void rehash()
{
}
int nBuckets = 0;
void insert(char key[], char value[])
{
    int keyIdx = hash(key);
    Bucket *newBucket = createNewBucket(key, value);
    double limit = ceil(TABLE_SIZE * LOAD_FACTOR);
    if (nBuckets / TABLE_SIZE < limit)
    {
        // insert to table
        if (!hashTable[keyIdx])
        {
            hashTable[keyIdx] = newBucket;
        }
        else
        {
            Bucket *curr = hashTable[keyIdx];
            while (curr->next)
            {
                curr = curr->next;
            }
            curr->next = newBucket;
        }
    }
    else
    {
        // rehash to new table
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}

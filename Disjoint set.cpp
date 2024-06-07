#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 10

int parent[MAX_LEN];
int rank[MAX_LEN];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void make_set(int v)
{
    parent[v] = v;
    rank[v] = 0;
}

// Naive Implementation
// int find_set(int v)
// {
//     if (parent[v] == v)
//     {
//         return v;
//     }
//     return find_set(parent[v]);
// }

// Path compression
int find_set(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

// Naive implementation
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b)
    {
        return;
    }
    parent[b] = a;
}

// Union by rank
void union_set_by_rank(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if (a != b)
    {
        if (rank[b] > rank[a])
        {
            swap(&b, &a);
        }
        if (rank[a] == rank[b])
        {
            rank[a]++;
        }

        parent[b] = a;
    }
}

void print_set()
{
    printf("Element: ");
    for (int i = 0; i < MAX_LEN; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    printf("Parent : ");
    for (int i = 0; i < MAX_LEN; i++)
    {
        printf("%d ", parent[i]);
    }
    printf("\n");

    printf("Rank   : ");
    for (int i = 0; i < MAX_LEN; i++)
    {
        printf("%d ", rank[i]);
    }
    printf("\n");

    printf("Set    : ");
    for (int i = 0; i < MAX_LEN; i++)
    {
        printf("%d ", find_set(i));
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{

    for (int i = 0; i < 10; i++)
    {
        make_set(i);
    }

    print_set();
    union_set_by_rank(8, 7);
    puts("");
    print_set();
    union_set_by_rank(2, 3);
    puts("");
    print_set();
    union_set_by_rank(3, 7);
    puts("");
    print_set();
    return 0;
}

#include <stdio.h>

#define MAX 10

int stack[MAX];
// top starts at -1
void push(int x, int *top)
{
    if (*top < MAX && *top >= -1)
    {
        stack[++(*top)] = x;
    }
    else
    {
        puts("out of bound");
    }
}

void pop(int *top)
{
    (*top)--;
}

void top(int top)
{
    if (top < MAX && top >= 0)
    {
        printf("%d\n", stack[top]);
    }
    else
    {
        puts("out of bound");
    }
}

int main(int argc, char const *argv[])
{
    int topNum = -1;
    push(2, &topNum);
    top(topNum);
    push(5, &topNum);
    top(topNum);
    push(8, &topNum);
    top(topNum);
    pop(&topNum);
    top(topNum);
    pop(&topNum);
    top(topNum);
    pop(&topNum);
    top(topNum);
    return 0;
}

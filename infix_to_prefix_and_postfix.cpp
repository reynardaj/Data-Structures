#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct Node
{
    char data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

void init(Stack *s)
{
    s->top = NULL;
}

int isEmpty(Stack *s)
{
    return s->top == NULL;
}

void push(Stack *s, char value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

char getTop(Stack *s)
{
    return s->top->data;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        puts("Stack is empty");
        return -1;
    }

    Node *del = s->top;
    int temp = del->data;
    s->top = s->top->next;
    free(del);
    return temp;
}

int isOp(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char c)
{
    switch (c)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void infixToPrefix(Stack stack, char infix[], char prefix[])
{
    int len = strlen(infix);
    char infixCopy[50];
    strcpy(infixCopy, infix);

    int index = 0;

    for (int i = 0; i < len; i++)
    {
        char c = infixCopy[len - i - 1];
        if (isdigit(c))
        {
            // add to prefix
            prefix[index++] = c;
        }
        else if (isOp(c))
        {
            // push operator to stack given operator has higher precedence
            if (isEmpty(&stack) || (getPrecedence(c) > getPrecedence(getTop(&stack))))
            {
                push(&stack, c);
            }
            else
            {
                // empty stack if current precedence less or equal to operators in stack
                char top = getTop(&stack);
                while (isOp(top) && getPrecedence(c) <= getPrecedence(top))
                {
                    prefix[index++] = pop(&stack);
                    if (isEmpty(&stack))
                    {
                        break;
                    }
                    else
                    {
                        top = getTop(&stack);
                    }
                }
                push(&stack, c);
            }
        }
        else if (c == ')')
        {
            push(&stack, c);
        }
        else if (c == '(')
        {
            char top = getTop(&stack);
            while (isOp(top) && c != ')')
            {
                prefix[index++] = pop(&stack);
                top = getTop(&stack);
            }
            pop(&stack);
        }
        else
        {
            puts("invalid character!");
        }
    }

    // empty remaining operators in stack
    while (!isEmpty(&stack))
    {
        prefix[index++] = pop(&stack);
    }

    prefix[index] = '\0';
    strrev(prefix);
}

void infixToPostfix(Stack stack, char infix[], char postfix[])
{
    int len = strlen(infix);
    char infixCopy[50];
    strcpy(infixCopy, infix);

    int index = 0;

    for (int i = 0; i < len; i++)
    {
        char c = infixCopy[i];
        if (isdigit(c))
        {
            // add to prefix
            postfix[index++] = c;
        }
        else if (isOp(c))
        {
            // push operator to stack given operator has higher precedence
            if (isEmpty(&stack) || (getPrecedence(c) > getPrecedence(getTop(&stack))))
            {
                push(&stack, c);
            }
            else
            {
                // empty stack if current precedence less or equal to operators in stack
                char top = getTop(&stack);
                while (isOp(top) && getPrecedence(c) <= getPrecedence(top))
                {
                    postfix[index++] = pop(&stack);
                    if (isEmpty(&stack))
                    {
                        break;
                    }
                    else
                    {
                        top = getTop(&stack);
                    }
                }
                push(&stack, c);
            }
        }
        else if (c == '(')
        {
            push(&stack, c);
        }
        else if (c == ')')
        {
            char top = getTop(&stack);
            while (isOp(top) && c != '(')
            {
                postfix[index++] = pop(&stack);
                top = getTop(&stack);
            }
            pop(&stack);
        }
        else
        {
            puts("invalid character!");
        }
    }

    // empty remaining operators in stack
    while (!isEmpty(&stack))
    {
        postfix[index++] = pop(&stack);
    }

    postfix[index] = '\0';
}

int main(int argc, char const *argv[])
{
    Stack s1;
    init(&s1);

    char infix[] = "5+(3*2)-7/2";
    printf("  infix: %s\n", infix);

    char prefix[50];
    infixToPrefix(s1, infix, prefix);
    printf(" prefix: %s\n", prefix);

    Stack s2;
    init(&s2);

    char postfix[50];
    infixToPostfix(s2, infix, postfix);
    printf("postfix: %s\n", postfix);
    return 0;
}

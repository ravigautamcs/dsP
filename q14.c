// 14. Program to implement a stack using a linked list

#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("stack is full\n");
    }
    else
    {
        t->data = x; //storing the data
        t->next = top;
        top = t;
    }
}

void Display()
{

    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{

    push(10);
    push(30);
    push(20);
    Display();

    return 0;
}
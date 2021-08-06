// Program to insert a node in a linked list and delete a node from a linked list.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Insert(int pos, int x)
{
    struct Node *p, *t;
    if (pos == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = first;
        first = t;
    }
    else if (pos > 0)
    {
        p = first;
        for (int i = 0; i < pos - 1 && p; i++)
        {
            p = p->next;
        }
        if (p)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}

void Display(struct Node *p)
{
    while (p != 0)
    {
        printf("%d\t", p->data);
        p = (p->next);
    }
    printf("\n");
}

int main(){

    int A[] = {3, 5, 10, 15, 16};
    create(A, 5);
    Display(first);
    printf("entering the 230 at the posittion 2 :\t");
    Insert(2,230);
    Display(first);

    return 0;
}
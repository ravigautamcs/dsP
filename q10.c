// 10. Program to reverse a linked list.

// Program to print the elements of a linked list in a reverse order without disturbing the linked list.


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

struct Node * reverse(struct Node *p){
    struct Node *prvs=NULL, *crr=p, *nxt;
    while(crr!=NULL){
        nxt=crr->next;
        crr->next=prvs;
        prvs=crr;
        crr=nxt;
    }
    return prvs;
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
    printf("List after reversing the elements :\t");
    Display(reverse(first));
    
    return 0;
}
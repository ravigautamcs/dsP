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

void displayReverse(struct Node *p){

    int arr[5];
    int i=0;
    while(p!=NULL){
        arr[i]=p->data;
        p=p->next;
        i++;
    }
    for(int i=4; i>=0; i--){
        printf("%d\t", arr[i]);
    }
    // printf("\n");
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
    printf("printing of the reverse linked list : ");
    displayReverse(first);

    return 0;
}
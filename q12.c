// 12. Program to implement a doubly linked list.

#include <stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n){
    struct Node *t , *last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->prev=first->next=NULL;
    first->data=A[0];

    last=first;

    for(int i=1; i<n; i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }

}

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d\t", p->data);
        p=p->next;
    }
}


int main(){

    int A[]={1,2,3,4,4,5,6};
    create(A, 7);
    Display(first);

    return 0;
}
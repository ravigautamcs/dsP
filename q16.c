// 16. Program to implement a queue using a linked list.


#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*first=NULL, *rear=NULL;

void enqueue(int x){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Queue is FULL\n");
    }
    else{
        t->data=x;
        t->next=NULL;
        if(first==NULL){
            first=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }
}


void display(){
    struct Node *p=first;
    
        while(p){
            printf("%d\n", p->data);
            p=p->next;
        }
    
}

int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    return 0;
}
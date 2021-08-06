// 19. Program to implement a priority queue using a linked list


#include<stdio.h>
#include<stdlib.h>

struct Node {
    int priority;
    int data;
    struct Node *next;
}*front=NULL;

void insert(int data, int priority){
    struct Node *temp, *q;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->priority=priority;

    if(front == NULL || priority <front->priority){
        temp->next=front;
        front=temp;
    }
    else{
        q=front;
        while(q->next!=NULL && q->next->priority <=priority){
            q=q->next;
        }
        temp->next=q->next;
        q->next=temp;
    }

}

void del(){
    struct Node *temp;
    if(front==NULL){
        printf("\nQueue is Empty");
    }
    else{
        temp =front;
        printf("\n deleted element is %d.", temp->data);
        front=front->next;
        free(temp);
    }
}

void display(){
    struct Node *p;
    p=front;
    if(front==NULL){
        printf("\nqueue is empty.");
    }
    else{
        while(p!=NULL){
            printf("%d      %d\n", p->data, p->priority);
            p=p->next;
        }
    }
}

int main(){

    insert(10,1);
    insert(11,2);
    insert(12,7);
    insert(13,3);
    insert(14,5);

    display();

    return 0;
}
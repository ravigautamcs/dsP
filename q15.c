// 15. Program to implement a queue using an array.

#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front, rear;
    int *Q;
};

void create(struct Queue *q, int size){
    q->size=size;
    q->Q=(int *)malloc(q->size*sizeof(int));
    q->front=q->rear=-1;
}

void enqueue(struct Queue *q, int x){
    if(q->rear==q->size-1){
        printf("Queue is Full\n");
    }
    else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}

void Display(struct Queue q){
    q.front++;
    for(int i=q.front; i<=q.rear; i++){
        printf("%d\n", q.Q[i]);
    }
}


int main(){
    struct Queue q;
    create(&q, 3);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    Display(q);
    return 0;
}
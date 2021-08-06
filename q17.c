// 17. Program to implement a circular queue using an array


#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int f,r;
    int *Q;
};

void create(struct Queue *q){
    printf("enter the size of queue you want to create\n");
    scanf("%d", &q->size);
    q->f=q->r=0; 
    q->Q=(int *)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q, int x){
    if((q->r+1)%q->size==q->f){
        printf("Queue is Full\n");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->Q[q->r]=x;
    }
}


void display(struct Queue q){
    
    
        int i=q.f+1;
        do{
            printf("%d\n", q.Q[i]);
            i=(i+1)%q.size;
        }while(i!=(q.r+1)%q.size);
   
}

int main(){

    struct Queue q;
    create(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(q);

    return 0;
}
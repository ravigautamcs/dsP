// 21. Program to construct a binary tree and display its pre-order, in-order and post-order traversal

#include <stdio.h>
#include<stdlib.h>

struct Node * root=NULL;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front, rear;
    struct Node **Q;  
};

void create(struct Queue *q, int size){
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node * x){
    if((q->rear+1)%q->size==q->front){
        printf("Queue is full");
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

struct Node * dequeue(struct Queue *q){
    struct Node* x =NULL;
    if(q->front==q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}



void Tcreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);


    printf("Enter the value of root\n");
    scanf("%d", &x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        p=dequeue(&q);

        printf("Enter the value of left child of %d \n", p->data);
        scanf("%d", &x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }

        printf("Enter the value of right child of %d \n", p->data);
        scanf("%d", &x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }

}

void preorder(struct Node * p){
    if(p){
        printf("%d\t", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d\t", p->data);
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d\t", p->data);
    }
}

int main()
{
    Tcreate();

    printf("preOrder traversal : ");
    preorder(root);
    printf("\nInOrder Traversal : ");
    Inorder(root);
    printf("\nPostOrder Traversal : ");
    Postorder(root);

    return 0;
}
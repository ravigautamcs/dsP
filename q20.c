// 20. Program to implement a double ended queue using a linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
} *head = NULL, *tail = NULL;

struct node *createNode(int data)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = data;
    t->next = t->prev = NULL;
    return t;
}

void initialize() 
{

    head = createNode(0);
    tail = createNode(0);
    head->next = tail;
    tail->prev = head;
}

void enqueueAtFront(int data)
{
    struct node *newnode, *temp;
    newnode = createNode(data);
    temp = head->next;
    head->next = newnode;
    newnode->prev = head;

    newnode->next = temp;
    temp->prev = newnode;
}

void enqueueAtRear(int data)
{
    struct node *newnode, *temp;
    newnode = createNode(data);

    temp = tail->prev;
    tail->prev = newnode;
    newnode->next = tail;
    newnode->prev = temp;
    temp->next = newnode;
}

void dequeueAtFront()
{

    struct node *temp;
    if (head->next == tail)

    {
        printf("Queue is empty\n");
    }

    else
    {
        temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;

        free(temp);
    }
    return;
}

void dequeueAtRear()
{
    struct node *temp;
    if (tail->prev == head)

    {
        printf("Queue is empty\n");
    }
    else
    {

        temp = tail->prev;
        tail->prev = temp->prev;
        temp->prev->next = tail;
        free(temp);
    }

    return;
}

void display()
{
    struct node *temp;

    if (head->next == tail)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = head->next;
    while (temp != tail)
    {

        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{

    initialize();

    enqueueAtFront(10);
    enqueueAtFront(20);
    enqueueAtFront(30);

    enqueueAtRear(40);
    enqueueAtRear(50);
    enqueueAtRear(60);
    dequeueAtFront();
    dequeueAtRear();
    display();
    return 0;
}
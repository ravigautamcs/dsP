// 11. Program to add two polynomials using linked list.


#include <stdio.h>
#include <stdlib.h>
struct node
{
    int pow, coeff;
    struct node *next;
};
struct node *newNode(int val, int pow)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff = val;
    temp->pow = pow;
    temp->next = NULL;
    return temp;
}
void insertionAtHead(struct node **head, int data, int pow)
{
    struct node *temp = newNode(data, pow);
    temp->next = *head;
    *head = temp;
}
void insertionAtTail(struct node **head, int data, int pow)
{
    if (*head == NULL)
    {
        insertionAtHead(head, data, pow);
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct node *new = newNode(data, pow);
    temp->next = new;
    new->next = NULL;
}
struct node *addPolynomials(struct node *a, struct node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }

    struct node *c;
    if (a->pow == b->pow)
    {
        a->coeff = a->coeff + b->coeff;
        c = a;
        c->next = addPolynomials(a->next, b->next);
    }
    else if (a->pow > b->pow)
    {
        c = b;
        c->next = addPolynomials(a, b->next);
    }
    else
    {
        c = a;
        c->next = addPolynomials(a->next, b);
    }
    return c;
}
void print(struct node *head)
{
    while (head->next != NULL)
    {
        printf("%dx^%d + ", head->coeff, head->pow);
        head = head->next;
    }
    printf("%dx^%d \n", head->coeff, head->pow);
}
void main()
{
    struct node *head1 = NULL, *head2 = NULL;
    int c, p;

    insertionAtTail(&head1, 5, 0);
    insertionAtTail(&head1, 3, 2);
    insertionAtTail(&head1, 1, 3);

    insertionAtTail(&head2, 2, 1);
    insertionAtTail(&head2, 1, 2);
    insertionAtTail(&head2, 7, 3);

    printf("\n1st expression: ");
    print(head1);
    printf("\n2nd expression: ");
    print(head2);
    struct node *head = addPolynomials(head1, head2);
    printf("\nPolynomial expression after adding the two polynomials: ");
    print(head);
}
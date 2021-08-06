// 13. Program to implement a stack using an array.

#include <stdio.h>
#include<stdlib.h>


struct stack{
    int size;
    int top;
    int *s;
};

void create(struct stack * st){
    printf("Enter the size of the required stack\n");
    scanf("%d", &st->size);
    st->top=-1;
    st->s=(int *)malloc(st->size*sizeof(int));
}

void Push(struct stack *st, int x){
    if(st->top==st->size -1){
        printf("stack overflow\n");
    }
    else{
        st->top++;
        st->s[st->top]=x;
    }
}

void Display(struct stack *st){
    for(int i=st->top; i>=0; i--){
        printf("%d\n", st->s[i]);
    }
}

int main(){

    struct stack st;
    create(&st);

    Push(&st, 1);
    Push(&st, 2);
    Push(&st, 4);
    Push(&st, 6);

    Display(&st);

    return 0;
}
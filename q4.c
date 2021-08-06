// Program to sort an array.

#include<stdio.h>

struct Array{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr){
    int i;
    for(int i=0; i<arr.length; i++){
        printf("%d\t", arr.A[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int sort(struct Array *arr){
    int flag=0;
    for(int i=0; i<arr->length-1; i++){
        for(int j=0; j<arr->length-1-i; j++){
            if(arr->A[j]>arr->A[j+1]){
                swap(&arr->A[j], &arr->A[j+1]);
                flag=1;
            }
        }
            if(flag==0)
                break;
    }
    return flag;
}

int main(){

    struct Array arr={{1,4,3,8,5,6}, 10, 6};
    printf("before sorting : ");
    display(arr);
    int a = sort(&arr);
    printf("after sorting : ");
    display(arr);

    return 0;
}
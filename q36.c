// 36. Program to sort given list of data using bubble sort.


#include <stdio.h>

void swap(int *a, int *b){
    int temp =*a;
    *a=*b;
    *b=temp;
}

int sort(int A[], int length){
    int flag=0;
    for(int i=0; i<length-1; i++){
        for(int j=0; j<length-1-i; j++){
            if(A[j]>A[j+1]){
                swap(&A[j], &A[j+1]);
                flag=1;
            }
        }
            if(flag==0)
                break;
    }
    return flag;
}

void display(int A[], int length){
    for(int i=0; i< length; i++){
        printf("%d\t", A[i]);
    }
    printf("\n");
}

int main(){
    int A[10]={3,4,5,2,5,7,1,8,6,1};
    display(A,10);
    int a=sort(A,10);
    if(a==0){
        printf("the array is already a sorted array\n");
    }
    else{
        printf("the sorted array is given as : ");
        display(A, 10);
    }
    
    return 0;
}
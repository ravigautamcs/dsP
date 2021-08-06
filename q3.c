// Program to search for a number in an array

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

int search(struct Array *arr, int key){
    for(int i=0; i<=arr->length; i++){
        if(arr->A[i]==key){
            return i;
        }
    }
    return -1;
    
}

int main(){
    struct Array arr={{1,2,3,4,5,6}, 10, 6};
    int n; 
    printf("enter the number you want to search for : ");
    scanf("%d", &n);
    int flag = search(&arr,n);
    if(flag==-1)
        printf("UnSuccessfull search\n");
    else
        printf("Successfull search and it is present on the index %d\n", flag);


    return 0;
}

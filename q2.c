// Program to insert one element in an array and delete an element from an array

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

void insert(struct Array *arr, int index, int value){
    if(index>=0 && index<=arr->length){
        for(int i=arr->length; i>index; i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=value;
        arr->length++;
    }
}

void del(struct Array *arr, int index){
    if(index>=0 && index<arr->length){
        for(int i=index; i<arr->length-1; i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
}

int main(){
    struct Array arr={{1,2,3,4,5,6}, 10, 6};
    printf("initial array : ");
    display(arr);
    insert(&arr,2,60);
    printf("array after inserting the value 60 at index 2 : ");
    display(arr);
    del(&arr, 5);
    printf("array after deleting the value at index 5 : ");
    display(arr);

    return 0;
}

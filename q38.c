// 38. Program to sort given list of data using insertion sort.


#include <stdio.h>
 
 void InsertionSort(int A[], int n){
     int x, j=0, i=0;
     for(int i=1; i<n; i++){
        j=i-1;
        x=A[i];

        while(j>-1 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
     }
 }

int main(){
    int A[10]={4,2,1,5,7,3,8,4,2,3};
    for(int i=0; i<10; i++){
        printf("%d\t", A[i]);
    }
printf("\n");
    InsertionSort(A, 10);
    for(int i=0; i<10; i++){
        printf("%d\t", A[i]);
    }

    return 0;
}
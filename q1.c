// 1. Program to find the mean and the median of the numbers stored in an array

#include<stdio.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sort(int a[], int n){
    int i, j, temp;

    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i; j++){
            if(a[j]>a[j+1]){
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

int main(){

    int n; 
    printf("enter the no of numbers : ");
    scanf("%d", &n);

    int a[1000];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int sum=0;
    for(int i=0; i<n; i++){
        sum += a[i];
    }
    int mean = sum/n;
    
    sort(a,n);

    int m = (n+1)/2 -1;

    int median = a[m];

    printf("mean - %d\nmedian - %d\n", mean, median); 

    return 0;
}
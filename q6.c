// Program to store the marks obtained by 10 students in 5 courses in a 2d-array.

#include<stdio.h>

int main(){

    int data[10][5];
    for(int i=0; i<10; i++){
        for(int j=0; j<5; j++){
            printf("enter the marks of the student roll no. %d of course%d :", i+1, j+1);
            scanf("%d", &data[i][j]);
        }
    }

printf("rollno and marks of the students : \n");

    for(int i=0; i<10; i++){
        printf("Roll no. %d\t", i+1);
        for(int j=0; j<5; j++){
            printf("%d\t", data[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#include<stdio.h>
// input a int n;
//for every line i before n, call function calc
//in calc for every column j before i, print #
void line(i){
    for(int j = 1; j <= i; j++){
        printf("#");
    }
    printf(" \n");
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        line(i);
    }
    return 0;
}
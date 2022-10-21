//Prompt for number N, set up a bool flag.
//form for loop for every number before N/2 (since number's factor can't be bigger than half of itself)
//second for loop for modding number j (in first loop) by number i
//if j can be modded to 0, then bool is false, number not prime
//if true print true, if false print false.
#include<stdio.h>
int main(){
int n,i,m=0,flag=0; //n as input, i as pointer, flag to check prime.
printf("Enter the number to check prime:");
scanf("%d",&n);
for(int j = 2; j <= n; j++){
    flag = 0;
    m=j/2;
    for(i=2;i<=m;i++){
        if(j%i==0){
        flag=1;
        }
        }
    if(flag==0){
    printf("Number %d is prime\n", j);}
    else{
    printf("Number %d is not prime\n", j);
    }
 }
 }

/*
create do while to ask user for a number > 0 and smaller than 2^16
declare a sum variable
for loop counter = 1 and <= num
    sum += counter
    print "the sum of all the numbers from 1 to N is
    print number
*/
#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(){
    int num1;
    int outputint = 0;
    do {
        num1 = get_int("Input a number smaller than 256: ");
    }   while(num1 <= 0 || num1 > 65536);
    for(int i = 0; i <= num1; i++){
        outputint += i;
    }
    printf("Sum is %d ", outputint);
}
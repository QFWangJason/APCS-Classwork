//prompt user for number C
//use 3 functions to return the biggest it can get to C on quarters, dimes, and nickels using division.
//move the remainder of the change to the next
//track down how many coins are used for each
//print final number;

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int c; //Amount of change

int calculate_quarters(int i){
    int j = c/25; //This line calculates the biggest amount that can be used to get to C
    c = c - j*25; //this line produces the leftover change for the smaller coins
    return j;
}
int calculate_dimes(int i){
    int j = c/10;
    c = c - j*10;
    return j;
}
int calculate_nickels(int i){
    int j = c/5;
    c = c - j*5;
    return j;
}

int main(){
    int final = 0;
  do{
    c = get_int("Change: ");
    }while(c <= 0 || c >= 100);

    final += calculate_quarters(c); //execute each in order, greedy algorithm.
    final += calculate_dimes(c);
    final += calculate_nickels(c);
    final += c; //The rest are pennies
    printf("%d ", final);
}
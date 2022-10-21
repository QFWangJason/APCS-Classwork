#include <stdio.h>
#include <cs50.h>
#include <math.h>

string name;
int age;
float hourly;

void printName(string name1, int age1, float hourly1){
    printf("%s, you are %i years old, and make %.2f $/hr ", name1, age1, hourly1);
}

int main(){
    name = get_string("What is your name? ");
    age = get_int("How old are you? ");
    hourly = get_float("Hourly pay: ");
    printName(name, age, hourly);
    return 0;
}

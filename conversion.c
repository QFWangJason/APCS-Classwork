//Promt user for decimal number;
//write function to execute procedure to get quotient and remainder
//store remainder in array and keep a pointer for reverse printing

#include <stdio.h>
#include <cs50.h>
#include <math.h>

void convert(long x, int base);
int arr[1000]; //array for storing remainders
char hex[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E'}; //Hex chart

int main(){
    long n;
    char check;
    bool repeat = 1;
    while(repeat){ //repeat prompt
        n = get_long("Input a decimal: ");
        convert(n, 2);
        convert(n, 8);
        convert(n, 16);
        check = get_char("Convert another? Y/N: ");
        if(check == 'N'){
            repeat = 0;
        }
    }
}

void convert(long x, int base){ //x is the number input, base is the conversion unit
    int dig = 0;
    while(x > 0){ //conversion algoritm;
        arr[dig] = x%base;
        dig++;
        x = x/base;
    }
    if(base == 2){ //checks which base is x being converted to
        printf("Binary: ");
    }
    if(base == 8){
        printf("Octal: ");
    }
    if(base == 16){
        printf("Hex: ");
    }
    for(int i = dig-1; i >= 0; i--){ //print in reverse order, from the last to the first element (digit)
        printf("%c", hex[arr[i]]); //print the correpsonding value of the hex chart.
    }
    printf("\n");
}

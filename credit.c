//prompt for input
//calculate checksum
//Check for card length and starting points
//Output valid, and card type.

#include <cs50.h>
#include <stdio.h>

bool found = false; //is the card valid?

bool checksum(long x);
int digit(long card);
long power(int n);
void checktype(long n, int d);

int main(void)
{
    bool keepcheck = true;
    long cardn;
    while(keepcheck){
        found = false;
        do{ cardn =  get_long("Enter card number: "); }while(cardn < 0);
        if(checksum(cardn) == true){ //only check type after checking that card is valid
        checktype(cardn, digit(cardn));
        }
        else{
            printf("INVALID\n"); //If not a valid card at all, print INVALID
        }
        char keep = get_char("Keep checking? Y/N ");
        if(keep == 'N'){
            keepcheck = 0;
        }
    }
}
bool checksum(long x){ //check whether the card validates Luhn's algorithm
    int credit = 0;
    int mod1 = 0;
    int mod2 = 0;
    int sum1 = 0;
    int sum2 = 0;
    int d1 = 0;
    int d2 = 0;
    while(x > 0){
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;
        // Remove second last digit
        mod2 = x % 10;
        x = x / 10;
        // Double second last digit and add digits to sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    credit = sum1 + sum2;
    if(credit%10 == 0){
        return true;
    }
    else{
        return false;
    }
}

int digit(long card){ //checks how many digits in the card
    int c = 0;
    while(card > 0){
        card/=10;
        c++;
    }
    return c;
}

long power(n){ //get power number
    long p = 1;
    for(int i = 1; i <= n; i++){
        p = p*10;
    }
    return p;
}

void checktype(long n, int d){ //if card is 13 digits, checks what type
    if(d == 13){
         if(n/power(12) == 4){ //13 digit VISA
                printf("VISA\n");
                }
            else{
                printf("INVALID\n");
            }
    }
    else if(d == 15){
        if(n/power(13) == 34 || n/power(13) == 37){ //15 digit AMEX
            printf("AMEX\n");
        }
        else{
            printf("INVALID\n");
        }
    }
    else if(d == 16){
        bool check = 0; //Only print INVALID if not either type
        for(int i = 51; i <= 55; i++){
            if(n/power(14) == i){
                printf("MASTERCARD\n");
                check = 1;
                }
        }
            if(n/power(15) == 4){
                printf("VISA\n");
                check = 1;
                }
            if(check != 1){
                printf("INVALID\n");
            }
    }
    else{
        printf("INVALID\n");
    }
}
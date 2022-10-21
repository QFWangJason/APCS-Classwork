//prompt for input
//execute space triangle
//print first hash triangle (execute function)
//print two spaces
//print second hash triangle (execute function)
#include <stdio.h>
#include <cs50.h>
#include <math.h>

void printer(int i){ //function for printing hash triangle
    for(int k = 1; k <= i; k++){
        printf("#");
    }
}

int main(){
    int h;
    do {
        h = get_int("Height: "); //prompt H row
    } while( h <= 0 || h > 8 );
    for(int i = 1; i <= h; i++){ //for each row
        for(int j = 1; j <= h - i; j++){ //for each column
            printf(" ");
        }
        printer(i); //first hash triangle
        printf("  "); //space in between
        printer(i); // second hash triganle
        printf("\n");
    }
}
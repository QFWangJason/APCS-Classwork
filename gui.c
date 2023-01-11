#include <stdio.h>
#include <string.h>
int main() {
        char buff[255];
        FILE * fp;
        char c;
        printf("File Handling\n");
        //open a file
        fp = fopen("demo.txt", "w");
        //writing operation
        while ((c = getchar()) != '\t') {
            putc(c, fp);
        }
        //close file
        fclose(fp);
        printf("Data Entered:");
        //reading
        fp = fopen("demo.txt", "r");
        while ((c = getc(fp)) != EOF) {
            printf("%c", c);
        }
        //close clearfile
        //fclose(fp);
        // printf("Data Entered after append:");
        // //reading
        // fp = fopen("demo.txt", "r");
        // while ((c = getc(fp)) != EOF) {
        //     printf("%c", c);
        // }
        //printf("\n");
        fp = fopen("demo.txt","r");
        fscanf(fp, "%s", buff);
        //printf("1: %s\n", buff);
        fclose(fp);
        printf("\n");
        fp = fopen("demo.txt", "r");
        int counter = 1;
        while(fgets(buff,255,fp) != NULL){
            printf("%i : %s\n", counter, buff);
            counter++;
        }
        fclose(fp);
        printf("\n");
        return 0;
    }

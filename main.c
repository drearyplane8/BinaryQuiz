#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char BinaryStringToInt(const char *string) {
    return (char) strtol(string, NULL, 2);
}

void PrintHelp() {
    printf("/p for positive numbers only\n");
    printf("/n for negative numbers only\n");
    printf("/pn for both\n");
    printf("/? to display help\n");
}


int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Wrong number of args:\n");
        PrintHelp();
        return 1;
    }


    setbuf(stdout, NULL);
    srand(time(NULL)); //inialise rng

    char *arg = argv[1];
    char num;

    if (arg[0] != '/') {
        printf("Invalid argument\n");
        return 1;
    }

    while(1) {

        if (arg[1] == 'n') num = (rand() % 127) * -1; //if negative option is chosen
        else if (arg[1] == 'p') { //is either /p or /pn
            if (arg[2] == 'n') { //if it is /pn
                num = (rand() % 255) - 127;
            } else num = rand() % 127; //else only generate positive numbers
        } else if (arg[1] == '?') { //if it is help
            PrintHelp();
            return 0;
        } else { //otherwise it is invalid
            printf("Invalid argument\n");
            return 1;
        }

        printf("Convert the number %d to sign-and-magnitude representation\n", num);
        char *input = malloc(64);
        gets(input);

        if (BinaryStringToInt(input) == num)
            printf("Correct\n");
        else
            printf("Incorrect\n");

    }
}



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>


void main(int argc, char** argv){
    char* match;
    int caseSensitive = 0;
    int lenMax = 128;
    int currentMax = 128;

    if(argc == 2)
    {
        match = argv[1];
    }
    else if(argc == 3 && strcmp(argv[1], "-i")==0)
    {
        caseSensitive = 1;
        match = argv[2];
    }
    else{
        printf("INVALID ARGUMENTS!\n");
        return;
    }
    
    int ended = 0;
    while(!ended){
        char* input = calloc(currentMax, sizeof(char));
        int inputtedChar = EOF;
        int index = 0;
        while((inputtedChar = getchar()) != '\n' && inputtedChar != EOF){
            input[index++] = (char) inputtedChar;
            if(index == currentMax){
                currentMax = index + lenMax;
                input = realloc(input, currentMax);
            }
        }
        
        if(inputtedChar == EOF)
            ended = 1;
        
    
        if(caseSensitive){
            char* lowerA = malloc(currentMax);
            strncpy(lowerA, input, currentMax);

            char* lowerB = malloc(strlen(match));
            strncpy(lowerB, match, strlen(match));

            for(int m = 0; m < currentMax; m++)
                lowerA[m]= tolower(lowerA[m]);
            for(int m = 0; m < strlen(match); m++)
                lowerB[m]= tolower(lowerB[m]);

            if(strstr(lowerA, lowerB))
                printf("%s\n", input);
            
            free(lowerA);
            free(lowerB);
        }
        else if(strstr(input, match)){
            printf("%s\n", input);
        }
        free(input);

    }

    

    
}

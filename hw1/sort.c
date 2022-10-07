#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

int main(int argc, char** argv){
    int lenMax = 128;
    int currentMax = 128;
    int inputCurrentMax = 128;
    int numbers = 0;

    int currentRow = 0;

    char** arr = (char**)malloc(lenMax * sizeof(char*));
    for (int i = 0; i < lenMax; i++)
        arr[i] = (char*)malloc(lenMax * sizeof(char));

    if(argc == 2) //I mean if we never need to argument check...
    {
        numbers = 1;
    }

    int ended = 0;
    
    while(!ended){
       
        char* input = malloc(sizeof(char)*inputCurrentMax);
        int inputtedChar = EOF;
        int index = 0;
        
        while((inputtedChar = getchar()) != '\n' && inputtedChar != EOF){
            input[index++] = (char) inputtedChar;
            if(index == inputCurrentMax){
                inputCurrentMax = index + lenMax;
                input = realloc(input, inputCurrentMax);
            }
        }
        
        if(inputtedChar == EOF){
            ended = 1;
            break;
        }
        input[strcspn(input, "\n")] = 0;
        
        if(inputCurrentMax > currentMax){
            currentMax = inputCurrentMax + currentMax;
            arr = realloc(arr, currentMax);
            for (int i = 0; i < sizeof(arr); i++)
                arr[i] = realloc(arr[i], currentMax);
        }
        

        if(strlen(input) != 0){
            strcpy(arr[currentRow], input);
            currentRow++;
        }
        
        
        
            
        
        free(input);
        
      

    }
    printf("\n");
    for(int i = 0; i < sizeof(arr); i++)
    {
        for(int j = 0; j < sizeof(arr[i])-1-i; j++)
        {
            char temp[sizeof(arr[i])];

            char* lowerA = malloc(sizeof(arr[j]));
            strncpy(lowerA, arr[j], sizeof(arr[j]));
            char* lowerb = malloc(sizeof(arr[j+1]));
            strncpy(lowerb, arr[j+1], sizeof(arr[j+1]));

            for(int m = 0; m < sizeof(lowerA); m++)
                lowerA[m]=tolower(lowerA[m]);
            for(int m = 0; m < sizeof(lowerb); m++)
                lowerb[m]=tolower(lowerb[m]);
            
            if(!numbers && strcmp(lowerA, lowerb) > 0) 
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
            else if(numbers && atoi(lowerA) > atoi(lowerb)) 
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
            free(lowerA);
            free(lowerb);
      
        }
    }
    
    for(int i = 0; i < sizeof(arr); i++)
    {
        if(strlen(arr[i]) > 0)
            printf("%s\n", arr[i]);
        free(arr[i]);
    }
    free(arr);

    
    
}
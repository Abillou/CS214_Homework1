#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int lenMax = 100;
    int maxSize = 100;
    int count = 0;
    int ended = 0;
    char **strArr = (char**) malloc(lenMax * sizeof(char*));

    for(int i = 0; i < lenMax; i++)
    {
        strArr[i] = (char*)malloc(lenMax * sizeof(char));
    }

    int row = 0;
    int inputMax = 100;
    while(!ended)
    {
        char* line = malloc(sizeof(char) * maxSize);
        int exitChar = EOF;
        int index = 0;     
        int num = 0;
        while((exitChar = getchar()) != '\n' && exitChar != EOF)
        {
            line[index++] = (char) exitChar;
            if(index == inputMax)
            {
                inputMax = index + lenMax;
                line = realloc(line, inputMax);
            }
        }

        if(exitChar == EOF)
        {
            ended = 1;
        }
        
        if(inputMax > maxSize)
        {
            maxSize = inputMax + maxSize;
            strArr = realloc(strArr, maxSize);
            for(int i = 0; i < lenMax; i++)
            {
                strArr[i] = realloc(strArr[i], maxSize);
            }
        }
        
        if(strlen(line) != 0)
        {
            strcpy(strArr[row], line);
            row++;
        }        
        free(line);       
    }
   
    
    int counter = 1;
    char* duplicate = malloc(sizeof(strArr[0]));
    strncpy(duplicate, strArr[0], sizeof(strArr[0]));
    free(strArr[0]);   
    printf("\n");
    
    for(int j = 1; j < row; j++)
    {  
        if(strlen(strArr[j])>0)
        {
            if(strcmp(duplicate, strArr[j])==0){
                        counter++;
            }
            else{
                printf("%d %s\n", counter, duplicate);
                duplicate =  strcpy(duplicate, strArr[j]);
                counter = 1;
            }             
        }
        free(strArr[j]);  
        
    }
    free(strArr);
    printf("%d %s\n", counter, duplicate);
    
}
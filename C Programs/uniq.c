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
    /*
    int* repetitions = (int*)malloc(sizeof(int) * lenMax);
    int intMax = 100;
    int length = 0;
    int indexTwo = 0;
    int numOfReps = 0;
    int arrRows = sizeof(strArr)/sizeof(strArr[0]);
    
    while(length != arrRows)
    {
        if(intMax > maxSize)
        {
            maxSize = intMax + maxSize;
            repetitions = realloc(repetitions, maxSize);
        }

        if(strcmp(strArr[indexTwo], strArr[indexTwo + 1]) == 0)
        {
            numOfReps++;
        }
        else
        {
            numOfReps = 1;
        }
        repetitions[indexTwo] = numOfReps;
        length++;
        indexTwo++;

    }
    */
    
    int counter = 1;
    char* duplicate = malloc(sizeof(strArr[0]));
    strncpy(duplicate, strArr[0], sizeof(strArr[0]));
    free(strArr[0]);   
    printf("\n");

    for(int j = 1; j < sizeof(strArr); j++)
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
            free(strArr[j]);               
        }
        
    }
    free(strArr);
    printf("%d %s\n", counter, duplicate);
    
}

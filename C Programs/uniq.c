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

    while(!ended)
    {
        char* line = malloc(sizeof(char) * maxSize);
        int exitChar = EOF;
        int index = 0;
        int inputMax = 100;
        int num = 0;

        int row = 0;

        while((exitChar = getchar()) != '\n' && exitChar != EOF)
        {
            line[index] = (char) exitChar;
            if(index == maxSize)
            {
                inputMax = index + lenMax;
                line = realloc(line, inputMax);
            }
            index++;
        }

        if(exitChar == EOF)
        {
            ended = 1;
            //break;
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
                strncpy(strArr[row], line, sizeof(line));
                row++;
        }



        free(line);
    }
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

    
    int skip = 0;
    /*for(int j = 0; j < sizeof(strArr); j++)
    {   
        if(strlen(strArr[j] > 0))
        {
            printf("%s\n", strArr[j]);
        }
        
        

        //skip += repetitions[j];

    }*/
    
    printf("%s\n%s\n", strArr[0], strArr[1]);
    
}
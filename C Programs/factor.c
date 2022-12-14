#include<stdio.h>
#include<stdlib.h>

int isPrime(int number){

    for(int j = 2; j <= number/2; j++){

        if(number%j == 0)
            return 0;

    }
    return 1;
}

int main(int argc, char** argv){
    if(argc != 2){
        printf("Error! No number inputted.\n");
        return 0;
    }
    int a = atoi(argv[1]);
    if(isPrime(a)){
        printf("%d\n", a);
    }
   
    else{

        for(int i = 2; i <= a; i++){       
            if(a%i==0 && isPrime(i)){
                printf("%d ", i);
                a/=i;
                i=1;
            }           
        }
        printf("\n");
    }   
    
}
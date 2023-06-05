/*
* File Name: string.c
* Author: VO MINH HIEU
* Date: 02/06/2023
* Description: This file is use for counting the occurencces of each word in a string
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char myString[] = "She sells seashells on the seashore. The shells she sells are seashells";

typedef struct{
    char data[10];
    int counter;
}WordData;

int length(char *myString){
    int len = 0; 
    int i=0;
    while(myString[i] != '\0'){
        ++len;
        ++i;
    }
    return len;
}

void plitWord(char *myString){

int ctr=0;
int j;
int i;


int stringLength = length(myString);

char newString[100][100];

for (int i = 0; i <= stringLength; i ++){
    if (myString[i] == ' ' || myString[i] == '\0'){
        newString[ctr][j] = '\0';
        ctr++;
        j = 0;
    }
    else{
        newString[ctr][j]=myString[i];
            j++;
    }
    printf("\n Strings or words after split by space are :\n");
    for(i=0;i < ctr;i++)
        printf(" %s\n",newString[i]);
}
}

int main(){


    plitWord(myString);

    return 0;
}

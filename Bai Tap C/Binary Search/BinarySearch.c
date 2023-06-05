/*
* File Name:BinarySearch.c
* Author: Vo Minh Hieu
* Date: 02/06/2023
* Description: This file is used for search a number in array
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
* Function: randomArray
* Description: Create a random array with elements valued between 1 and 10000
* Input:
*     iArray[]: the random array 
* Output:
*     None
*/
void randomArr(int iArray[])
{
    for (int i = 0; i < 10000; i++)
    iArray[i] = 1 + rand() % (10000 - 1 + 1);
}

/*
* Function: sortArray
* Description: This function sorts all elements in an array in ascending order
* Input:
*   iArray - an array with n integer members
* Output:
*   None
*/

void sortArray(int iArray[]){
    for (int i = 0; i < 10000 ; i++){
        for(int j = i + 1; j < 10000; j++){
            if (iArray[i] > iArray[j]){
                int temp;
                temp = iArray[i];
                iArray[i] = iArray[j];
                iArray[j] = temp;
            }
        }
    }

}

/*
* Function: printArray
* Description: This function prints the array into the screen
* Input:
*   iArray - an array with n integer members
* Output:
*   Array
*/

void printArray(int iArray[])
{
    printf("\n");
    for (int i = 0; i < 10000; i++)
    printf("%d ", iArray[i]);
}

/*
* Function: binarySearch
* Description: This function prints the array into the screen
* Input:
*   iArray - an array with 10000 integer members
*/

int binarySearch(int iArray[], int yourNum){
    int low = 0;
    int high = 10000;

    while(low <= high){
        int mid = low + (high - 1) / 2;

        if (iArray[mid] == yourNum){
            return mid;
        }
        if (iArray[mid] < yourNum){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int iArray[10000];
    randomArr(iArray);
    sortArray(iArray);
    printArray(iArray);
    
    int yourNum;
    printf("\nEnter your number: \n");
    scanf("%d", &yourNum);
    int result = binarySearch(iArray, yourNum);
    if(result  == -1){
        printf("Can not found your number");
    }else{
        printf("Founded your number in array");
    }

    return 0;
}

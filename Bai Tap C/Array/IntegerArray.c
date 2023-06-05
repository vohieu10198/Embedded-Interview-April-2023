/*
* File: IntegerArray.c
* Author: VO MINH HIEU
* Date: 02/06/2023
* Description: This is file for array handling
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/*
* Function: RandomArray
* Description: This function creates a random array with n members
* Input:
*   iArray - an array with n integer members
*   n - an integer value
*/


void randomArray(int iArray[], int n){
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        iArray[i] = rand() % 10;
    }
}

/*
* Function: printArray
* Description: This function prints the array into the screen
* Input:
*   iArray - an array with n integer members
*   n - an integer value
*/

 void printArray(int iArray[], int n){
    for (int i = 0; i < n; i++){
        printf("%2d", iArray[i]);
    }
    printf("\n");
}

 /*
* Function: sortArray
* Description: This function sorts all elements in an array in ascending order
* Input:
*   iArray - an array with n integer members
*   n - an integer value
*/

void sortArray(int iArray[], int n){
    for (int i = 0; i < n ; i++){
        for(int j = i + 1; j < n; j++){
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
* Function: countOccurences
* Input:
*   n: size of array that user input
*   iArray: array
* Output:
*   print the occurences of each element
*/

void countOccurences(int iArray[], int n)
{
    int tempArray[n];
    for (int i = 0; i < n; i++)  tempArray[i] = 1;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        if(tempArray[i] == 1)
        {
           
            for (int j = i + 1; j < n; j++)
            {
                if (iArray[i] == iArray[j])
                {
                count++;
                tempArray[j] = 0;
                }
            }
        printf("Element %d appears %d times(s)\n", iArray[i], count);
        }
        
    }
}


 int main(int argc, char const *argv[])
 {  
    int n, iArray[n];

   	printf("Enter the number of array's members: ");
  	scanf("%d",&n);
    printf("Random array is: ");

    randomArray(iArray, n);
    printf("Random array is: ");
  	printArray(iArray, n);

	sortArray(iArray,n);
	printf("Array is sorted in ascending order:");
	printArray(iArray,n);

    countOccurences(iArray,n);

    return 0;
 }
 

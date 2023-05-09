/*
* File: sortArray.c
* Author: Vo Minh Hieu
* Date: 30/04/2023
* Description: This file is used for array handling
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// Create a random array with n integer numbers
// Sorting array's element in ascending order
// Count occurrences of elements in array



/*
* Function: createRandomArray
* Description: This function creates a random array with n members
* Input:
*   iArray - an array with n integer members
*   n - an integer value
*/

void createRandomArray(int iArray[], int n){
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

void printArray(int iArray[], int n)
{
    for(int i = 0; i < n; i++)
    {
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


int main()
{
   	int n, iArray[n];

   	printf("Enter the number of array's members: ");
  	scanf("%d",&n);

    createRandomArray(iArray, n);
	printf("A random array is: ");
  	printArray(iArray, n);

	sortArray(iArray,n);
	printf("Array is sorted in ascending order:");
	printArray(iArray,n);

	
}
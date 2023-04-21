#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Create a random array with n elements
void createArray(int arr[], int n){
    
    srand((int) time(0));
    for (int i = 0; i < n; i++){
        arr[i] = rand() % (n+1);
    }


}


// Sorting array's elements in ascending orders
void sortArray(int arr[], int n){
    for (int i = 0; i < n ; i++){
        for(int j = i + 1; j < n; j++){
            if (arr[i] > arr[j]){
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

}


// Print array
void printArray(int arr[], int n){
   
    for (int i =0; i < n; i++){
    printf("%2d", arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    int arr[n];
    
    printf("Enter the number of array's members: ");
    scanf("%d", &n);
    
    createArray(arr,n);
    printArray(arr,n);
    
    sortArray(arr,n);
    printArray(arr,n);
}

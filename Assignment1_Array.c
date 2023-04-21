#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Create a random array with n members
void createArray(int arr[], int n){
    
    srand((int) time(0));
    for (int i = 0; i < n; i++){
        arr[i] = rand() % (n+1);
    }


}

// Print array
void printArray(int arr[], int n){
   
    printf("Array: ");
    for (int i =0; i < n; i++)
    printf("%2d", arr[i]);
}

void swap(int *a, int *b){
    int *temp;
    *temp = *a;
    *a = *b;
    *b = *temp;
}

void sortArray(){

}

int main(){
    int n;
    int arr[n];
    
    printf("Enter the number of array's members: ");
    scanf("%d", &n);
    
    createArray(arr,n);
    printArray(arr,n);
}
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


// Create a random array with n elements
void create_random_array(int arr[], int n){
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10;
    }
}



void print_array(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%2d", arr[i]);
    }
    printf("\n");
}

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

void separate_element(int arr[] , int b[], int n, int m){
	m = 0;
	b[m] = arr[0];
	m++;
	int i, j;
	for (i = 1; i < n; i++){
		int flag  = 1;
		for (j = i-1; j >= 0; j--){
			if (arr[i] == arr[j]){
				flag = 0;
			}
		}
		if (flag == 1){
			b[m] = arr[i];
			m++;
			}
	}
}

void count_element(int arr[] , int b[], int n, int m){
	separate_element(arr,b,n,m);
	for (int i = 0; i < m; i++){
		int count = 0;
		for(int j = 0; j < n; j++){
			if(b[i] == arr[j])
			{
				count++;
			}
			}
			printf("\tElement %d appears %d time(s)\n", b[i], count);
		
	}	
}

int main()
{
    int n, arr[n];
	int b[n];
	int m;

    printf("Enter the number of array's members: ");
    scanf("%d",&n);

    create_random_array(arr, n);
	printf("A random array is: ");
    print_array(arr, n);

	sortArray(arr,n);
	printf("Array is sorted in ascending order:");
	print_array(arr,n);

	printf("Occurrences of each element in array: \n");
	count_element(arr,b,n,m);
	
}
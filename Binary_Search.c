#include<stdio.h>
#define N 100


int inputData( int arr[] ){
	int i;
	for(i = 0; i< N; i++ ){
		scanf("%d", &arr[i]);
	}
}

void printData( const int arr[] ){
	int i;
	for(i = 0; i< N; i++ ){
		printf("%2d", arr[i]);
	}
}

void sortArray( int arr[] ){
	int i, j;
	for(i = 0; i< N-1; i++){
		for(j= N-1; j> i; j-- ){
			if(arr[j] < arr[j-1]){
				int tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] =tmp;
			}
		}
	}
}

int binarySearch( int arr[], int x ){
	int left = 0, right = N-1;
	while(left <= right){
		int mid = (left+right)/2;
		if(arr[mid] == x)
			return 1; 
		else if(arr[mid] < x) 
			left = mid+1;
		else right = mid-1;
	}
	return -1;
}

int main(){
	
	int arr[N];
	inputData(arr);
	sortArray(arr);
	printData(arr);
	int x;
	
	while(1){
		printf("\nEnter x= ");
		scanf("%d", &x);
		if(x == -1) break;
		if(binarySearch(arr, x))
			printf("\nFound x");
		else printf("\n not Found x");
	}
	
	return 0;
}

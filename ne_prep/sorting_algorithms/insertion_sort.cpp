#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) {
	int i, key,k;
	for(i=1;i<n;i++){
		key = arr[i];
		k=i-1;
	while(k>=0 && arr[k]>key){
		arr[k+1]=arr[k];
		k=k-1;	}
		arr[k+1]=key;
	}
}

void printArr(int arr[],int n) {
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main() {
	int arr[] = {12,11,13,5,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	insertionSort(arr,n);
	printArr(arr,n);
	return 0;
}

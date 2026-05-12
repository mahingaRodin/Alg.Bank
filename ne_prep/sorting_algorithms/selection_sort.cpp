#include<iostream>
using namespace std;

void selectionSort(int arr[], int n) {
	int i,k;
	for(i=0;i<n-1;i++){
		int targetIndex = i;
		for(k=i+1;k<n;k++){
			if(arr[k]<arr[targetIndex]) {
				targetIndex = k;
			}
		}
		swap(arr[i],arr[targetIndex]);
	}
}

void printArray(int arr[],int n) {
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main() {
	int arr[] = {1,2,24,41,23};
	int n = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,n);
	cout<<endl;
	selectionSort(arr,n);
	printArray(arr,n);
	return 0;
}

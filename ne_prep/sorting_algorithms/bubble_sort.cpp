#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
	for(int i=0;i<n-1;i++){
		for(int k=0;k<n-1;k++){
			if(arr[k]>arr[k+1]){
				int temp = arr[k];
				arr[k]=arr[k+1];
				arr[k+1]=temp;
			}
		}
	}
}
int main() {
	int n=6;
	int arr[n] = {20,21,12,33,11,211};
	bubbleSort(arr,n);
	for(int k=0;k<n;k++){
		cout<<arr[k]<<" ";
	}
	cout<<endl;
	return 0;
}

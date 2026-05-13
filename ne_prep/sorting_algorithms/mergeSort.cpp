#include<iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
	int n1 = mid-l+1;
	int n2 = r-mid;
	//temporary arrays
	int left[n1];
	int right[n2];
	//copying data
	for(int i=0;i<n1;i++){
		left[i]=arr[l+i];
	}
	for(int i=0;i<n2;i++){
		right[i]=arr[mid+i+1];
	}
	//merging arrays back
	int i=0,j=0,k=l;
	while(i<n1 && j<n2){
		if(left[i]<=right[j]){
			arr[k]=left[i];
			i++;
		}else{
			arr[k]=right[j];
			j++;
		}
		k++;
	}
	
	//remaing elements
	while(i<n1){
		arr[k]=left[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=right[j];
		j++;
		k++;
	}
	}
	
void mergeSort(int arr[], int left, int right) {
	if(left<right){
		int mid = (left+right)/2;
	mergeSort(arr,left,mid);
	mergeSort(arr,mid+1,right);
	merge(arr,left,mid,right);
}
}

void printArray(int arr[], int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main() {
	int arr[] = {3,4,5,1,6,8,7,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,n);
	mergeSort(arr,0,n-1);
	cout<<endl;
	printArray(arr,n);
	return 0;
}

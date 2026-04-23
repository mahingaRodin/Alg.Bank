#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
	int s=0, e=n-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		
		if(arr[mid]==key) {
			return mid;
		}else if(arr[mid]>key){
			e=mid-1;
		}else {
			s=mid+1;
		}
	}
	return -1;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter The key: "<<endl;
	int key;
	
	int pos= binarySearch(arr,n,key);
	if(pos==-1) {
		cout<<"key not found"<<endl;
	cin>>key;
	} else {
		cout<<"key found at index"<<pos<<endl;
	}
	return 0;
}

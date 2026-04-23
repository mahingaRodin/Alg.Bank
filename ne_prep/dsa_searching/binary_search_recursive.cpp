#include<iostream>
using namespace std;

int binarySearch(int arr[], int l,int r, int x) {
	if(r>=l){
		int mid=l+(r-l)/2;
		if(arr[mid]==x) return mid;
		if(arr[mid]>x) return binarySearch(arr,l,mid-x,x);
		return binarySearch(arr,mid+1,r,x);
	}
	return -1;
}

int main() {
	int arr[] = {2,3,4,10,40};
	int x=55;
	int n =sizeof(arr)/sizeof(arr[0]);
	int result = binarySearch(arr,0,n-1,x);
	(result==-1)?cout<<"element isn't present in array":cout<<"element is present at index: "<<result<<endl;
	return 0;
}

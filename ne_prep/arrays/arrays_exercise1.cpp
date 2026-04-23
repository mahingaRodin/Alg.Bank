#include<iostream>
using namespace std;

int main() {
	int size;
	//ask user for size of the array
	cout<<"Enter the size of the array: ";
	cin>>size;
	
	int arr[size];
	
	//input array elements;
	cout<<"Enter "<<size<<" elements:\n";
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	
	//calculate sum & mean
	int sum=0;
	
	for(int i=0;i<size;i++){
		sum+=arr[i];
	}
	double avg = (double)sum/size;
	cout<<"\nSum = "<<sum<<endl;
	cout<<"Avg = "<<avg<<endl;
	
	//find the min and max
	int max = arr[0];
	int min =arr[0];
	for(int i=1;i<size;i++){
		if(arr[i]>max){
			max=arr[i];
		}
		if(arr[i]<min){
			min=arr[i];
		}
	}
	
	cout<<"\nLargest element: "<<max<<endl;
	cout<<"Smallest element: "<<min<<endl;
	
	//print array in reverse order
	cout<<"\nArray in Reverse order:\n";
	for(int i=size-1;i>=0;i--) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	//generate reversed array
	int reversed[size];
	
	for(int i=0;i<size;i++) {
		reversed[i]=arr[size-1-i];
	}
	cout<<"\nReversed Array Stored:\n";
	for(int i=0;i<size;i++) {
		cout<<reversed[i]<<" ";
	}
	cout<<endl;
	return 0;
}

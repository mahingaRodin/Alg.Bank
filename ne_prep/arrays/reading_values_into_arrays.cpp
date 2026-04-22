#include<iostream>
using namespace std;

int main() {
	int scores[9]= {};
	//use for loop to read values into score array
	for(int i=0;i<9;i++) {
		cout<<"Please enter score numbers: "<<i+1<<endl;
		cin>>scores[i];
	}
	
	cout<<"\nThe Enter values are:\n";
	for(int i=0;i<9;i++){
		cout<<scores[i]<<" ";
	}
	return 0;
}

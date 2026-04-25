#include<iostream>
using namespace std;

int main() {
	int arr[4] = {5,10,15,20};
	
	int *p = arr;
	p = p+2;
	cout<<*p<<" "<<endl;
	cout<<*(p-1);
	return 0; 
}

#include<iostream>
using namespace std;

int pow(int x, int n) {
	//base case
	if(n==0) return 1;
	//recursive case
	int s1 = pow(x,n-1);
	return x*s1;
}

int main() {
	int x,n;
	cout<<pow(5,2)<<endl;
	return 0;
}

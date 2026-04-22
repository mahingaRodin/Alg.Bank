#include<iostream>
using namespace std;

int multiply(int m, int n) {
	//base case
	if(n==0) return 0;
	//recursive
	int s1 = multiply(m,n-1);
	//calc
	return s1+m;
}


int main() {
	cout<<multiply(3,5);
	return 0;
}

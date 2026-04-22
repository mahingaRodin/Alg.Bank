#include<iostream>
using namespace std;

int count(int n) {
	//base case
	if(n==0) return 0;
	//recursive case
	int s1 = count(n/10);
	//calc
	return s1+1;
}

int main() {
	cout<<count(1234);
	return 0;
}

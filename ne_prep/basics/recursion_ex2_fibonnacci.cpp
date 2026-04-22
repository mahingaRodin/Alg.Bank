#include<iostream>
using namespace std;

int fib(int n) {
	//basecases
	if(n==0) return 0;
	if(n== 1) return 1;
	
	//recursive case
	int s1 = fib(n-1);
	int s2 = fib(n-2);
	return s1+s2;
}

int main() {
	cout<<fib(3);
	return 0;
}

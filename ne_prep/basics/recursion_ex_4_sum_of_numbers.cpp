#include<iostream>
using namespace std;

int sum(int n) {
	//base case
	if(n==0) return 0;
	//recursive case
	int s1=sum(n/10);
	//last digit
	int last_digit = n%10;
	return s1+last_digit;
}

int main() {
	int x;
	cout<<sum(123)<<endl;
	return 0;
}

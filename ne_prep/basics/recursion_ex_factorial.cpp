#include<iostream>
using namespace std;

int fact(int n) {
	//best case
	if(n<0) return -1;
	if(n==0) return 1;
	//assumption
	int smallAnswer = fact(n-1);
	//calculate
	return n*smallAnswer;
}

int main() {
	int n=5;
	
	int answer = fact(n);
	cout<<answer<<endl;
	return 0;
}

#include<iostream>
using namespace std;

int print(int n) {
	//base case
	if(n==0) return 0;
	//recursive
	cout<<n<<" ";
	print(n-1);
}

int main() {
	print(4);
	return 0;
}

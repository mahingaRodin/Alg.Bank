#include<iostream>
using namespace std;

template <class T, int N>

T fixed_multiply(T val) {
	return val * N;
}

int main() {
	cout<<fixed_multiply<int,2>(10)<<endl;
	cout<<fixed_multiply<double,4>(22)<<endl;
	return 0;
}

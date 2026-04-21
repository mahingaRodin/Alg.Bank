#include<iostream>
using namespace std;

template <typename rodin>
rodin sum (rodin a, rodin b) {
	return a+b;
}

int main() {
	int x=5, y=2;
	double n=12,m=13;
	cout<<sum<int>(x,y)<<endl;
	cout<<sum<double>(n,m)<<endl;
	return 0;
}

#include<iostream>
#include<string>
using namespace std;

double maximum(double x,double y,double z) {
	double maxiVal = x;
	if(y>maxiVal) {
		maxiVal=y;
	}
	if(z>maxiVal)
	maxiVal=z;
	return maxiVal;
}

int main() {
	double max = maximum(12,14,15);
	cout<<max<<endl;
	return 0;
}

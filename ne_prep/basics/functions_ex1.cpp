#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	double height, base, hypothenuse;
	cout<<"Enter the value of height and base: "<<endl;
	cin>>height>>base;
	hypothenuse = sqrt(pow(height,2) + pow(base,2));
	cout<<"The hypothenuse = "<<hypothenuse<<endl;
	return 0;
}

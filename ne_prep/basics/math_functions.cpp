#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main() {
	double val;
	
	val = fmax(10.0,1.0);
	cout<<fixed<<setprecision(4)<<"Fmax(10.0,1.0) = "<<val<<endl;
	
	val = fmax(-10.0,1.0);
	cout<<fixed<<setprecision(4)<<"Fmax(-10.0,1.0) = "<<val<<endl;
	
	val = fmax(-10.0,-1.0);
	cout<<fixed<<setprecision(4)<<"Fmax(-10.0,-1.0) = "<<val<<endl;
	
	return 0;
}

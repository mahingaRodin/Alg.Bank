#include<iostream>
#include<string>
using namespace std;

double rect_area(double width, double length) {
	double area = width * length;
	return area;
}

int main() {
	double width =23;
	double length=234;
	cout<<rect_area(width,length);
	return 0;
}

#include<iostream>
using namespace std;

#define PI 3.14159265

int main() {
	double radius;
	cout<<"Enter the radius of the circle: "<<endl;
	cin>>radius;
	double area = PI * radius * radius;
	cout<<"The area of the cirlce is: "<<area<<endl;
	return 0;
}

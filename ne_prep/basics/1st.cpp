#include<iostream>
using namespace std;

int main() {
	string firstName,lastName;
	int age;
	cout<<"Enter Your FirstName: \n";
	cin>>firstName;
	cout<<"Enter Your LastName: \n";
	cin>>lastName;
	cout<<"Enter Your Age: \n";
	cin>>age;
	string fullName = firstName + lastName;
	cout<<"Your Names are: "<<fullName<<"And You are "<<age<<"Years Old!"<<endl;
	return 0;
}

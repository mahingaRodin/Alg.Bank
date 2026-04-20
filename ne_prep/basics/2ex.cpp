#include<iostream>
using namespace std;

int main() {
	string fullName;
	double principal;
	double rate;
	double time;
	double interest;
	
	cout<<"Enter Your Full Name: ";
	getline(cin, fullName);
	
	cout<<"Enter Init Amount: ";
	cin>>principal;
	
	cout<<"Enter Interest Rate Per Year (%): ";
	cin>>rate;
	
	cout<<"Enter Payment Time (years): ";
	cin>>time;
	
	interest = (principal*rate*time) / 100;
	
	cout<<"\nCustomer Name: "<<fullName<<endl;
	cout<<"Total Interest: "<<interest<<endl;
	return 0;
}

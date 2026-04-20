#include<iostream>
#include<cctype>
using namespace std;

int main() {
	char ch;
	cout<<"Enter a character: ";
	cin>>ch;
	
	if(isdigit(ch)) {
		cout<<"The char is a digit. "<<endl;
	} else if (isalpha(ch)) {
		cout<<"it is an alphabet letter."<<endl;
	}
	else {
		cout<<"it is none a digit or an aphabet."<<endl;
	}
	
	return 0;
}

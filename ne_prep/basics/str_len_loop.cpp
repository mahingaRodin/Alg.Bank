#include<iostream>
#include<string>
using namespace std;

int main() {
	string text;
	int length = 0;
	
	cout<<"Enter a string: ";
	getline(cin,text);
	
	while(text[length] != '\0') {
		length++;
	}	
	
	cout<<"length of the string: "<<length<<endl;
	return 0;
}

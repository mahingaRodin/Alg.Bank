#include<iostream>
#include<string>
using namespace std;

int main() {
	string text;
	string reversed="";
	
	cout<<"enter a string: ";
	getline(cin,text);
	
	for(int i=text.length()-1; i>=0;i--) {
		reversed+=text[i];
	}
	if(text==reversed){
		cout<<"Palindrome"<<endl;
	} else {
		cout<<"Not Palindrome"<<endl;
	}
	return 0;
} 

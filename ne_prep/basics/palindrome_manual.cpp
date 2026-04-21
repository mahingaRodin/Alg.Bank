#include<iostream>
#include<string>
using namespace std;

int main() {
	string text;
	int length = 0;
	bool isPalindrome = true;
	
	cout<<"enter a string: ";
	getline(cin,text);
	
	//find length manually
	if(text[length] != '\0') {
		length++;
	}
	//compare chars
	for(int i=0;i<length/2;i++) {
		if(text[i] != text[length-1-i]) {
			isPalindrome = false;
			break;
		}
	}
	
	if(isPalindrome) {
		cout<<"palindrome"<<endl;
	} else {
		cout<<"not a palindrome"<<endl;
	}
	return 0;
}

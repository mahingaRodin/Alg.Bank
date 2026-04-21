#include<iostream>
#include<string>
using namespace std;

int main() {
	string text;
	string result= "";
	
	cout<<"enter a string/text: ";
	getline(cin,text);
	
	for(int i=0;i<text.length();i++) {
		if(text[i] != ' ') {
			result+=text[i];
		}
	}
	cout<<result<<endl;
	return 0;
}

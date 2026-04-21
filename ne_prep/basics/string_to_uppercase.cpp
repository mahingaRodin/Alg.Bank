#include<iostream>
#include<string>
using namespace std;

int main() {
	string text;
	
	cout<<"enter a string/text: ";
	getline(cin,text);
	
	for(int i=0;i<text.length();i++) {
		if(text[i]>='a' && text[i]<='z') {
			text[i]=text[i]-32;
		}
	}
	
	cout<<"The Uppercased string: "<<text<<endl;
	return 0;
}

#include<iostream>
#include<string>
using namespace std;

int main() {
	string text;
	int spaceCount;
	
	cout<<"Enter a string"<<endl;
	getline(cin,text);
	
	for(int i=0; i<text.length(); i++) {
		if(text[i]==' ') {
			spaceCount++;
		}
	}
	cout<<"nbr of spaces: "<<spaceCount<<endl;
	return 0;
}

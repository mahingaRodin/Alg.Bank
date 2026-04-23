#include<iostream>
using namespace std;

int main() {
	//cin usage -> gets one word
	char name[50];
	cout<<"Enter a name: ";
	cin>>name;
	cout<<"You entered: "<<name<<endl;
	
	//cin.get() -> get character by character
	char ch;
	cout<<"enter characters: ";
	while(cin.get(ch)){
		cout<<ch;
	}
	
	//cin.getline() -> reads enter line
	char sent[50];
	cout<<"enter a sentence: ";
	cin.getline(sent,50);
	cout<<"You entered: "<<sent;
	return 0;
}

#include<iostream>
using namespace std;

int main() {
	char buffer[80];
	cout<<"Enter a string: ";
	cin.get(buffer,79);
	cout<<"String you typed is: "<<buffer<<endl;
	return 0;
}

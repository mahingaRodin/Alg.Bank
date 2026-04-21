#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char str[80];
	strcpy(str,"these ");
	strcat(str, "strings ");
	strcat(str, "are ");
	strcat(str, "concantenated ");
	cout<<str;
	return 0;
}

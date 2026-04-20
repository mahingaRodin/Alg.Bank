#include<iostream>
#include<string>

using namespace std;

int main() {
	string text;
	int charWithSpaces;
	int charWithoutSpaces=0;
	int wordCount=0;
	
	cout<<"Enter a sentence: ";
	getline(cin,text);
	
	for(int i=0;i<text.length();i++) {
		if(text[i]!=' ') {
			charWithoutSpaces++;
		}
		if(text[i] == ' ' && text[i+1]!=' ') {
			wordCount++;
		}
	}
	if(text.length() > 0) {
		wordCount++;
	}
	
    cout << "Characters without spaces: "
         << charWithoutSpaces << endl;

    cout << "Characters with spaces: "
         << charWithSpaces << endl;

    cout << "Number of words: "
         << wordCount << endl;

    return 0;
}

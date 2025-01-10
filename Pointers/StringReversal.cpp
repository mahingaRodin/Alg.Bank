#include<iostream>
#include<cstring>
using namespace std;

//program to reverse a string

void reverseString(char* str) {
    char* start = str;
    char* end = str + strlen(str) - 1;

    while(start < end) {
       char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    char str[100];
    cout << "Enter string to reverse: "<<endl;
    cin >> str;

    //call the function

    reverseString(str);

    //print the output
    cout << "The reversed string is: " << str << endl;
}
#include<iostream>
using namespace std;
namespace first {
	int x = 500;
}
int x = 200;

int main() {
	int x = 300;
	
	cout<<first::x<<endl;
	cout<<::x<<endl;
	cout<<x<<endl;
	return 0;
}

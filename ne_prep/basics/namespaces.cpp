#include<iostream>
using namespace std;

namespace rodin {
	int value() {
		return 5;
	}
}

namespace olga {
	const double x = 100;
	double value() {
		return 2*x;
	}
}


int main() {
	cout<<rodin::value()<<endl;
	cout<<olga::value()<<endl;
	cout<<olga::x<<endl;
	return 0;
}

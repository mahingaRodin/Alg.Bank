#include<iostream>
using namespace std;

int main() {
	int scores[] = {11,12,13,14,15,16,17,18,19};
	int item=10,k=3,len=9,h=len-1;
	
	while(h>=k) {
		scores[h+1]=scores[h];
		h--;
	}
	
	scores[k]=item;
	for(int index=0;index<len+1;index++){
		cout<<scores[index]<<" ";
	}
	return 0;
}

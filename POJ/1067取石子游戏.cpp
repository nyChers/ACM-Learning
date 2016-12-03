#include<iostream>
#include<math.h>

using namespace std;


int main() {
	int a1,a2;
	while(cin>>a1>>a2) {
		if(a1>a2)
			swap(a1,a2);
		double p1 = (sqrt(5.0)+1)/2;
		int n = a2 -a1;
		if(a1 == int(p1*n))
			cout<<"0"<<endl;
		else
			cout<<"1"<<endl;
	}
	return 0;	
} 
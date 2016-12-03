#include<iostream>
#include<math.h>

using namespace std;

int main() {
	int a[100];
	a[0] = 1;
	for(int i=1; i<100; i++) {
		a[i] = a[i-1] * 2 + 1;
	}
	int n;
	cin>>n;
	for(int i=0; i<100; i++) {
		if(a[i]==n) {
			cout<<"lose"<<endl;
			break;
		}
		if(n<a[i]) {
			cout<<"win"<<endl;
			break;
		}		
	}
	
	return 0;
} 
#include<iostream>
#include<cmath>

using namespace std;

int quick_pow(int a,int b) {
	int t = 1;
	while(b != 0) {
		if(b%2 == 1) 
			t *= a; 
		a *= a;
		b /= 2; 
	}
	
	return t;
}
int main() {
	int a,p;
	cin>>a>>p;
//	pow(a,p);
	int s = quick_pow(a,p);	
	cout<<s<<endl;
	return 0;	
} 
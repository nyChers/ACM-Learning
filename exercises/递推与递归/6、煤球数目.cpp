#include<iostream>
using namespace std;

int duimeiqiu(int n) {
	int  sum=0;
	for(int i=1; i<=n; i++){
		sum+=i*(i+1)/2;
	}
	return sum;
}
int main() {
	int n=100;
	cout<<duimeiqiu(n)<<endl;
	return 0;
}
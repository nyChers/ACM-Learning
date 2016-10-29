#include<iostream>
#include<cmath>

using namespace std;

int cut_noodles(int n) {
		return 1+pow(2,n);
}

int main(){
	int n;
	cin>>n;
	cout<<cut_noodles(n)<<endl;
	return 0;
}
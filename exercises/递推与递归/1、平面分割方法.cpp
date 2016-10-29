#include <iostream>
using namespace std;


int area1(int n){
	return n * (n-1) + 2;
}
int area2(int n){
	if(n==1)
		return 2;
	else
		return area2(n-1) + 2 * (n-1); 
}

int main() {
	int n;
	cin>>n;
	int sum1 = area1(n);
	int sum2 = area2(n);
	cout<<"sum1="<<sum1<<endl;
	cout<<"sum2="<<sum2<<endl;
}

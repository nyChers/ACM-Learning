#include<iostream>
#include<math.h>

using namespace std;

int a[15] = {0,1,0,1,0,1,0,1,1,1,1,1,1,1,1};
int main() {
	int n;
	cin>>n;
	n %= 15;
	if(a[n])
		cout<<"win"<<endl;
	else
		cout<<"lose"<<endl;
	return 0;
} 
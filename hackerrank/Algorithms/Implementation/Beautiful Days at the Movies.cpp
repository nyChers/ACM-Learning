#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int reversed(int a){
	int b = a;
	int t = 0;
	while(b){
		t = t * 10 + b % 10;
		b /= 10;
	}
	return t;
}

int main() {
	int i,j,k;
	cin>>i>>j>>k;
	int cnt = 0;
	for(int a=i; a<=j; a++){
		if(abs(a-reversed(a))%k == 0)
			cnt++;
	}
	cout<<cnt<<endl;
    return 0;
}

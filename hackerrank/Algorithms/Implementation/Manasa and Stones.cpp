#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int t;
	int n,a,b;
	vector<int> sum;
	cin>>t;
	for(int k=0; k<t; k++){
		cin>>n>>a>>b;
		if(b<a)
			swap(a,b);
		if(a==b) {
			cout<<a*(n-1)<<endl;
			continue;
		} 
		for(int i=0; i<n; i++){
			cout<<i*b+(n-1-i)*a<<" ";
		} 
		cout<<endl;
	}
    return 0;
}

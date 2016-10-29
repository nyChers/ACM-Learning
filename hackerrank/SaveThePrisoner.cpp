#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int n,s,m;
		cin>>n>>m>>s;
		int t=m%n;
		s=(s+t-1)%n;
		if(s==0)
			s=n;
		cout<<s<<endl;
	} 
    return 0;
}


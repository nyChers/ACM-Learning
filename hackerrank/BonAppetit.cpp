#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    cin>>n>>k;
    int *a = new int[n];
    int sum=0;
    for(int i=0; i<n; i++) {
    	cin>>a[i];
    	sum+=a[i];
	}
	sum-=a[k];
	int s;
	cin>>s;
	int t=s-sum/2;
	if(t == 0)
		cout<<"Bon Appetit"<<endl;
	else
		cout<<t<<endl;
    return 0;
}


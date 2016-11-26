#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n;
	int a[102] = {0};
	cin>>n;
	int temp;
	for(int i=0; i<n; i++){
		cin>>temp;
		a[temp]++;
	} 
	int max = 0;
	for(int i=0; i<101; i++){
		if(a[i]>max)
			max = a[i];
	}
	cout<<n-max<<endl;
    return 0;
}

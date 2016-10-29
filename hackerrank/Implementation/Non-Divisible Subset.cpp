#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k;
	cin>>n>>k;
	int *a = new int[n];  
	int *b = new int[k]{0};

	for(int i=0; i<n; i++){
		cin>>a[i];
	}	
	if(k != 0){
		for(int i=0; i<n; i++){
			b[a[i]%k]++;
		}
	}
	
	int sum=0;
	if(k==0)
		sum=0;
	else if(k==1) 
		sum=1;
	else if(k==2){
			if(b[1] != 0)
				sum=2;
			else 
				sum=1;
		}
	else {
		if(k%2 == 1){
			for(int i=1; i<=k/2; i++){
				if(b[i]>=b[k-i])
					sum+=b[i];
				else 
				 	sum+=b[k-i];
				
			}
			if(b[0] != 0)
					sum++;
		}
		else {
			for(int i=1; i<k/2; i++){
				if(b[i]>=b[k-i])
					sum+=b[i];
				else 
					sum+=b[k-i];
				
			}
			if(b[0] != 0)
				sum++;	
			if(b[k/2] != 0 )
				sum++;
		}
	}
	cout<<sum<<endl;
    return 0;
}


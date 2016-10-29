#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int min(int *p,int n){
	int min;
	for(int i=0; i<n; i++){
			if(p[i]>0) {
			min=p[i];
			break;
		}
		min=0;
	}	
	for(int i=1; i<n; i++){
    	if(p[i]<min && p[i]>0)
    		min=p[i];
	}
	return min;
}
int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
	int sum;
	int m;
	while(true){
		m=min(arr,n);
		if(m==0)
			break;
		sum=0;
		for(int i=0; i<n; i++)
			if(arr[i]>0){
				arr[i]=arr[i]-m;
				sum++;
			}				
		if(sum==0)
		 	break;
		cout<<sum<<endl;
	}
    return 0;
}


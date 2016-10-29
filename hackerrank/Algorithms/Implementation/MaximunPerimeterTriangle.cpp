#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cmp ( const void *a , const void *b ) {
	return *(int *)a - *(int *)b; 
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int *p = new int[n];
    for(int i=0; i<n; i++){
    	cin>>p[i];
	}
	qsort(p,n,sizeof(int),cmp);
	
	for(int i=n-1; i>=2; i--)
		for(int j=i-1; j>=1; j--)
			for(int k=j-1; k>=0; k--)
				if(p[k]+p[j]>p[i]){
					cout<<p[k]<<" "<<p[j]<<" "<<p[i]<<endl;		
					return 0;		
				}
	cout<<"-1"<<endl;
	
    return 0;
}


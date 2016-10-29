#include<iostream>
#include<cmath>

using namespace std;

int cnt = 0;

void merge(int a[], int l, int m, int r) {
	    int i = l, j = m + 1;
	    int k = 0;
	    int *t = new int [r-l+1];
	    while(i<=m && j<=r){
	    	if(a[i]<=a[j])
	    		t[k++] = a[i++];
	    	else {
	    		t[k++] = a[j++];
	    		cnt = cnt + m - i + 1;//逆序对数计数 
			}	
		}
		while(i <= m) {
        	t[k++] = a[i++];
	    }
	    while(j <= r) {
	        t[k++] = a[j++];
	    }
	    for(int i = 0; i < k; i++){
	        a[l + i] = t[i];
	    }
}

void merge_sort(int a[], int l, int r) {
	if(r>l){
		int m = l + (r - l) / 2;
		merge_sort(a, l, m);
		merge_sort(a, m+1, r);
		merge(a, l, m, r);
	}
}
int main() {
	int n;
	cin>>n;
	int *a = new int [n];
	for(int i=0; i<n; i++) 
		cin>>a[i];
	merge_sort(a, 0, n-1);
	cout<<cnt<<endl;
	return 0;	
} 
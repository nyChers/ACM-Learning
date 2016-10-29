#include<iostream>
using namespace std;

struct M{
	int min;
	int max; 
}mm;

M min_max(int a[] , int f,int l) {
	M temp;
	if(l-f<2) {
		temp.min = a[f]<a[l] ? a[f]:a[l];
		temp.max = a[f]>a[l] ? a[f]:a[l];
	}
	else {
		int p = (f+l)/2;
		M p1 = min_max(a,f,p);
		M p2 = min_max(a,p+1,l);
		temp.min = p1.min<p2.min ? p1.min:p2.min;
		temp.max = p1.max>p2.max ? p1.max:p2.max;
	}
	
	return temp;
}
int main() {
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	mm = min_max(a,0,n-1);
	cout<<mm.max<<" "<<mm.min<<endl;
	
	return 0;	
} 
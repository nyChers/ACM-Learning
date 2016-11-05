#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int w,n;
	cin>>w>>n;
	int *a = new int[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a,a+n);
	int left = 0;
	int right = n-1;
	int count = 0;
	while(right>left) {
		if(a[right]+a[left]>w) {
			count++;
			right--;
		}
		else {
			right--;
			left++;
			count++;
		}
	}
	cout<<++count<<endl;
	
	return 0;	
}

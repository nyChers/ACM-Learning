#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int k,m,n;
	while(cin>>k,k!=0){
		cin>>m>>n;
		int *a = new int[m];
		int *l = new int[m-1];
		for(int i=0; i<m; i++){
			cin>>a[i];
		}
		int len = a[m-1] - a[0] + 1;
		for(int i=0; i<m-1; i++){
			l[i] = a[i+1] - a[i] - 1;
		}
		sort(l,l+m-1);
		for(int i=1; i<=n-1; i++){
			len-=l[m-1-i];
		}
		cout<<len<<endl;
	}
	return 0;	
}

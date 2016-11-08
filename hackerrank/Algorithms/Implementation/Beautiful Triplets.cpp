#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,d;
	cin>>n>>d;
	vector<int> a(n);
	for(int i=0; i<n; i++)
	 	cin>>a[i];
	int sum = 0;
	for(int i=0; i<=n-3; i++) {
		for(int j=i+1; j<=n-2; j++) {
			if(a[j]-a[i]==d){
				for(int k=j+1; k<=n-1; k++){
					if(a[k]-a[j]==d)
						sum++;
					if(a[k]-a[j]>d)
						break; 
				}
			}
			if(a[j]-a[i]>d)
				break;
		}
	}
	cout<<sum;
	return 0;
}
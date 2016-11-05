#include <iostream>
#include <algorithm>
using namespace std;

struct event {
	int start;
	int end;	
};
int main() {
	int n;
	cin>>n;
	event *a = new event[n];
	for(int i=0; i<n; i++){
		cin>>a[i].start>>a[i].end;
	}
	int cnt = 1;
	int end = a[0].end;
	cout<<0<<" ";
	for(int i=1; i<n; i++){
		if(a[i].start>=end){
			end = a[i].end;
			cnt++;
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return 0;	
}

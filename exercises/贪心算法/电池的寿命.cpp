#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	int n;
	int bat[1001];
	while(cin>>n) {
		double sum = 0;
		for(int i=0; i<n; i++) {
			cin>>bat[i];
			sum += bat[i];
		}
		sort(bat,bat+n);
		if(bat[n-1]>sum-bat[n-1])
			cout<<fixed<<setprecision(1)<<sum-bat[n-1]<<endl;
		else
			cout<<fixed<<setprecision(1)<<sum/2.0; 
	}
	return 0;
}
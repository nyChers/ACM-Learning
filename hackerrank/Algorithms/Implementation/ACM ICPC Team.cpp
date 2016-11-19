#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n_topic(string a,string b,int m) {
	int cnt = 0;
	for(int i=0; i<m; i++) {
		if(a[i]=='1' || b[i]=='1')
			cnt++;
	}	
	return cnt;
}
int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<string> topic(n);
    for(int topic_i = 0;topic_i < n;topic_i++){
       cin >> topic[topic_i];
    }
    int max = 0;
    int sum = 1;
    for(int i=0; i<n; i++)
    	for(int j=i+1; j<n; j++) {
    		int x = n_topic(topic[i],topic[j],m);
    		if(x>=max) {
    			if(x==max) {
    				sum++;
				}
				else {
					sum = 1;
					max = x;
				}
			} 
		}
    cout<<max<<"\n"<<sum<<endl;
    return 0;
}

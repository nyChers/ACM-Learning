#include <iostream>
#include <algorithm>

using namespace std;
struct room{
	int t;
	int s;
};
int cmp(room a, room b){
	return a.s<b.s;
}
int main() {
	int T;
	cin>>T;
	int n;
	room r[201];
	int *cnt = new int[T];
	for(int o=0; o<T; o++){
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>r[i].s>>r[i].t;
			if(r[i].s>r[i].t)
				swap(r[i].s,r[i].t);
			r[i].s = (r[i].s+1)/2;
			r[i].t = (r[i].t+1)/2;			
		}
		sort(r,r+n,cmp);
		int rs[201] = {0};
		for(int i=0; i<n; i++){
			for(int j=r[i].s; j<=r[i].t; j++){
				rs[j]++;
			}
		}
		int max = 1;
		for(int i=1; i<201; i++){
			if(rs[i]>max)
				max = rs[i];
		}
		cnt[o] = max * 10;
	} 
	for(int i=0; i<T; i++)
		cout<<cnt[i]<<endl;
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

struct str{
	int a;
	int b;
}; 
int cmp(str x, str y){
	if(x.b==y.b)
		return x.a<y.a;
	return x.b<y.b;
}
int main() {
	int n;
	str p[101];
	while(cin>>n,n!=-1){
		for(int i=0; i<n; i++)
			cin>>p[i].a>>p[i].b;
		sort(p,p+n,cmp);
		int end = p[0].b;
		int cnt = 1;
		for(int i=1; i<n; i++) {
			if(p[i].a>end){ 
				cnt++;
				end = p[i].b;
			} 
		} 
		cout<<cnt<<endl;
	}

	return 0;	
}

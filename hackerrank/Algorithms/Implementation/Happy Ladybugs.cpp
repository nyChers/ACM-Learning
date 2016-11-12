#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int g,n;
	string b;
	cin>>g;
	int a[27] = {0};
	vector<string> result;
	for(int z=0; z<g; z++){
		cin>>n>>b;
		memset(a,0,sizeof(a));
		for(int i=0; i<n; i++){
			if(b[i]=='_')
				a[0]++;
			else
				a[b[i]-64]++;
		}
		if(a[0]==0){
			if(b[0]!=b[1] || b[n-1]!=b[n-2])
				result.push_back("NO");
			else{
				for(int i=1; i<n-1; i++){
					if(b[i]==b[i+1] || b[i]==b[i-1]){
						result.push_back("YES");
						break;						
					}
					else{
						result.push_back("NO");
						break;
					}
				}
			}
		}
		else {
			result.push_back("YES");
			for(int i=1; i<27; i++){
				if(a[i]==1){
					result.pop_back();
					result.push_back("NO");
					break;
				}
			}				
		}
	}
	for(int i=0; i<g; i++)
		cout<<result[i]<<endl;
    return 0;
}

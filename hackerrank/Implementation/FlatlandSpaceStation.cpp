#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int cmp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
int main(){
    int n;
    int m;
    cin >> n >> m;
    int* c = new int[m];
    for(int c_i = 0;c_i < m;c_i++){
       cin >> c[c_i];
    }
    qsort(c,m,sizeof(int),cmp);
    int dis=0;
    for(int i=0; i<m-1; i++){
    	if((c[i+1]-c[i])>dis){
    		dis=c[i+1]-c[i];
		}
	}
	dis/=2;
	if(c[0]>dis)
		dis=c[0];
	if((n-1-c[m-1])>dis)
		dis=n-1-c[m-1];
	cout<<dis<<endl;
    return 0;
}


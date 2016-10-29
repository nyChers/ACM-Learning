#include <iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> c(n);
    for(int c_i = 0;c_i < n;c_i++){
       cin >> c[c_i];
    }
    int step=0;
    int e=100;
    while(true){
    	step+=k;
    	if(step>n-1)
    		step%=n;
    	
    	if(c[step]==1)
    		e-=3;
    	else 
    		e-=1;
		if(step==0)
    		break;
	}
	cout<<e<<endl;
    return 0;
}


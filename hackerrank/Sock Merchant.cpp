#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n;
    int sum=0;
    cin >> n;
    vector<int> c(n);
    for(int c_i = 0;c_i < n;c_i++){
       cin >> c[c_i];
    }
	int p[101]={0};
    for(int i=0; i<n; i++){
    	p[c[i]]++;
	}

	
	for(int i=0; i<101; i++){
    	if(p[i] > 1 )
    		sum+=p[i]/2;
	}
	
	cout<<sum<<endl;
    return 0;
}


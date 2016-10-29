#include <vector>
#include <iostream>

using namespace std;


int main(){
    int t;
    cin >> t;
    
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        vector<int> pos(n); 
        if(k==0){
        	for(int i=1; i<=n; i++)
        		cout<<i<<" "; 
        	cout<<endl;
        	continue;
		}
       
        if(n%k==0) {
        	int dev_p=n/k;
        	if(dev_p%2==0){
        		for(int i=0; i<n; i++){
        			if((i/k)%2==0){
        				pos[i]=i+1+k;
					}
					else
						pos[i]=i+1-k;
        		}
        		for(int i=0; i<n; i++)
        			cout<<pos[i]<<" ";
				cout<<endl; 
			}
			else
				cout<<"-1"<<endl;
		} 
		else
			cout<<"-1"<<endl;
    }
    return 0;
}


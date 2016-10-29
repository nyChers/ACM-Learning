#include <iostream>
#include <cmath>

using namespace std;


int main(){
    long long t;
    cin >> t;
    long long sum=0;
    long long temp=0;
    for(int n=1; n<40; n++){
    	sum=3*(pow(2,n)-1);
    	if(t<=sum){
    		temp=1+sum-t;
			break;    		
		}
	}
    cout<<temp<<endl;
    return 0;
}


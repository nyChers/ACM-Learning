#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int sum=0;
        int temp=n,k;
        while(true){
	        k=temp%10;
	        if(k!=0 && n%k==0)
	        	sum++;
	        temp=temp/10;
	        if(temp==0){
	        	cout<<sum<<endl;
	        	break;
   			}
		}
    }
    return 0;
}


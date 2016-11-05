#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){  
    int n;
    cin>>n;
    vector<int> p;
    for(int i=1; i<=9; i++)
    	for(int j=0; j<=9;  j++)
    		for(int k=0; k<=9; k++){
    			if((i+j+k)*2 == n)
    				p.push_back(i*100000+j*10000+k*1100+j*10+i);
    			else if(i+j+k+j+i == n)
    				p.push_back(i*10000+j*1000+k*100+j*10+i);
			}
	sort(p.begin(),p.end());
	for(int i=0;i<p.size();i++)
		cout<<p[i]<<endl;
	return 0;	
}  
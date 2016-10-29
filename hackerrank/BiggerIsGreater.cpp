#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void b_sort(string &p,int n,int x){
	char t;
	for(int i=x+1; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(p[i]>p[j]){
				t=p[i];p[i]=p[j];p[j]=t;
			}
		}	
	}
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	string s;
	int t,l; 
	char temp;
	cin>>t;
	for(int k=0; k<t; k++) {
		cin>>s;
		l=s.length();
		temp='0';
		for(int i=l-2; i>=0; i--){
			for(int j=l-1; j>i; j--){
				if(s[i]<s[j]){
					temp=s[i];s[i]=s[j];s[j]=temp;
					b_sort(s,l,i);
					cout<<s<<endl;
					break;
				}
			}
			if(temp!='0'){
				break;
			}	
		}
		if(temp=='0')
			cout<<"no answer"<<endl;
	}
    return 0;
}


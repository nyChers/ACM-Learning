#include <string>
#include <vector>
#include <iostream>

using namespace std;


int main(){
    string s;
    cin >> s;
    long long n;
    cin >> n;
    long l=s.length();
    long *a = new long[l]{0}; 
	long aNum=0;
	long j=0;
	for(int i=0; i<l; i++){
		if(s[i]=='a'){
			aNum++;	
			a[j]=i+1;
			j++;
		}
		
	}
	long long sum=0;
	sum+=aNum*(n/l);
	long long temp=n%l;
	if(temp != 0){
		for(int i=0; i<j; i++){
			if(a[i]<=temp)
				sum++;
		}
	}
	cout<<sum<<endl;
    return 0;
}


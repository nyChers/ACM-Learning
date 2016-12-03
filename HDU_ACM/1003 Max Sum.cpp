#include<iostream>
#include<cmath>

using namespace std;

int m1,m2;
int temp;
int max_sub(int *v,int n) {//动态规划 
    int sum=-100000001,b=0;
    int i;
    m1 = m2 = temp= 1;
    for (i=0;i<n;i++)
    {
    	b += v[i];
        if(b>sum) {
        	sum=b;   
        	m1 = temp;
			m2 = i + 1;    	
		}
		if(b<0) {
        	b=0;
        	temp = i + 2;
		}
       
    }
    return sum;
}
int main() {
	int t;
	cin>>t;
	int T = t;
	while(t--) {
		int n;
		cin>>n;
		int *a = new int [n];
		for(int i=0; i<n; i++)
			cin>>a[i];
		int m = max_sub(a,n);
		cout<<"Case "<<T-t<<":\n"<<m<<" "<<m1<<" "<<m2<<endl;
		if(t>0)
			cout<<endl;
	} 
	
	return 0;	
} 
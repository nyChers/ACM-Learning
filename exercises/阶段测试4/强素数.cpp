/* 强素数
Problem Description
如果一个n位的素数的左端一位数为素数、左端两位数为素数、……、左端n-1为也为素数，则称该素数为强素数。例如：3119为强素数，因为3、31、311、3119都为素数。给定整数n，求n位的所有强素数。
Input
第一行为一个整数t，表示测试用例的个数。
每个测试用例输入一行，一个整数n，表示强素数的位数。
Output
每个测试用例输出若干行，每一行为一个n位的强素数，请按从小到大的顺序排列。
Sample Input

1
4

Sample Output

2333
2339
2393
2399
2939
3119
3137
3733
3739
3793
3797
5939
7193
7331
7333
7393

 */
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool check(int a){
	for(int i=2;i<=sqrt(a);++i){
		if(a%i==0)
		return 0; 
	}	
	return 1;
}

//每次增加一位，直到有n位 
vector<int> prime(vector<int> n) {  //返回增加一位后的 素数  
	vector<int> p;
	for(int j=0; j<n.size(); ++j)
		for(int i=1; i<=9; i+=2) {
			if( check(n[j]*10+i) )
				p.push_back(n[j]*10+i);
		}
	return p;
}

int main(){
	int t;
	cin>>t;
	vector<int> a = {2,3,5,7};

	while(t--) {
		int n;
		cin>>n;
		vector<int> r = a;
		for(int i=1; i<n; ++i)
			r = prime(r);	
		for(int i=0; i<r.size(); ++i)
			cout<<r[i]<<endl;
	}
	return 0;
}

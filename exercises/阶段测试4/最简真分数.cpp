/* 最简真分数
Problem Description
对于给定的整数n，求所有分母不大于n的最简真分数（分母不小于分子，且分子和分母的最大公因子为1）。
Input
第一行为一个整数t，表示测试样例的数量。
每一个测试用例一行：一个整数，表示给定的整数n(0<n<161)。
Output
每个测试用例输出若干行，每一行表示分母不大于n的最简真分数（格式为：分子/分母），并按分数的值从小到大排序。
Sample Input

2
4
5

Sample Output

0/1
1/4
1/3
1/2
2/3
3/4
1/1
0/1
1/5
1/4
1/3
2/5
1/2
3/5
2/3
3/4
4/5
1/1 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int gcd(int x, int y) {
	if (x > y)
		return gcd(y, x);
	if (y%x == 0)
		return x;
	else
		return gcd(y%x, x);
}

struct zfs{
	int zi;
	int mu;
	zfs(int a,int b) {
		zi = a;
		mu = b;
	}
};
int cmp(zfs a,zfs b) {
	return double(a.zi)/a.mu < double(b.zi)/b.mu;
}
int main() {  
	int t;
	cin>>t;
	vector<zfs> p;
	while(t--) {
		int n;
		cin>>n;
		p.clear();
		for(int i=2; i<=n; i++){
			for(int j=1 ; j<i; j++) {
				if(gcd(i,j)==1){
					zfs temp(j,i);
					p.push_back(temp); 
				}
			}
		}
		sort(p.begin(),p.end(),cmp);
		cout<<"0/1\n";
		for(int i=0; i<p.size(); i++){
			cout<<p[i].zi<<"/"<<p[i].mu<<endl;
		}
		cout<<"1/1\n";
	}
    return 0;  
}  


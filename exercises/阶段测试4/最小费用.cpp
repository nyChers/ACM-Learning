/* 最小费用
Problem Description
一个牛奶公司每天都需要从n个奶农那里购买m升牛奶，给定第i个奶农每天生产牛奶的数量ai以及牛奶的价格为pi，求该公司所需要付出的最小费用。假设牛奶公司可以购买任一奶农的全部或部分牛奶。
Input
第一行为一个整数t，表示测试样例的数量。
对每个测试样例:
第一行为两个整数m和n，分别表示牛奶公司一天所需要的牛奶的数量和奶农的数量（0<=m<=2000000, 0<=n<=5000）。
第2行到第n+1行，每行有两个整数pi和ai，表示第i个奶农的牛奶的价格和每天生产牛奶的数量（0<=pi<=1000, 0<=ai<=2000000）。假设奶农能够满足牛奶公司的需求，即a1+a2+…+an>=m。
Output
一个测试用例输出一行，为一个整数，表示牛奶公司购买牛奶的最小费用。
Sample Input

2
100 5
5 20
9 40
3 10
8 80
6 30
100 6
5 20
9 40
3 10
8 80
6 30
0 100

Sample Output

630
0 */

#include <iostream>
#include <algorithm>
using namespace std;

struct nai{
	int pi;//价格 
	int ai;//奶量 
}; 
int cmp(nai a,nai b) {
	return a.pi<b.pi;
}

int main() {  
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>m>>n;
		int sum = 0;
		int cost = 0;
		nai *p = new nai[n];
		for(int i=0; i<n; i++) 
			cin>>p[i].pi>>p[i].ai;
		sort(p,p+n,cmp);
		for(int i=0; i<n; i++) {
			if(sum+p[i].ai<=m) {
				cost += p[i].pi * p[i].ai;
				sum += p[i].ai;
			}
			else {
				cost = cost + (m-sum)*p[i].pi;
				break;
			}				
		}
		cout<<cost<<endl;
	}
    return 0;  
}  


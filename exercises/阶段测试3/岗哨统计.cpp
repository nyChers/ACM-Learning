// 岗哨统计 

// Problem Description
// 假设一个公司有三个门卫，假设第一个门卫在300秒(从0 点开始计时)到达门岗，一直到1000秒离开，他的站岗时间为700秒；第二个门卫在700秒到达门岗，在 1200秒离开，他的站岗时间为500秒；第三个门卫在1500 秒到达门岗，2100秒离开，站岗时间为600秒。期间(从300秒刻到1200秒)至少有一个门卫的最长连续时间为900 秒，无人站岗的最长的连续时间为300 秒。
// 编一个程序，对给定的门卫数N(1 <= N <= 5000)以及每一个门卫到达和离开门岗的时间，统计如下两个数据(均以秒为单位):
// (1) 至少有一人站岗的最长时间段
// (2) 无人站岗的最长间段
// Input
// 第一行为一个整数t，表示测试用例的个数。
// 每一个测试用例的第一行为一个整数N，为门卫的数量。
// 接下来N行：每一行有两个整数，分别表示各门卫到岗时间si和离岗时间ei，0<si, ei<1000000
// Output
// 每个测试用例输出一行，为两个整数(用空格分隔)，分别表示至少有一人站岗的最长时间段和无人站岗的最长间段
// Sample Input

// 2
// 1
// 100 200
// 4
// 100 200
// 201 301
// 302 402
// 403 503

// Sample Output

// 100 0
// 100 1


#include<iostream>
#include<algorithm>
using namespace std;

struct S_E{
	int start;
	int end;
};

int cmp(S_E a, S_E b) {
	return a.start<b.start;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		S_E *p = new S_E[n];
		for(int i=0; i<n; i++) {
			cin>>p[i].start>>p[i].end;
		}
		sort(p,p+n,cmp);
		
		int s = p[0].start,e = p[0].end;
		int wu = 0;
		int you = e - s;
		
		for(int i=1; i<n; i++) {
			if(p[i].start<=e) {
				if(p[i].end>e)
					e = p[i].end;
			}
			else {
				s = p[i].start;
				if(s-e>wu)
					wu = s - e;
				e = p[i].end;				
			}
			if(you<e-s)
					you = e - s;
		}
		cout<<you<<" "<<wu<<endl;
	}
	return 0;
} 
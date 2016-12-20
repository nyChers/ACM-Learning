#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int x;

int count1(int a) {
	int s = 0;
	while(a) {
		if(a%10==x)
			s++;
		a /= 10;
	}
	return s;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n>>x;
		int sum = 0;
		for(int i=1; i<=n; i++) {
			sum += count1(i);
		}
		cout<<sum<<endl;
	}
    return 0;
}
/* Problem Description
给定整数n和x，统计闭区间[1, n]中的整数中数字x共出现多少次。例如，当n=11时，在1到11中，即在 1、2、3、4、5、6、7、8、9、10、11 中，数字 1 出现了 4 次(1和10中各出现1次，11中出现2次)。
Input
第一行为一个整数t，表示测试用例的数量。
每个测试用例输入一行，输入两个整数n和x（1<=n<=1000000, 0<=x<=9）。
Output
每个测试用例输出一行，每一行一个整数，表示x在[1, n]中出现的次数。
Sample Input
1
11 1
Sample Output
4 */
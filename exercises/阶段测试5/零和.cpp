/* 零和
Problem Description
给定一个整数n(2<n<10)，在序列1 2 3…n中插入“+”(加号)、“-”(减号)或“ ”(空格)（序列的首尾不要插入任何符号），将中间为空格的数字组成一个数，这样得到一个数学表达式，求数学表达式值为0的所有情形
Input
第一行为一个整数t，表示测试样例的个数。
每个测试用例输入一行，只有一个整数n。
Output
每个测试用例输出若干行，表示所有满足条件的表达式。注意：保留插入的空行，且输出的优先顺序为空格、加、减，即先输出1 2之间为空格的情形，在输出1 2之间为加号的情形，最后输出1 2之间为减号的情形……。
Sample Input

2
7
9

Sample Output

1+2-3+4-5-6+7
1+2-3-4+5+6-7
1-2 3+4+5+6+7
1-2 3-4 5+6 7
1-2+3+4-5+6-7
1-2-3-4-5+6+7
1 2+3 4-5 6-7+8+9
1 2+3+4-5-6-7+8-9
1 2+3-4 5+6+7+8+9
1 2+3-4+5-6+7-8-9
1 2-3+4+5 6-7 8+9
1 2-3+4+5+6-7-8-9
1 2-3-4-5+6-7-8+9
1 2-3-4-5-6+7+8-9
1+2-3 4-5 6+7 8+9
1-2 3-4-5 6-7+8 9
1-2-3 4+5+6+7+8+9 */
#include <cmath>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int x[12];
int a[12] = {0,1,2,3,4,5,6,7,8,9};
int b[12];
string s[4];
bool legal(int k) {
	for(int i=0; i<11; i++) 
		a[i] = i;
	if(k==n-1) {
		for(int i=1; i<n; i++) {
			if(x[i]==1) {
				a[i+1] = a[i]*10 +a[i+1];
				a[i] = -1;
			}
		}
		int j=0;
		for(int i=1; i<=n; i++) {
			if(a[i]!=-1) {
				b[j] = a[i];
				j++;				
			}
		}
		int temp = b[0];
		int p = 1;
		for(int i=1; i<n; i++) {
			if(x[i]==2) {
				temp += b[p];
				p++;
			}
			if(x[i]==3) {
				temp -= b[p];				
				p++;
			}
		}
		if(temp!=0)
			return false;
	}
	return true;
}
void dfs(int k) {
	if(k>=n) {
		for(int i=1; i<n; i++)
			cout<<i<<s[x[i]];
		cout<<n<<endl;
	}
	else {
		for(int i=1; i<4; i++) {
			x[k] = i;
			if(legal(k))
				dfs(k+1);
		}
	}
}
int main(){
	s[1] = " ";
	s[2] = "+";
	s[3] = "-";
   	int t;
    cin>>t;
	while(t--) {
		cin>>n;
		dfs(1);
	} 
    return 0;
}

/*算式成立的数量
Problem Description
   B   DEF
A+---+----- = 10
   C   GHI
这个算式中A~I代表1~9的数字，不同的字母代表不同的数字。
比如：
6+8/3+952/714 就是一种解法，
5+3/1+972/486 是另一种解法。
这个算式一共有多少种解法？
注意：你提交应该是个整数，不要填写任何多余的内容或说明性文字。*/
#include<iostream>
#include<cstring> 
using namespace std;
int mark[10];
int a[10];
int cnt = 0;
bool check(int n) {
	if(n==9) {
		int num1 = a[4]*100 + a[5]*10 + a[6];
		int num2 = a[7]*100 + a[8]*10 + a[9];
		int numup = a[2]*num2 + a[3]*num1;
		int numdown = a[3]*num2;
		if(numup%numdown!=0)
			return false;
		if(a[1]+numup/numdown!=10)
			return false;
	}
	return true;
}

void dfs(int x) {
	if(x>9) {
		cnt++;
		return;
	}
	for(int i=1; i<10; i++) {
		if(mark[i]==0) {
			mark[i] = 1;
			a[x] = i;
			if(check(x))
				dfs(x+1);
			mark[i] = 0;
		}
	}
}
int main() {
	memset(a,-1,sizeof(a));
	memset(mark,0,sizeof(mark));
	dfs(1);
	cout<<cnt;
}

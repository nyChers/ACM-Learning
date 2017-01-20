/*算术题
Problem Description
现在小学的数学题目也不是那么好玩的。
看看这个寒假作业：
□ + □ = □
□ - □ = □
□ × □ = □
□ ÷ □ = □ 

每个方块代表1~13中的某一个数字，但不能重复。
比如：
6 + 7 = 13
9 - 8 = 1
3 * 4 = 12
10 / 2 = 5
以及： 
7 + 6 = 13
9 - 8 = 1
3 * 4 = 12
10 / 2 = 5
就算两种解法。（加法，乘法交换律后算不同的方案） 
你一共找到了多少种方案？
请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[20]={-1};
int book[20]={0},sum=0;
void dfs(int x) {
	if(x>3&&a[1]+a[2]!=a[3])
		return;
	if(x>6&&a[4]-a[5]!=a[6])
		return;
	if(x>9&&a[7]*a[8]!=a[9])
		return;
	if(x>12&&a[12]*a[11]==a[10]) {
		sum++;
		return;
	}
	
	for(int i=1;i<14;i++) {
		if(book[i]==0) {
			a[x]=i;
			book[i]=1;
			dfs(x+1);
			book[i]=0;
		}
	}
	return;
}
int main(){
	memset(a,-1,sizeof(a));
	dfs(1);
	cout<<sum;
	return 0;
}
//64

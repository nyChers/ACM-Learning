/*求另一个解

Problem Description
请看下面的算式：
(ABCD - EFGH) * XY = 900
每个字母代表一个0~9的数字，不同字母代表不同数字，首位不能为0。
比如，(5012 - 4987) * 36 就是一个解。
请找到另一个解，并提交该解中 ABCD 所代表的整数。
注意：只提交 ABCD 所代表的整数，不要写其它附加内容，比如：说明性的文字。*/
#include<iostream>
#include<cstring>
using namespace std;
int mark[10];
int a[10];
int num1,num2,num3;
bool check(int n) {
	if(n==0) {
		if(a[0]==0)
			return false;
	}
	if(n==4) {
		if(a[4]==0)
			return false;
	}
	if(n==8) {
		if(a[8]==0)
			return false;
	}
	if(n==9) {
		num1 = a[0]*1000 + a[1]*100 + a[2]*10 + a[3];
		num2 = a[4]*1000 + a[5]*100 + a[6]*10 + a[7];
		num3 = a[8]*10 +a[9];
		if((num1-num2)*num3==900)
			return true;
		else
			return false;
	}
	return true;
}

void dfs(int x) {
	if(x>9) {
		cout<<num1<<endl;
		cout<<num2<<endl;
		cout<<num3<<endl;
		cout<<endl; 
		return;
	}
	for(int i=0; i<10; i++) {
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
	dfs(0);
	
}
//6048

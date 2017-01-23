/*平方特殊的6位数
Problem Description
小明正看着 203879 这个数字发呆。
原来，203879 * 203879 = 41566646641
这有什么神奇呢？仔细观察，203879 是个6位数，并且它的每个数位上的数字都是不同的，并且它平方后的所有数位上都不出现组成它自身的数字。
具有这样特点的6位数还有一个，请你找出它！
再归纳一下筛选要求：
1. 6位正整数
2. 每个数位上的数字不同
3. 其平方数的每个数位不含原数字的任何组成数位
答案是一个6位的正整数。

注意：只提交另一6位数，题中已经给出的这个不要提交。*/
#include<iostream>
#include<cstring>
#include<cmath> 
using namespace std;
int mark[10];
int a[10];
long long num,num2;
bool check(int n) {
	if(a[1]==0)
		return false;
	if(n==6) {
		num = a[1]*100000 + a[2]*10000 +a[3]*1000 + a[4]*100 + a[5]*10 + a[6];
		num2 = num*num;
		while(num2) {
			int s = num2%10;
			for(int i=1; i<=6; i++) 
				if(s==a[i])
					return false;
			num2 /= 10;
		}
	}
	return true;
}

void dfs(int x) {
	if(x>6) {
		cout<<num<<endl;
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
	memset(mark,0,sizeof(mark));
	dfs(1);
	
}
//203879
//639172

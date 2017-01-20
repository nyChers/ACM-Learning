/*不同金字塔的数量

Problem Description
小明最近喜欢搭数字积木，
一共有10块积木，每个积木上有一个数字，0~9。
搭积木规则：
每个积木放到其它两个积木的上面，并且一定比下面的两个积木数字小。
最后搭成4层的金字塔形，必须用完所有的积木。
下面是两种合格的搭法：
___0
__1_2
_3_4_5
6_7_8_9

___0
__3_1
_7_5_2
9_8_6_4 
说明：数字之间的下划线只是为了对齐，没有实际意义
请你计算这样的搭法一共有多少种？
请填表示总数目的数字。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。*/
#include<iostream>
using namespace std;

int a[11];
int mark[11];//数字是否用过 
int sum=0;

int check(int n) {
	if(n%10==5){
		if(a[1]>a[3]||a[1]>a[4]||a[2]>a[4]||a[2]>a[5])
			return 0;
	}
	if(n%10==9){
		for(int i=3;i<6;i++){
			if(a[i]>a[i+3]||a[i]>a[i+4])
				return 0;
		}
	}
	return 1;
}

void dfs(int n) {
	if(n>=10) {
		sum++;
		return;
	}
	for(int i=1; i<10; i++) {
		if(!mark[i]) {
			mark[i]=1;
			a[n]=i;
			if(check(n)) 
				dfs(n+1);
			mark[i]=0;
			
		}
	}
}

int main() {
	for(int i=1;i<11;i++) {
		a[i]=0;
		mark[i]=0;
	}
	a[0]=0;
	mark[0]=1;
	dfs(1);
	cout<<sum;
}
//768

/*粗心的小李
Problem Description
小李的店里专卖其它店中下架的样品电视机，可称为：样品电视专卖店。
其标价都是4位数字（即千元不等）。
这种价牌有个特点，对一些数字，倒过来看也是合理的数字。如：1 2 5 6 8 9 0 都可以。这样一来，如果牌子挂倒了，有可能完全变成了另一个价格，比如：1958 倒着挂就是：8561，差了几千元啊!! 
当然，多数情况不能倒读，比如，1110 就不能倒过来，因为0不能作为开始数字。
有一天，悲剧终于发生了。某个店员不小心把店里的某两个价格牌给挂倒了。并且这两个价格牌的电视机都卖出去了!
庆幸的是价格出入不大，其中一个价牌赔了2百多，另一个价牌却赚了8百多，综合起来，反而多赚了558元。
请根据这些信息计算：赔钱的那个价牌正确的价格应该是多少？
答案是一个4位的整数。
注意：不要提交解答过程，或其它辅助说明类的内容。*/
#include<iostream>
#include<cstring>
#include<cmath> 
using namespace std;
int mark[7] = {1,2,5,6,8,9,0}; 
int a[10];
int num1,num2;
int num1t,num2t;
int turn(int n) {  
    if(n==6)  
        return 9;  
    if(n==9)  
        return 6;  
    return n;  
}  
bool check(int n) {	
	
	if(n==8) {
		if(a[1]==0 || a[5]==0 || a[4]==0 || a[8]==0)
			return false;
		num1 = a[1]*1000 + a[2]*100 + a[3]*10 + a[4];
		num1t = turn(a[4])*1000 + turn(a[3])*100 + turn(a[2])*10 + turn(a[1]);
		if(num1-num1t<200 || num1-num1t>300 )
			return false;
		num2 = a[5]*1000 + a[6]*100 + a[7]*10 + a[8];
		num2t = turn(a[8])*1000 + turn(a[7])*100 + turn(a[6])*10 + turn(a[5]);
		if(num2t-num2<800 || num2t-num2>900 )
			return false;
		if(num2t-num2-num1+num1t!=558)
			return false;
	}
	return true;
}

void dfs(int x) {
	if(x>8) {
		for(int i=1; i<=4; i++)
			cout<<a[i];
		cout<<endl;
		for(int i=5; i<=8; i++)
			cout<<a[i];
		cout<<endl;
		return;
	}
	for(int i=0; i<7; i++) {
		a[x] = mark[i];
		if(check(x))
			dfs(x+1);
	}
}
int main() {
	dfs(1);	
}
//9088

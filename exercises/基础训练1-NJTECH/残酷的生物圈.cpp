/*残酷的生物圈

Problem Description
假设有两种微生物 X 和 Y
X出生后每隔3分钟分裂一次（数目加倍），Y出生后每隔2分钟分裂一次（数目加倍）。
一个新出生的X，半分钟之后吃掉1个Y，并且，从此开始，每隔1分钟吃1个Y。
现在已知有新出生的 X=10, Y=89，求60分钟后Y的数目。
如果X=10，Y=90 呢？
本题的要求就是写出这两种初始条件下，60分钟后Y的数目。
题目的结果令你震惊吗？这不是简单的数字游戏！真实的生物圈有着同样脆弱的性质！也许因为你消灭的那只 Y 就是最终导致 Y 种群灭绝的最后一根稻草！*/ 

#include<iostream>
using namespace std;

int f(int x,int y){
	for(int i=1; i<=120; i++){
		if(i%2==1)
			y-=x;
		if(y<=0)
			return 0;
		if(i%4==0)
			y*=2;
		if(i%6==0){
			x*=2;
		}	
	}
	return y;
}
int main(){
	int x1=10,y1=89;
	int x2=10,y2=90;
	cout<<f(x1,y1)<<endl;
	cout<<f(x2,y2)<<endl;
	return 0;
}

/*硬币方案数

Problem Description
有50枚硬币，可能包括4种类型：1元，5角，1角，5分。
已知总价值为20元。求各种硬币的数量。
比如：2,34,6,8 就是一种答案。
而 2,33,15,0 是另一个可能的答案，显然答案不唯一。
你的任务是确定类似这样的不同的方案一共有多少个（包括已经给出的2个）？
直接提交该数字，不要提交多余的内容。*/

#include<iostream>
using namespace std;

int main() {
	int cnt = 0;
	for(int a=0; a<=20; a++)
		for(int b=0; b<=40; b++)
			for(int c=0; c<=200; c++)
				for(int d=0; d<=400; d++) {
					if(a*20+b*10+c*2+d==400 && a+b+c+d==50)
						cnt++;
				}
	cout<<cnt<<endl; 
} 
//50

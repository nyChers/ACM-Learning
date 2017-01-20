/*特殊的数字

Problem Description
有些数字的立方的末尾正好是该数字本身。
比如：1,4,5,6,9,24,25,....
请你计算一下，在10000以内的数字中（指该数字，并非它立方后的数值），符合这个特征的正整数一共有多少个。

请提交该整数，不要填写任何多余的内容。*/
#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int sum = 0;
	for(int i=1; i<=9; i++)
		if(i == int(pow(i,3))%10)
			sum++;
	for(int i=10; i<=99; i++)
		if(i == int(pow(i,3))%100)
			sum++;
	for(int i=100; i<=999; i++)
		if(i == int(pow(i,3))%1000)
			sum++;
	for(long long i=1000; i<=9999; i++)
		if(i == (i*i*i)%10000)
			sum++;
	cout<<sum<<endl;
}
//36

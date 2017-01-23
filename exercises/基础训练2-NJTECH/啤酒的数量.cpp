/*啤酒的数量

Problem Description
啤酒每罐2.3元，饮料每罐1.9元。小明买了若干啤酒和饮料，一共花了82.3元。
我们还知道他买的啤酒比饮料的数量少，请你计算他买了几罐啤酒。
注意：答案是一个整数。
不要书写任何多余的内容（例如：写了饮料的数量，添加说明文字等）。*/
#include<iostream> 
using namespace std;

int main() {
	int a = 23;
	int b = 19;
	int sum = 823;
	for(int i=0; i<36; i++) {
		for(int j=i; j<44; j++) {
			if(a*i+b*j==sum)
				cout<<"啤酒"<<i<<"\n饮料"<<j;
		}
	}
}
//11 

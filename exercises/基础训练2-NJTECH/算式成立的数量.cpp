/*��ʽ����������
Problem Description
   B   DEF
A+---+----- = 10
   C   GHI
�����ʽ��A~I����1~9�����֣���ͬ����ĸ����ͬ�����֡�
���磺
6+8/3+952/714 ����һ�ֽⷨ��
5+3/1+972/486 ����һ�ֽⷨ��
�����ʽһ���ж����ֽⷨ��
ע�⣺���ύӦ���Ǹ���������Ҫ��д�κζ�������ݻ�˵�������֡�*/
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

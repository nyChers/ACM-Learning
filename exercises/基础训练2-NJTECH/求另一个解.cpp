/*����һ����

Problem Description
�뿴�������ʽ��
(ABCD - EFGH) * XY = 900
ÿ����ĸ����һ��0~9�����֣���ͬ��ĸ����ͬ���֣���λ����Ϊ0��
���磬(5012 - 4987) * 36 ����һ���⡣
���ҵ���һ���⣬���ύ�ý��� ABCD �������������
ע�⣺ֻ�ύ ABCD ���������������Ҫд�����������ݣ����磺˵���Ե����֡�*/
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

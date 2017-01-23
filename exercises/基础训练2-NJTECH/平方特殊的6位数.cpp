/*ƽ�������6λ��
Problem Description
С�������� 203879 ������ַ�����
ԭ����203879 * 203879 = 41566646641
����ʲô�����أ���ϸ�۲죬203879 �Ǹ�6λ������������ÿ����λ�ϵ����ֶ��ǲ�ͬ�ģ�������ƽ�����������λ�϶��������������������֡�
���������ص��6λ������һ���������ҳ�����
�ٹ���һ��ɸѡҪ��
1. 6λ������
2. ÿ����λ�ϵ����ֲ�ͬ
3. ��ƽ������ÿ����λ����ԭ���ֵ��κ������λ
����һ��6λ����������

ע�⣺ֻ�ύ��һ6λ���������Ѿ������������Ҫ�ύ��*/
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

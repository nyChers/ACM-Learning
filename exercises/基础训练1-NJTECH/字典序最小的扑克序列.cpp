/*�ֵ�����С���˿�����

Problem Description
A A 2 2 3 3 4 4�� һ��4���˿��ơ�����������ų�һ�С�
Ҫ������A�м���1���ƣ�����2֮����2���ƣ�����3֮����3���ƣ�����4֮����4���ơ�
����д�����з���Ҫ��������У��ֵ�����С���Ǹ���
���磺22AA3344 �� A2A23344 �ֵ���С����Ȼ�����Ƕ���������Ҫ��Ĵ𰸡�
��A��һ����Ҫ��Сд��ĸa��Ҳ��Ҫ�á�1�����档�ַ���һ����Ҫ���ո�*/
#include<iostream>
#include<cstring>
using namespace std;
char a[8];
char b[3] = {'3','4','A'};
int mark[3] = {0,0,0};

void huitui(int i,int x) {
	a[x] = '0';
	if(i==0) {
		a[x+4] = '0';
	}
	if(i==1) {
		a[x+5] = '0';
	}
	if(i==2) {
		a[x+2] = '0';
	}	
}

bool check(int i,int x) {
	if(i==0) {
		if(x+4<=7 && a[x+4]=='0') {
			a[x+4] = '3';
			return true;
		}
	}
	if(i==1) {
		if(x+5<=7 && a[x+5]=='0') {
			a[x+5] = '4';
			return true;
		}
	}
	if(i==2) {
		if(x+2<=7 && a[x+2]=='0') {
			a[x+2] = 'A';
			return true;
		}
	}
	return false;
}
void dfs(int x) {
	if(x>7) {
		for(int i=0; i<8; i++)
			cout<<a[i];
		cout<<endl;
		return;
	}
	if(a[x]=='0'){
		for(int i=0; i<3; i++) {
			if(mark[i]==0) {
				mark[i] = 1;
				a[x] = b[i];
				if(check(i,x)) {
					dfs(x+1);
					huitui(i,x);
				}
				mark[i] = 0;
			}
		}	 
	}else{
		dfs(x+1);
	}
	return;
}
int main() {
	for(int i=0; i<=7; i++)
		a[i] = '0';
	a[0] = '2';
	a[3] = '2';
	dfs(1);
}

//2342A3A4

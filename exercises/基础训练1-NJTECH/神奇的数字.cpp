/*���������
Problem Description
��һ��6λ�������������и�����������ʣ�
�ֱ���2 3 4 5 6ȥ�������õ�����Ȼ��6λ�������ҳ˻��������������������6λ����ȫһ����
ֻ���������ǵ�˳�����������˶��ѡ�
���������6λ����
����һ����������Ҫ��д�κζ�������ݣ�����˵���Ե����֣�*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[6];
int b[6]; 
bool checkn(int i,int n) {
	
	int x = 0;
	int y = i*n;
	while(i) {
		a[x] = i%10;
		i /= 10;
		x++;
	}
	x = 0;
	
	while(y) {
		b[x] = y%10;
		y /= 10;
		x++;
	}
	sort(a,a+6);
	sort(b,b+6);
	for(int k=0; k<6; k++) {
		if(a[k]!=b[k])
			return false;
	}
	return true;
}
bool check(int i) {
	for(int j=2; j<=6; j++)
		if(!checkn(i,j))
			return false;
	return true;
}
int main() {
	for(int i=100000; i<166667; i++) {
		if(check(i))
			cout<<i;
	}
}
//142857

/*������

Problem Description
һ���߽����棬�м���һ�������Եõ�2��������
����ȶ���1�Σ��м���һ�������Եõ�3��������
�����������2�Σ��м���һ�������Եõ�5��������
��ô����������10�Σ��м���һ������õ����������أ� 
���Ǹ���������Ҫ��д�κζ�������ݡ�*/
#include<iostream>
#include<cmath>

using namespace std;

int cut_noodles(int n) {
		return 1+pow(2,n);
}

int main(){
	int n = 10;
//	cin>>n;
	cout<<cut_noodles(n)<<endl;
	return 0;
}

/*���������

Problem Description
��Щ���ֵ�������ĩβ�����Ǹ����ֱ���
���磺1,4,5,6,9,24,25,....
�������һ�£���10000���ڵ������У�ָ�����֣����������������ֵ�����������������������һ���ж��ٸ���

���ύ����������Ҫ��д�κζ�������ݡ�*/
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

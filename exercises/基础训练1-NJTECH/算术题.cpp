/*������
Problem Description
����Сѧ����ѧ��ĿҲ������ô����ġ�
�������������ҵ��
�� + �� = ��
�� - �� = ��
�� �� �� = ��
�� �� �� = �� 

ÿ���������1~13�е�ĳһ�����֣��������ظ���
���磺
6 + 7 = 13
9 - 8 = 1
3 * 4 = 12
10 / 2 = 5
�Լ��� 
7 + 6 = 13
9 - 8 = 1
3 * 4 = 12
10 / 2 = 5
�������ֽⷨ�����ӷ����˷������ɺ��㲻ͬ�ķ����� 
��һ���ҵ��˶����ַ�����
����д��ʾ������Ŀ��������
ע�⣺���ύ��Ӧ����һ����������Ҫ��д�κζ�������ݻ�˵�������֡�*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[20]={-1};
int book[20]={0},sum=0;
void dfs(int x) {
	if(x>3&&a[1]+a[2]!=a[3])
		return;
	if(x>6&&a[4]-a[5]!=a[6])
		return;
	if(x>9&&a[7]*a[8]!=a[9])
		return;
	if(x>12&&a[12]*a[11]==a[10]) {
		sum++;
		return;
	}
	
	for(int i=1;i<14;i++) {
		if(book[i]==0) {
			a[x]=i;
			book[i]=1;
			dfs(x+1);
			book[i]=0;
		}
	}
	return;
}
int main(){
	memset(a,-1,sizeof(a));
	dfs(1);
	cout<<sum;
	return 0;
}
//64

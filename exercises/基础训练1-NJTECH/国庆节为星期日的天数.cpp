/*�����Ϊ�����յ�����
Problem Description
1949��Ĺ���ڣ�10��1�գ����������� 
���꣨2017���Ĺ�����������ա�
��ô���ӽ��������꣬�м��ι�����������������أ�
ֻҪ�𰸣������ֶΣ�������windows������windows��������Excel��ʽ������������ 
��Ȼ��Ҳ���Ա�̣�
��Ҫ��д����������Щ�ֻ꣬Ҫһ����Ŀ��
ǧ��Ҫ�ύԴ����*/
#include<iostream>
using namespace std;

int ds[2] = {365,366};
int year[100] = {6};

void cal(int y) {
	if((y%4==0 && y%100!=0) || y%400==0)
		year[y-1949] = (year[y-1-1949]+366) % 7;
	else
		year[y-1949] = (year[y-1-1949]+365) % 7;
}
int main(){
	int cnt = 0;
	for(int i=1950; i<=2017; i++){
		cal(i);
	}
	for(int i=1949; i<=2017; i++){
		if(year[i-1949]==0)
			cnt++;
	}
	cout<<cnt<<endl;
}
//10

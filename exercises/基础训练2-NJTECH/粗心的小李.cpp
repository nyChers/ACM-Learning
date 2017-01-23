/*���ĵ�С��
Problem Description
С��ĵ���ר�����������¼ܵ���Ʒ���ӻ����ɳ�Ϊ����Ʒ����ר���ꡣ
���۶���4λ���֣���ǧԪ���ȣ���
���ּ����и��ص㣬��һЩ���֣���������Ҳ�Ǻ�������֡��磺1 2 5 6 8 9 0 �����ԡ�����һ����������ӹҵ��ˣ��п�����ȫ�������һ���۸񣬱��磺1958 ���ŹҾ��ǣ�8561�����˼�ǧԪ��!! 
��Ȼ������������ܵ��������磬1110 �Ͳ��ܵ���������Ϊ0������Ϊ��ʼ���֡�
��һ�죬�������ڷ����ˡ�ĳ����Ա��С�İѵ����ĳ�����۸��Ƹ��ҵ��ˡ������������۸��Ƶĵ��ӻ�������ȥ��!
���ҵ��Ǽ۸���벻������һ����������2�ٶ࣬��һ������ȴ׬��8�ٶ࣬�ۺ�������������׬��558Ԫ��
�������Щ��Ϣ���㣺��Ǯ���Ǹ�������ȷ�ļ۸�Ӧ���Ƕ��٣�
����һ��4λ��������
ע�⣺��Ҫ�ύ�����̣�����������˵��������ݡ�*/
#include<iostream>
#include<cstring>
#include<cmath> 
using namespace std;
int mark[7] = {1,2,5,6,8,9,0}; 
int a[10];
int num1,num2;
int num1t,num2t;
int turn(int n) {  
    if(n==6)  
        return 9;  
    if(n==9)  
        return 6;  
    return n;  
}  
bool check(int n) {	
	
	if(n==8) {
		if(a[1]==0 || a[5]==0 || a[4]==0 || a[8]==0)
			return false;
		num1 = a[1]*1000 + a[2]*100 + a[3]*10 + a[4];
		num1t = turn(a[4])*1000 + turn(a[3])*100 + turn(a[2])*10 + turn(a[1]);
		if(num1-num1t<200 || num1-num1t>300 )
			return false;
		num2 = a[5]*1000 + a[6]*100 + a[7]*10 + a[8];
		num2t = turn(a[8])*1000 + turn(a[7])*100 + turn(a[6])*10 + turn(a[5]);
		if(num2t-num2<800 || num2t-num2>900 )
			return false;
		if(num2t-num2-num1+num1t!=558)
			return false;
	}
	return true;
}

void dfs(int x) {
	if(x>8) {
		for(int i=1; i<=4; i++)
			cout<<a[i];
		cout<<endl;
		for(int i=5; i<=8; i++)
			cout<<a[i];
		cout<<endl;
		return;
	}
	for(int i=0; i<7; i++) {
		a[x] = mark[i];
		if(check(x))
			dfs(x+1);
	}
}
int main() {
	dfs(1);	
}
//9088

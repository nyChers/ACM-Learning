/*��˺����ֲ���

Problem Description
��4����ͬ�����֣���ɵ�һ���˷���ʽ�����ǵĳ˻���Ȼ����4��������ɡ�
���磺
210 x 6 = 1260
8 x 473 = 3784
27 x 81 = 2187
������Ҫ��
�������˷������ɵ���ʽ����ͬһ���������ô�������ϱ����г���3�������һ���ж���������Ҫ�����ʽ��
����д�����֣�ͨ��������ύ�𰸣���Ҫ��д�������ݣ����磺�г�������ʽ����*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	int num;
	int cnt = 0;
	int a[4];
	int b[5];
	for(int i=1; i<100; i++)
		for(int j=10; j<1000; j++) {
			num = i*j;
			if(num<1000 || num>9999)
				continue;
			int flag = true;
			if(i<10 && j>99) {
				a[0] = i;
				a[1] = j/100;
				a[3] = j%10;
				a[2] = j%100/10;
				
			} else if(i>9 && j<100 && i<=j) {
				a[0] = i/10;
				a[1] = i%10;
				a[2] = j/10;
				a[3] = j%10;
				
			} else
				continue;
			b[0] = num/1000;
			b[1] = num/100%10;
			b[2] = num%100/10;
			b[3] = num%10;
			sort(a,a+4);
			sort(b,b+4);
			for(int k=0; k<3; k++) {
				if(a[k]==a[k+1])
					flag = false;
			} 
			for(int k=0; k<4; k++) {
				if(a[k]!=b[k])
					flag = false;
			}
			if(flag) {
				cnt++;
				cout<<i<<' '<<j<<' '<<num<<endl;
			}
		
		}
		cout<<cnt;
}
//12

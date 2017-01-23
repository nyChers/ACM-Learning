/*相乘后数字不变

Problem Description
由4个不同的数字，组成的一个乘法算式，它们的乘积仍然由这4个数字组成。
比如：
210 x 6 = 1260
8 x 473 = 3784
27 x 81 = 2187
都符合要求。
如果满足乘法交换律的算式算作同一种情况，那么，包含上边已列出的3种情况，一共有多少种满足要求的算式。
请填写该数字，通过浏览器提交答案，不要填写多余内容（例如：列出所有算式）。*/
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

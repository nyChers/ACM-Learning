/* 13日
Problem Description
统计n年内（从1900年1月1日到1900+n-1年12月31日）星期1、星期2、…星期日为13日的次数。已知1900年1月1日为星期1。
Input
第一行为一个整数t，表示测试用例的个数。
一个测试用例输入一行：一个整数，表示n。
Output
每个测试用例输出一行，共7个数字，表示13日为星期六、星期日、星期一、……星期五的次数。
Sample Input

1
20

Sample Output

36 33 34 33 35 35 34
 */

#include <iostream>
#include <cstring>
using namespace std;

int a[7] = {0};
int mon[] = {31,31,28,31,30,31,30,31,31,30,31,30,31};
int main() {  
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int d = 4; //(31+4)%7 = 0 为周六 
		memset(a,0,sizeof(a));
		for(int i=1900; i<1900+n; i++) {
			mon[2] = 28;
			if(i%400==0 || (i%4==0 && i%100!=0))
				mon[2] = 29;
			for(int j=1; j<13; j++) {
				d = (d+mon[j-1]) % 7;
				a[d]++;
			}	
		}
		for(int j=0; j<6; j++)
			cout<<a[j]<<" ";
		cout<<a[6]<<endl;
	}
    return 0;  
}  


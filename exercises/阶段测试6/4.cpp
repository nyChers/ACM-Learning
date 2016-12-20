#include <iostream> 
#include <algorithm>
using namespace std;

int d;
int num[70] = {0};

bool check(int a,int b) {
	int d1 = 0;
	int c = a^b;
	int i = 1;
	for(int j=0; j<32; j++) {
		if(i>c)
			break;
		if(c&i)
			d1++;	
		i *= 2;
	}
	if(d1>=d)
		return true;
	return false;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		int k = 1;
		int i = 1;
		cin>>n>>d;
		while(k<n) {
			for(int j=1; j<=k; j++) {
				if(!check(i,num[j])) 
					break;
				if(j==k)
					num[++k] = i;				
			}
			i++;
		}
		for(int i=1; i<=n; i++) {
			cout<<num[i];
			if(i==n || i%10==0)
				cout<<endl;
			else
				cout<<" ";

		}
	}
}
/* Problem Description
给定两个整数n（1<=n<=64）和d（1<=d<=7），找到n个非负整数（必须包含0），使得这n个整数中任意两个数之间的“距离”不小于d。这里的”距离”是指这两个数的二进制数对应数字(0或1)不相同的数量。例如两个整数（16进制）0x554和0x234，它们的二进制数分别为：
  0x554 = 0101 0101 0100
  0x234 = 0010 0011 0100
则这两个数不同的二进制位有5个（左起第1、2、3、5、6位），因此这两个数的距离为5.
提示：计算两个正整数a和b的“距离”的方法为：先计算a和b的“按位异或”：c = a^b，则c的二进制表示中1的数量即为a和b的”距离”，可通过将c分别与1, 4, 8, 16, …进行“按位与”的方法计算c中1的数量。
Input
第一行为一个整数t，表示测试样例的数量。
每一个测试样例输入一行，包括两个整数：n和d。


Output
每个测试样例输出n个整数(第一个为0)，整数之间用空格分隔，如果n大于10，则每行输出10个数字。为避免多解的情形，应采取如下方法：首先寻找第一个与0的距离不小于d的最小整数a1，然后寻找与0和a1的距离都不小于d的最小整数a2，……，直到求得n个数为止。
注意每一行的行尾不要有多余的空格。
Sample Input
1
16 3
Sample Output
0 7 25 30 42 45 51 52 75 76
82 85 97 102 120 127 */
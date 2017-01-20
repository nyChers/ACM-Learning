/*神奇的数字
Problem Description
有一个6位的正整数，它有个很神奇的性质：
分别用2 3 4 5 6去乘它，得到的仍然是6位数，并且乘积中所包含的数字与这个6位数完全一样！
只不过是它们的顺序重新排列了而已。
请计算出这个6位数。
这是一个整数，不要填写任何多余的内容（比如说明性的文字）*/
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

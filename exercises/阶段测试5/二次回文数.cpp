/* 二次回文数
Problem Description
有些数的十进制不是回文数，但其他进制为回文数，例如十进制数21不是回文数，但其二进制数10101为回文数。对于给定两个整数n和s，求大于s的n个最小整数，它们的2~10进制数中至少有两个为回文数。
Input
第一行为一个整数t，表示测试样例的个数。
每个测试样例输入一行，包括两个整数n和s（0<n<16, 0<s<10000）。
Output
每个测试用例输出n行，每一行一个整数，该整数大于s，且其2~10进制数中至少有2个为回文数，n个数为满足条件的最小整数，且按照从小到大的顺序输出。
Sample Input

1
3 25

Sample Output

26
27
28 */
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;


string change(int k,int n) {
	string s = "";
	while(k) {
		int a = k%n;
		char c;
		if(a<=9){
			c = a +'0';
		}
		else {
			c = a +55;
		}
		s = s + c;
		k /= n;
	}
	reverse(s.begin(),s.end());
	return s;
}
bool check(string s) {
//	for(int i=0; i<(s.end()-s.begin())/2; i++)
//		if(*(s.begin()+i) != *(s.end()-1-i))
//			return false;
//	return true;
	string a = s;
	reverse(s.begin(),s.end());
	if(a == s)	
		return true;
	return false;
}
int main() {
	int t, n, s;
	cin >> t;
	while (t--) {
		cin>>n>>s;
		while(n) {
			s++;
			int j = 0;
			for(int i=2; i<=10; i++) {
				if(check(change(s,i))) {
					j++;
					if(j==2) {
						cout<<s<<endl;
						n--;
						break; 
					}
				}
			}
		}
	}
	return 0;
}
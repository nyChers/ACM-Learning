// 回文数的变形
// Problem Description
// 回文数是指从左向右读和从右向左读为同一个数，例如1234321为回文数。
// 给定一个十进制整数B(1<B<21)，求一个十进制整数k（0<k<=300），满足k的平方用B 进制表示时是回文数，在进制表示中，用大写字母’A’, ‘B’, ……表示10, 11, ……
// Input
// 第一行为一个整数t，表示测试用例的个数。
// 对每一个测试用例，输入一个十进制整数，表示B。
// Output
// 对每个测试用例，输出所有满足条件的数。
// 一个测试用例可能有多行，每行包括两个数字（中间用空格分隔），第一个数为k（B进制数），第二个数为k的平方（B进制数），且第二个数为回文数。
// Sample Input

// 2
// 18
// 20

// Sample Output

// 1 1
// 2 4
// 3 9
// 4 G
// 11 121
// 22 484
// 2D 777
// 3B D0D
// 1 1
// 2 4
// 3 9
// 4 G
// 11 121
// 22 484
// 25 515
// 33 9I9
// DD 9669

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
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
	string a = s;
	reverse(s.begin(),s.end());
	if(a == s)	
		return true;
	return false;
}
int main() {
	int t; 
	cin>>t;
	while(t--) {
		int B;
		cin>>B;
		for(int i=1; i<=300; i++) {
			int k = i * i;
			string str = change(k,B);
			if(check(str))
				cout<<change(i,B)<<" "<<str<<endl;
		}
	}
	return 0;
} 
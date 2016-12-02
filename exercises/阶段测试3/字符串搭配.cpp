// Problem Description
// 给定两个由大写字母构成的字符串（长度为1~6），判断这两个字符串是否“搭配”。两个字符串是否搭配的判断标准如下：
// （1）计算这两个字符串的值：设’A’为1, ‘B’为2, … ‘Z’为26，一个字符串的值为该字符串中各个字符值的乘积，例如：’ABC’的值为1*2*3=6。
// （2）将两个字符串的值对47取模，如果相等，则认为这两个字符串搭配，否则不搭配。
// Input
// 第一行为一个整数t，表示测试用例个数。
// 接下来共有t*2行，每两行表示一个测试用例，其中第一行为第一个字符串，第二行为第二个字符串。两个字符串都由大写字母构成。
// Output
// 共输出t行，一个测试用例输出一行，如果两个字符串搭配，则输出”YES”，否则输出”NO”
// Sample Input

// 2
// COMETQ
// HVNGAT
// STARAB
// USACO

// Sample Output

// YES
// NO

include<iostream>
#include<string>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		string s1,s2;
		int sum1 = 1;
		int sum2 = 1;
		cin>>s1>>s2;
		for(int i=0; i<s1.length(); i++) {
			sum1 *= (s1[i] - 'A' + 1);
		}	
		for(int i=0; i<s2.length(); i++) {
			sum2 *= (s2[i] - 'A' + 1);
		}
//		cout<<sum1<<endl;
//		cout<<sum2<<endl;
		sum1 %= 47;
		sum2 %= 47;
//		cout<<sum1<<endl;
//		cout<<sum2<<endl;
		if(sum1 == sum2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl; 
	}
	return 0;
} 
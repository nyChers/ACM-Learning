/*怎么又是年龄问题
Problem Description
小明和他的表弟一起去看电影，有人问他们的年龄。
小明说：今年是我们的幸运年啊。我出生年份的四位数字加起来刚好是我的年龄。表弟的也是如此。
假设今年是2014年（2014年的题），并且，小明说的年龄指的是周岁。
请推断并填写出小明的出生年份。
这是一个4位整数，请通过浏览器提交答案，不要填写任何多余的内容（比如，他表弟的出生年份，或是他们的年龄等等）*/
#include<iostream>
using namespace std;

int check(int y) {
	int sum = 0;
	while(y) {
		sum += y%10;
		y /= 10; 
	}
	return sum;
}
int main() {
	int y = 2014;
	int age = 0;
	int cnt = 0;
	while(true) {
		y--;
		age++;
		if(check(y)==age) {
			cout<<y<<endl;
			cnt++;
			if(cnt==2)
				break;
		}			
	}
}
//1988

/*国庆节为星期日的天数
Problem Description
1949年的国庆节（10月1日）是星期六。 
今年（2017）的国庆节是星期日。
那么，从建国到今年，有几次国庆节正好是星期日呢？
只要答案，不限手段！可以用windows日历，windows计算器，Excel公式，。。。。。 
当然，也可以编程！
不要求写出具体是哪些年，只要一个数目！
千万不要提交源代码*/
#include<iostream>
using namespace std;

int ds[2] = {365,366};
int year[100] = {6};

void cal(int y) {
	if((y%4==0 && y%100!=0) || y%400==0)
		year[y-1949] = (year[y-1-1949]+366) % 7;
	else
		year[y-1949] = (year[y-1-1949]+365) % 7;
}
int main(){
	int cnt = 0;
	for(int i=1950; i<=2017; i++){
		cal(i);
	}
	for(int i=1949; i<=2017; i++){
		if(year[i-1949]==0)
			cnt++;
	}
	cout<<cnt<<endl;
}
//10

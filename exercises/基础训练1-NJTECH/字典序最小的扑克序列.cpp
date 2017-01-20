/*字典序最小的扑克序列

Problem Description
A A 2 2 3 3 4 4， 一共4对扑克牌。请你把它们排成一行。
要求：两个A中间有1张牌，两个2之间有2张牌，两个3之间有3张牌，两个4之间有4张牌。
请填写出所有符合要求的排列中，字典序最小的那个。
例如：22AA3344 比 A2A23344 字典序小。当然，它们都不是满足要求的答案。
“A”一定不要用小写字母a，也不要用“1”代替。字符间一定不要留空格。*/
#include<iostream>
#include<cstring>
using namespace std;
char a[8];
char b[3] = {'3','4','A'};
int mark[3] = {0,0,0};

void huitui(int i,int x) {
	a[x] = '0';
	if(i==0) {
		a[x+4] = '0';
	}
	if(i==1) {
		a[x+5] = '0';
	}
	if(i==2) {
		a[x+2] = '0';
	}	
}

bool check(int i,int x) {
	if(i==0) {
		if(x+4<=7 && a[x+4]=='0') {
			a[x+4] = '3';
			return true;
		}
	}
	if(i==1) {
		if(x+5<=7 && a[x+5]=='0') {
			a[x+5] = '4';
			return true;
		}
	}
	if(i==2) {
		if(x+2<=7 && a[x+2]=='0') {
			a[x+2] = 'A';
			return true;
		}
	}
	return false;
}
void dfs(int x) {
	if(x>7) {
		for(int i=0; i<8; i++)
			cout<<a[i];
		cout<<endl;
		return;
	}
	if(a[x]=='0'){
		for(int i=0; i<3; i++) {
			if(mark[i]==0) {
				mark[i] = 1;
				a[x] = b[i];
				if(check(i,x)) {
					dfs(x+1);
					huitui(i,x);
				}
				mark[i] = 0;
			}
		}	 
	}else{
		dfs(x+1);
	}
	return;
}
int main() {
	for(int i=0; i<=7; i++)
		a[i] = '0';
	a[0] = '2';
	a[3] = '2';
	dfs(1);
}

//2342A3A4

// 图形变换
// Problem Description
// 将一块N x N（1<=N<=10）方形图案(原图案)通过指定的转换操作转换为目标方形图案。
// 转换操作只能采取如下方法中的一种:
// 1: 按顺时针转90 度
// 2: 顺时针转180 度
// 3: 按顺时针转270 度
// 4: 水平方向翻转（沿竖直中心轴旋转一圈）
// 5: 先按方法4翻转，然后按照方法1-方法3中的一种转换
// 6: 原图案和目标图一致
// 7: 无法用以上方法得到目标图案.
// 如果有多种转换方法，则选择序号最小的。
// Input
// 第一行为一个整数t，表示测试用例的个数。
// 每一个测试用例的第一行为一个整数，表示N
// 接下来的N行: 每行N 个字符（’@’或’-‘），表示原图案，字符之间没有空格。
// 接下来的N行: 每行N 个字符（’@’或’-‘），表示目标图案，字符之间没有空格
// Output
// 对每一个测试用例，输出一行，只有一个整数（1~7），表示转换方法（不能得到目标图案则输出7），如果有多个答案，则输出较小的数。
// Sample Input

// 1
// 5
// -@@@-
// -@@--
// -@---
// -----
// -----
// -----
// ----@
// ---@@
// --@@@
// -----

// Sample Output

// 5

#include<iostream>
#include<algorithm>

using namespace std;
char src[11][11];
char des[11][11];
int n;

bool change_s90() {
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) 
			if(src[i][j]!=des[j][n-1-i])
				return false;
	return true;		
}
bool change_s180() {
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) 
			if(src[i][j]!=des[n-1-i][n-1-j])
				return false;
	return true;			
}
bool change_s270() {
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) 
			if(src[i][j]!=des[n-1-j][i])
				return false;
	return true;			
}
void change_spfz() {//水平翻转
	for(int i=0; i<n; i++)
		for(int j=0; j<n/2; j++) {
			swap(src[i][j],src[i][n-1-j]);
		}
}
bool equal_src_des() {
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) 
			if(src[i][j]!=des[i][j])
				return false;
	return true;
}

int main() {
	int t; 
	cin>>t;
	while(t--) {
		cin>>n;
		
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) {
				cin>>src[i][j];
			}
				
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) {
				cin>>des[i][j];
			}
			
		if(change_s90()) {
			cout<<"1"<<endl;
			continue;
		}
		if(change_s180()) {
			cout<<"2"<<endl;
			continue;
		}
		if(change_s270()) {
			cout<<"3"<<endl;
			continue;
		}
	
		change_spfz();
		
		if(equal_src_des()) {
			cout<<"4"<<endl;
			continue;
		}
		if(change_s90() || change_s180() || change_s270()) {
			cout<<"5"<<endl;
			continue;
		}
		
		change_spfz();
		if(equal_src_des()) {
			cout<<"6"<<endl;
			continue;
		}
		cout<<"7"<<endl;		
	}
	return 0;
} 
/*切面条

Problem Description
一根高筋拉面，中间切一刀，可以得到2根面条。
如果先对折1次，中间切一刀，可以得到3根面条。
如果连续对折2次，中间切一刀，可以得到5根面条。
那么，连续对折10次，中间切一刀，会得到多少面条呢？ 
答案是个整数，不要填写任何多余的内容。*/
#include<iostream>
#include<cmath>

using namespace std;

int cut_noodles(int n) {
		return 1+pow(2,n);
}

int main(){
	int n = 10;
//	cin>>n;
	cout<<cut_noodles(n)<<endl;
	return 0;
}

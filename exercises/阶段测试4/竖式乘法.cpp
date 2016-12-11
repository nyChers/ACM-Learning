/* Problem Description
下面是一个乘法竖式运算，求用给定的数字来取代*，使该竖式成立的不同情形的数量。
	* * *
	x * *
------------
	* * *
  * * *
----------
* * * *
注意：一个*表示一个数字，不能增加*，也不能减少*。
Input
第一行为一个整数t，表示测试用例的个数。
每个测试用例两行：第一行为一个整数n(0<n<10)，表示给定数字的个数，第二行为n个整数，表示给定的数字ai(ai为1~9之间的整数)。
Output
输出一个整数，为满足条件算式的个数。
Sample Input

2
5
2 3 4 6 8
7
4 1 2 5 6 7 3

Sample Output

1
384

样例1说明：
满足第一个测试用例的算式只有1个：
     2 2 2
x 	2 2
---------------
     4 4 4
  4 4 4
---------------
  4 8 8 4
 */
 
 
// 回溯法：
#include<iostream>
#include<algorithm>
using namespace std;

int n, cnt;
int a[10];
int b[6];
bool check(int x) {
	for (int i = 0; i < n; i++) {
		if (x == a[i])
			return true;
	}
	return false;
}

bool checkNum3(int x) {
	if (x > 999)
		return false;
	while (x) {
		if (!check(x % 10))
			return false;
		x /= 10;
	}
	return true;
}

bool checkNum4(int x) {
	if (x > 9999)
		return false;
	while (x) {
		if (!check(x % 10))
			return false;
		x /= 10;
	}
	return true;
}
bool legal(int k) {
	if (k == 1 || k == 2 || k == 3)
		return true;
	if (k == 4) {
		int num = b[1] + b[2] * 10 + b[3] * 100;
		num *= b[4];
		if (checkNum3(num))
			return true;
	}
	if (k == 5) {
		int num = b[1] + b[2] * 10 + b[3] * 100;
		if (checkNum3(num*b[5]))
			if (checkNum4(num*(b[4] + b[5] * 10)))
				return true;
	}
	return false;
}
void dfs(int k) {
	if (k > 5) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		b[k] = a[i];
		if (legal(k))
			dfs(k + 1);
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		cnt = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		dfs(1);
		cout << cnt << endl;
	}
	return 0;
}

//枚举！！
/* #include<iostream>
#include<algorithm>
using namespace std;

int n, cnt, num[5]; 
int a[10];

bool check(int x) {
	for(int i=0; i<n; i++){
		if(x == a[i])
			return true;
	}
	return false;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>n;
		cnt = 0;
		for(int i=0; i<n; i++)
			cin>>a[i];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				for(int k=0; k<n; k++)
					for(int p=0; p<n; p++)
						for(int q=0; q<n; q++) {
							num[0] = a[i]*100 + a[j]*10 + a[k];
							num[1] = a[p]*10 + a[q];
							num[2] = num[0] * a[q];
							num[3] = num[0] * a[p];
							num[4] = num[0] * num[1];
							if(check(num[2]/100)) {
								num[2] %= 100;
								if(check(num[2]/10) && check(num[2]%10))
									if(check(num[3]/100)) {
										num[3] %= 100;
										if(check(num[3]/10) && check(num[3]%10))
											if(check(num[4]/1000) && check(num[4]%10)) {
												num[4] = num[4]%1000/10;
												if(check(num[4]/10) && check(num[4]%10))
													cnt++;
											}
									}
									
							}
							
						}
		cout<<cnt<<endl;
	} 
	
	return 0;
}  */
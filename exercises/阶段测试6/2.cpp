#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct score{
	int a;
	int b;
	int c;
	int d;
	int sum;
	score(int a1,int a2,int a3,int a4) {
		a = a1;
		b = a2;
		c = a3;
		d = a4;
		sum = a+b+c;
	}
};

int cmp(score a, score b) {
	if(a.sum==b.sum){
		if(a.a==b.a)
			return a.d<b.d;
		return a.a>b.a;
	}
	return a.sum>b.sum;	
}

vector<score> s;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int a, b, c;
		s.clear();
		for(int i=1; i<=n; i++) {
			cin>>a>>b>>c;
			score temp(a,b,c,i);
			s.push_back(temp);
		}
		sort(s.begin(),s.end(),cmp);
		for(int i=0; i<5; i++)
			cout<<s[i].d<<" "<<s[i].sum<<endl;
	}
    return 0;
}

/* Problem Description
某校计算机专业在第三学期的奖学金评定方法是：根据本学期的ACM，高数和大学英语这三门课的成绩评定奖学金，即将全班按照这三门课的成绩进行排名，前五位的同学可获得奖学金。排名方法是：先根据总分从高到低排序，如果总分相等，则按照ACM的成绩从高到低排序，如果总分相等，ACM成绩也相等，则学号较小的学生排在前面。
提示：对于学号较小的学生排在前面容易出错，解决方法是将学号参与排序，或者使用STL中的另一个排序函数stable_sort()，该函数的使用方法与sort类似。
Input
第一行为一个整数t，表示测试样例的数量。
对每一个测试样例：
第一行为一个整数n，表示参加评选学生的人数。
接下来n行，按照学号(学号为1, 2, ……, n)从小到大的顺序给出每个学生的三门课的成绩，即每行有3个用空格分隔的整数(0~100)，依次表示该学生的ACM、高数和大学英语的成绩。
Output
每个测试用例都输出5行，每行为两个用空格分隔的正整数，依次表示前5名学生的学号和总分。
Sample Input
2
6
90 67 80
87 66 91
78 89 91
88 99 77
67 89 64
78 89 98
8
80 89 89
88 98 78
90 67 80
87 66 91
78 89 91
88 99 77
67 89 64
78 89 98
Sample Output
6 265
4 264
3 258
2 244
1 237
8 265
2 264
6 264
1 258
5 258 */
/* 容器
Problem Description
现有三个容量分别为a, b, c的容器，其中a, b, c为区间[1, 20]内的整数，最初容器a和b都是空的，容器c装满水。可以进行下列操作：将容器i倒入容器j中，直到i为空或j满为止，假设在操作过程中水不会丢失。编程确定当容器a为空时，容器c中所剩水量的所有可能性。
Input
第一行为一个整数t，表示测试样例的个数。
每一个测试用例输入一行，为三个整数a, b, c，分别表示三个容器的容量。
Output
每个测试用例输出一行，为由个空格分隔的若干个整数，表示容器c中所剩水量的可能值。注意，行首和行尾不要有多余的空格。
Sample Input

2
8 9 10
3 20 20

Sample Output

1 2 8 9 10
0 2 3 5 6 8 9 11 12 14 15 17 18 20 */

#include <iostream>
#include <cstring>
using namespace std;

int a, b, c;
int map[21][21] = {0};

void dfs(int i, int k) {
    if(map[i][k])
		return;
    map[i][k] = 1;
    dfs(0, k);
    dfs(i, 0);
    if(i>=b-k) //a->b
		dfs(i-b+k, b);
    else
		dfs(0, i+k);
	
    if(k>=a-i) //b->a
		dfs(a, k-a+i);
    else
		dfs(i+k, 0);
		
    int j = c-i-k;//c现有水
    
    if(j>=a-i) //c->a
		dfs(a, k);
    else
		dfs(i+j, k);
	
    if(j>=b-k) //c->b
		dfs(i, b);
    else 
		dfs(i, k+j);
}


int main() {
	int t;
	bool flag;
	cin>>t;
	while(t--) {
		cin>>a>>b>>c;
		flag = false;
		memset(map,0,sizeof(map));
		dfs(0, 0);
	    for(int i=20; i>=0; i--)
	        if (map[0][i]) { // a空则输出
	            if(flag)
					cout<<' ';
	            else 
					flag = true;
	            cout << c-i;
	        }
		cout<<endl; 
	}
   
}
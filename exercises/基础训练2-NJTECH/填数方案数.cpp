/*填数方案数
Problem Description
如下的10个格子
（图形见文件）
填入0~9的数字。要求：连续的两个数字不能相邻。
（左右、上下、对角都算相邻）
一共有多少种可能的填数方案？
请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。*/
#include<iostream>
#include<cstring>
using namespace std; 
int mark[10];
int map[4][5];  
int sum = 0;  
bool check() {  
    int i,j;  
    for(i=0; i<3; i++) {  
        for(j=0;j<4;j++)  
            if(abs(map[i][j]-map[i][j+1])==1||abs(map[i][j]-map[i+1][j])==1||abs(map[i][j]-map[i+1][j-1])==1||abs(map[i][j]-map[i+1][j+1])==1)  
              return false;
    }  
    return true;
}
void dfs(int t) {
    int i;
    if(t==11) {
       if(check())
        sum++;
       return;  
    }
    for(i=0; i<=9; i++) {
        if(mark[i]==0) {
            mark[i]=1;
            map[t/4][t%4]=i;
            dfs(t+1);
            mark[i]=0;
        }
    }
}
int main() {
    int i;
	memset(mark,0,sizeof(mark));
    for(i=0; i<4; i++)
        map[i][4]=1000;
    for(i=0; i<5; i++)
        map[3][i]=1000;
    map[0][0] = map[2][3] = 1000;
    dfs(1);
    cout<<sum;
    return 0;
}
//1580

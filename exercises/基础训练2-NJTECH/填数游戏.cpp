/*填数游戏
Problem Description
所示六角形中，填入1~12的数字。 使得每条直线上的数字之和都相同。
图中已经替你填好了3个数字，请你计算星号位置所代表的数字是多少？*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
 
int mark[13]; 
int a[10];
int num[6];
bool check(int k) {  
    if(k==9) {
    	num[0] = 1+a[1]+a[4]+a[6];
    	num[1] = 1+a[2]+a[5]+a[9];
    	num[2] = 8+a[1]+a[2]+a[3];
    	num[3] = 8+a[4]+a[7]+3;
    	num[4] = 3+a[3]+a[5]+a[8];
    	num[5] = a[6]+a[7]+a[8]+a[9];
    	for(int i=0; i<5; i++)
    		for(int j=i+1; j<6; j++) {
    			if(num[i]!=num[j])
    				return false;
			}
	}
    return true;  
}  
  
  
void dfs(int k) {  
    if(k>9) {
      	cout<<a[4]<<endl;
    }
    for(int i=1; i<=12; i++)
        if(mark[i]==0) {
			mark[i] = 1;  
            a[k] = i;  
            if(check(k))  
                dfs(k + 1);  
            mark[i] = 0;
        }  
}  
  
  
int main() {
	memset(mark,0,sizeof(mark));
	mark[1] = 1;
	mark[3] = 1;
	mark[8] = 1;
    dfs(1);  
    return 0;  
}
//10

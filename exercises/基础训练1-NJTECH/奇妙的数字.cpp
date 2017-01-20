/*奇妙的数字

Problem Description
小明发现了一个奇妙的数字。它的平方和立方正好把0~9的10个数字每个用且只用了一次。
你能猜出这个数字是多少吗？
请填写该数字，不要填写任何多余的内容。*/
#include<iostream>
#include<cstring>
using namespace std;

bool solve(int a,int b)    
{    
    int test[10];    
    memset(test,0,sizeof(test));    
    while(a)    
    {    
        test[a%10]++;    
        a/=10;    
    }    
    while(b)    
    {    
        test[b%10]++;    
        b/=10;    
    }    
    for(int i=0;i<10;i++)   
        if(test[i] != 1)    
 			return false;    
    return true;
}    
int main() {
	for(int i=11; i<99; i++) {
		if(solve(i*i,i*i*i)) {
			cout<<i;
			break;
		}
	}
} 
//69

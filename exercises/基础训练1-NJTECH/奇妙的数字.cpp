/*���������

Problem Description
С��������һ����������֡�����ƽ�����������ð�0~9��10������ÿ������ֻ����һ�Ρ�
���ܲ³���������Ƕ�����
����д�����֣���Ҫ��д�κζ�������ݡ�*/
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

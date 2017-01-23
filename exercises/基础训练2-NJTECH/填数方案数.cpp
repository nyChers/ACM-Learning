/*����������
Problem Description
���µ�10������
��ͼ�μ��ļ���
����0~9�����֡�Ҫ���������������ֲ������ڡ�
�����ҡ����¡��ԽǶ������ڣ�
һ���ж����ֿ��ܵ�����������
����д��ʾ������Ŀ��������
ע�⣺���ύ��Ӧ����һ����������Ҫ��д�κζ�������ݻ�˵�������֡�*/
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

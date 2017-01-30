/*��ͬ�ļ�ȡ����
Problem Description
�硾ͼ1.jpg��, ��12������һ���12��Ф����Ʊ��
������Ҫ���м���5������Ҫ����������ŵġ�
����������һ���ǲ���������
���磬��ͼ2.jpg������ͼ3.jpg���У��ۺ�ɫ��ʾ���־��Ǻϸ�ļ�ȡ��
ͼ���ļ��� 
������㣬һ���ж����ֲ�ͬ�ļ�ȡ������
����д��ʾ������Ŀ��������
ע�⣺���ύ��Ӧ����һ����������Ҫ��д�κζ�������ݻ�˵�������֡�*/
#include<iostream>
#include<cstring>
using namespace std;
int tok = 0;
int cnt = 0;
int cn = 0;
int a[12];
int b[3][4];
int mark[3][4];
void dfs_find(int x,int y) {
	mark[x][y] = 1;
	if(b[x][y]==1) {
	
		cn++;	
		if(x-1>=0 && mark[x-1][y]==0) {
			dfs_find(x-1,y);
		}
		if(x+1<3 && mark[x+1][y]==0) {
			dfs_find(x+1,y);	
		}
		if(y-1>=0 && mark[x][y-1]==0) {
			dfs_find(x,y-1);
		}
		if(y+1<4 && mark[x][y+1]==0) {
			dfs_find(x,y+1);	
		}
	}
	return;
}
void check() {
	cn = 0;
	memset(mark,0,sizeof(mark));
	for(int i=0; i<12; i++) {
		b[i/4][i%4] = a[i];
	}
	for(int i=0; i<12; i++)
		if(b[i/4][i%4]==1) {
			dfs_find(i/4,i%4);
			break;
		}
	if(cn==5)
		cnt++;	
}
void dfs(int x) {
	if(x>11) {
		tok = 0;
		for(int i=0; i<12; i++) {
			if(a[i]==1)
				tok++;
		}
		if(tok!=5)
			return;
		check();
		return;
	}
	for(int i=0; i<=1; i++) {
		a[x] = i;
		dfs(x+1);
	}
}
int main() {
	memset(a,0,sizeof(a));
	memset(mark,0,sizeof(mark));
	dfs(0);
	cout<<cnt;
	return 0;
}
//116


//#include <stdio.h>  
//#include <string.h>  
//int mpt[3][4];  
//int mpt_visit[3][4];  
//int num[6];   
//int have[13];  
//int visit[13];  
//int ans = 0;  
//int Count = 0;  
//
//void init() {  
//    int k = 1;  
//    for(int i = 0 ; i < 3 ; i ++)  
//        for(int j = 0 ; j < 4 ; j ++) {  
//            mpt[i][j] = k;  
//            k ++;  
//        }  
//}  
//int dir[4][2] = {0,1,0,-1,-1,0,1,0};  
////�ж�������Ƿ�������һ��  
//void dfs_find(int x,int y) {  
//    for(int i = 0 ; i < 4 ; i++) {  
//        int tx,ty;  
//        tx = x + dir[i][0];  
//        ty = y + dir[i][1];  
//        if(tx < 0 || tx >= 3 || ty < 0 || ty >= 4) 
//			continue;  
//        if(have[mpt[tx][ty]] == 0 || mpt_visit[tx][ty])
//			continue;  
//        mpt_visit[tx][ty] = 1;  
//        Count ++;  
//        dfs_find(tx,ty);  
//    }  
//}  
//
//void Solve() {  
//    int i;  
//    memset(have,0,sizeof(have));  
//    memset(mpt_visit,0,sizeof(mpt_visit));  
//    for(i = 1; i < 6 ; i ++) have[num[i]] = 1;  
//    for(i = 0 ; i < 12 ; i ++) {  
//        int x,y;  
//        x = i / 4;  
//        y = i % 4;  
//        if(have[mpt[x][y]]) {  
//            Count = 1;  
//            mpt_visit[x][y] =1;  
//            dfs_find(x,y);  
//            break;  
//        }  
//    }  
//    if(Count == 5)  
//        ans ++;  
//}  
//
////����5���������  
//void dfs_creat(int index) {  
//    if(index == 6) {  
//        Solve();  
//        return;  
//    }  
//    for(int i = num[index-1] + 1; i < 13 ; i ++) {  
//        if(!visit[i]) {  
//            visit[i] = true;  
//            num[index] = i;  
//            dfs_creat(index+1);  
//            visit[i] = false;  
//        }  
//    }  
//}  
//
//int main() {  
//    init();  
//    dfs_creat(1);  
//    printf("%d\n",ans);  
//    return 0;  
//} 

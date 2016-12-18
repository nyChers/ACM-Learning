/* 城堡
Problem Description
一个城堡被分为m*n(0<m, n<51)个小正方形(m为城堡的宽度)，每个小正方形可能有0~4面墙，但城堡的边缘都是墙，例如下图表示大小为7*4的城堡（墙用#表示，无墙用-或|表示）。
#############################
# | # | # | | #
#####------#####-------#-------#####-------#
# # | # # # # #
#-------#####------#####-------#####-------#
# | | # # # # #
#------#########-------#####-------#-------#
# -># | | | | # #
#############################
如果两个方房间中间没有墙，则认为它们为同一个房间，一个房间的大小表示该房间是由几个房间相连，上图中共有5个房间，大小分别为1, 3, 7, 8, 9。现将某一面墙拆除，使得合并后的房间最大（例如上图中移除->所指向的墙就能得到最大房间）。
Input
第一行为一个整数t，表示测试用例的个数。
对每一个测试用例：
第一行两个整数m和n，分别表示城堡的宽和高。
以下n行，每行有m个整数（0~15），分别表示每个小正方形周围墙的情况。规定：0表示周围没有墙，1表示左面有墙，2表示上面有墙，4表示右面有墙，8表示下面有墙，其他数字可以根据由1,2,4,8和的情况确定墙的情况，比如：如果一个小正方形的值为13，因为13=1+4+8，则表示该小正方形的左面(1)、右面(4)和下面(8)有墙。
Output
每一个测试用例输出4行：
第一行为一个整数，表示城堡的房间数量
第二行为一个整数，表示最大的房间的大小
第三行为一个整数，表示移除一面墙后能够得到的最大房间的大小
第四行为两个整数x和y以及一个字母(E或N)，表示移除哪面墙。X和y表示房间的编号，字母表示拆除该房间的哪面墙（E：表示右面，N：表示上面），即只考虑拆除一个房间的右边或上边的墙。如果有多个拆除方案，则先考虑最左的房间，然后考虑最下的房间。
Sample Input

2
7 4
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13
5 5
3 2 6 3 6
1 8 4 1 4
13 7 13 9 4
3 0 2 6 5
9 8 8 12 13

Sample Output

5
9
16
4 1 E
3
9
17
4 1 N */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int m, n;
int sum, max1, max2;
int area[52*52] = {0};
int a[55][55],flag[55][55];
// void dfs(int i,int j) {  
 	// if(i<0||j>=n||j<0||i>=m) 
	 	// return;
    // if(flag[i][j])  
        // return;  
    // area[sum]++;  
    // flag[i][j]=sum;  
    // if((a[i][j]&1)==0)
		// dfs(i,j-1);  
    // if((a[i][j]&2)==0)
		// dfs(i-1,j);
    // if((a[i][j]&4)==0)
		// dfs(i,j+1);
    // if((a[i][j]&8)==0)
		// dfs(i+1,j);
// }  
void dfs(int i,int j) {  
 	if(i<0||j>=n||j<0||i>=m) 
	 	return;
    if(flag[i][j])  
        return;  
    area[sum]++;  
    flag[i][j]=sum;  
    int p=a[i][j];
    if(p==0) {
		dfs(i,j-1);
		dfs(i,j+1);
		dfs(i+1,j);
		dfs(i-1,j);
        return;
    }
    if(p>=8) 
		p-=8;
    else 
		dfs(i+1,j);
    if(p>=4) 
		p-=4;
    else
		dfs(i,j+1);
    if(p>=2) 
		p-=2;
    else
		dfs(i-1,j);
    if(p>=1) 
		p-=1;
    else  
		dfs(i,j-1);
}  
int main() {
	int t;
	cin>>t;
	while(t--) {
		sum = 0;//·¿¼äºÅ 
		max1 = 0;//×î´ó·¿¼ä´óÐ¡ 
		max2 = 0;//Á½¸öºÏ²¢ 
		int X, Y;
		char temp;
		memset(flag,0,sizeof(flag));
		memset(area,0,sizeof(area));
	    cin>>n>>m;
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				cin>>a[i][j];
		int x = 0;
	    for(int i=0; i<m; i++)
	        for(int j=0; j<n; j++) {
	        	if(!flag[i][j]) {  
                    sum++;  
                    dfs(i,j);  
                    if(area[sum]>max1)
						max1 = area[sum];  
                }
		}
		for(int j=0; j<n; j++)
	   		for(int i=m-1; i>=0; i--) {
				if(i-1>=0 && flag[i][j]!=flag[i-1][j] && area[flag[i][j]]+area[flag[i-1][j]]>max2) {
	        		max2 = area[flag[i][j]]+area[flag[i-1][j]];	
	        		X = i+1;
	        		Y = j+1;
	        		temp = 'N';
				}
				if(j+1<n && flag[i][j]!=flag[i][j+1] && area[flag[i][j]]+area[flag[i][j+1]]>max2) {
	        		max2 = area[flag[i][j]]+area[flag[i][j+1]];	
	        		X = i+1;
	        		Y = j+1;
	        		temp = 'E';
				}
			}
	    cout<<sum<<endl<<max1<<endl;
	    cout<<max2<<endl; 
	    cout<<X<<' '<<Y<<' '<<temp<<endl; 
	}	
  
    return 0;
}
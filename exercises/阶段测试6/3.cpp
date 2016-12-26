#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

bool sq[250*250*2+2];

int main() {
	int t;
	cin>>t;
	int n,m;

	while(t--) {

		int count=0;
		cin>>n>>m;
		memset(sq,0,sizeof(bool)*(m*m*2+2));
		for(int i=0; i<=m; ++i)
			for(int j=i; j<=m; ++j)
				sq[i*i+j*j]=1;

		int b_bound=m*m*2/(n-1);


		for(int b=1; b<=b_bound; ++b) {

			if(count>10000)
				break;
			int a_bound=m*m*2-(n-1)*b;
			for(int a=0; a<=a_bound; ++a) {
				int i=0,b_times_i=-b;
				for(i=0; i<n; ++i) {
					b_times_i+=b;
					if( sq[a+b_times_i]!=1 )
						break;
				}
				if(i==n ) {
					printf("%d%c%d\n",a,' ',b);
					count++;
				}
			}
		}

		if(count==0)
			cout<<"NONE"<<endl;
	}
	return 0;
}
/* Problem Description
设a为非负整数，b为正整数，则以首项为a，公差为b，长度为n的等差数列的各项为a, a+b, a+2b, ……, a+(n-1)*b。编写程序，求所有a，b，使得首项为a公差为b长度为n的等差数列的每一项都可以表示为给定范围内两个非负整数p和q的平方和（即a+i*b = p^2+q^2）。
提示：可先将能够表示为p^2+q^2的数存入一个数组中sq，比如假设i可以表示为p^2+q^2，则sq[i]=1，否则sq[i]=0。
注意：C++的时间限制为5秒。
Input
第一行为一个整数t，表示测试用例的数量。
每一个测试用例输入一行，共两个整数：
第一个整数n（3<=n<=25），表示等差数列的长度。
第二个整数m（1<=m<=250），表示p, q的上界，即0<=p, q<=m。
Output
如果存在这样的a和b，则输出一行或多行，每行包括两个用空格分隔的整数a和b，输出顺序为：先按b从小到大排序，如果b相同，则按a从小到大排序。每个测试用例的结果不会多于10000个。
如果不存在满足条件的a和b，则输出”NONE”
Sample Input
2
5 7
3 2
Sample Output
1 4
37 4
2 8
29 8
1 12
5 12
13 12
17 12
5 20
2 24
0 1
0 2
2 3
0 4 */
/* #include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int bisquars[251*251*2+5]={0};
struct node{
	int a;
	int b;
}result[10005];

void ini(int m){
	int i, j;
	for(i=0; i<=m; i++)
		for(j=0; j<=m; j++)
			bisquars[i*i + j*j] = 1;
}

int cmp(node n1, node n2){
	if(n1.b != n2.b)
		return n1.b<n2.b;
	return n1.a < n2.a;
}

int main(){	
    int n, m, a, b, n_i, ap, count=0;	 
    int t;
    cin>>t;    
    while(t--){		
		cin>>n>>m;
		if(n>=23){
	    	cout<< "NONE"<<endl;
			continue;
		}
		memset(bisquars, 0, sizeof(bisquars));
	    ini(m);			//每一个m求bisquars，
	    count = 0;
		for(a=0; a<=2*m*m-n; a++){
			if(!bisquars[a])
				continue;
	    	for(b=1; b<=(2*m*m-a)/(n-1); b++){    	
	    		for(n_i=1; n_i<n; n_i++){
	    			ap = a + b*n_i;
	    			if(!bisquars[ap])
	    				break;
	    		}
	    		if(n_i==n){
	    			result[count].a = a;
	    			result[count].b = b;
	    			count++;
	    		}    			
	    	}
	    }
	    sort(result, result+count, cmp);	    
	    if(count==0)
	    	cout<< "NONE"<<endl;	    	
	    else{
	    	for(int i=0; i<count; i++)
	    		cout<<result[i].a<<' '<<result[i].b<<endl;				
	    }	    
	}    
	return 0;
} */


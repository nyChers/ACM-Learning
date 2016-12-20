#include <iostream> 
#include <algorithm>
using namespace std;

int tri[1005][1005], dp[1005][1005];
int sum;

int main() {
	int t;
	cin>>t;
	while(t--) {
		int r;
		cin>>r;
		for(int i=1; i<=r; i++)
			for(int j=1; j<=i; j++)
				cin>>tri[i][j];
		for(int j=1; j<=r; j++)
			dp[r][j] = tri[r][j];
		for(int i=r-1; i>=1; i--) 
			for(int j=1; j<=i; j++)
				dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + tri[i][j];
		cout<<dp[1][1]<<endl;
	}
}
/* Problem Description
考虑下面的数字金字塔：
----------------7 
-------------3----8
----------8----1----0
-------2----7----4----4
----4----5----2----6----5
现从金字塔的顶端向下走，走的方法是每一步只能到达其下方的两个位置，例如，第三层的8只能走到其下方的2和7。则从金字塔的顶端到达底端有多条路径可走，编写程序，求从最高点开始到达底部的路径中所经过的数字之和的最大值。例如上图中的路径7->3->8->7->5中的数字和30为最大
Input
第一行为一个整数t，表示测试样例的数量。
每一个测试用例的第一行为一个整数r（1<=r<=1000），表示数字金字塔的高度。
接下来共有r行，其中第i行共有i个整数，表示数字金字塔在该行的数字分布。所有整数不大于100。
Output
每一个测试用例输出一个整数，表示得到的最大和。
Sample Input
1
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
Sample Output
30 */
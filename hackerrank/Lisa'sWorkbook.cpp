#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    cin>>n>>k;
    int chap=1;
    int page=1;
    int t;
    int cnt=0;
    int FirstP=1;
/*   vector<int> t[n];
    for(int i=0; i<n; i++)
    	cin>>t[i];
*/
	cin>>t;
	while(chap<=n){
		if(FirstP<=page && ((FirstP-1+k)>t?t:(FirstP-1+k))>=page)
			cnt++;
		page++;
		FirstP+=k;//·­Ò³ 
		if(FirstP>t){//ÏÂÒ»ÕÂ 
			FirstP=1;
			chap++;
			cin>>t;
		}
	}
	cout<<cnt<<endl;
    return 0;
}


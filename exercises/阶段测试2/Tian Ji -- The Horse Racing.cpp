#include<iostream>
#include<algorithm>
using namespace std;

int cmp(int a, int b){
	return a>b;
}
int main(){
    int a[1002];
    int b[1002];
    int m;
    while(cin>>m,m!=0){
        for(int i=0; i<m; i++)
			cin>>a[i];
        for(int i=0; i<m; i++)
            cin>>b[i];
        sort(a,a+m,cmp);
        sort(b,b+m,cmp);
        
        int tf=0,tl=m-1;
		int wf=0,wl=m-1;
        int sum = 0;
        while(m--){
	        if(a[tf]>b[wf]){
	            sum += 200;
	            wf++;
	            tf++;
	        }
	        else if(a[tl]>b[wl]){
	            sum += 200;
	            tl--;
	            wl--;
	        }
	        else if(a[tl]<b[wf]){
	            sum -= 200;
	            tl--;
	            wf++;
	        }
        }
       	cout<<sum<<endl;
    }
}
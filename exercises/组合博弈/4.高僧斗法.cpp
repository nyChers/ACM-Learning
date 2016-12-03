#include <iostream>
using namespace std;

int main() {  
    int a[101];//和尚位置 
	int b[101];//和尚两两间距 
	int i=0; 
    char c;  
    while(true) {  
        cin>>a[i++];
		c = getchar();  
        if(c=='\n')  
            break;  
    }  
	 
    int n = i;//和尚个数 
    
//	n-1个间距如n-1堆石子，每次取一段的任意个  加到 下一段上  
    for(i=0; i<n-1; i++)  
        b[i]=a[i+1]-a[i]-1;  
    b[n-1]=0;  
    
    int sum=b[0];  
//  你移动几格我就可以跟着你后面的和尚移动几格，这样保证最优。所以只需要判断第2*k+1到2*k+2之间的距离进行nim博弈即可。
    for(i=2; i<n; i+=2)  
        sum ^= b[i];  
    if(sum == 0)   
        cout<<-1<<endl;  
    else {  
        for(i=0; i<n; i++)  
            for(int j=1; j<=b[i]; j++) {  //移动一次 
                b[i] -= j;  
                if(i!=0)  
                    b[i-1] += j;  
                    
                sum = b[0];  
                for(int k=2; k<n; k+=2)  
                    sum ^= b[k];  
                if(sum == 0) {  
                    cout<<a[i]<<" "<<a[i]+j<<endl;  
                    break;  
                }
                
                b[i] += j;  //复原移动 
                if(i != 0)  
                    b[i-1] -= j;  
            }
    }
    return 0;  
}  
  
/* 
1 3 5 7 12 14 17 26 38 45 66 100 
66 84 
*/  



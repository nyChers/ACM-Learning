#include <iostream>
using namespace std;

int main() {  
    int a[101];//����λ�� 
	int b[101];//����������� 
	int i=0; 
    char c;  
    while(true) {  
        cin>>a[i++];
		c = getchar();  
        if(c=='\n')  
            break;  
    }  
	 
    int n = i;//���и��� 
    
//	n-1�������n-1��ʯ�ӣ�ÿ��ȡһ�ε������  �ӵ� ��һ����  
    for(i=0; i<n-1; i++)  
        b[i]=a[i+1]-a[i]-1;  
    b[n-1]=0;  
    
    int sum=b[0];  
//  ���ƶ������ҾͿ��Ը��������ĺ����ƶ�����������֤���š�����ֻ��Ҫ�жϵ�2*k+1��2*k+2֮��ľ������nim���ļ��ɡ�
    for(i=2; i<n; i+=2)  
        sum ^= b[i];  
    if(sum == 0)   
        cout<<-1<<endl;  
    else {  
        for(i=0; i<n; i++)  
            for(int j=1; j<=b[i]; j++) {  //�ƶ�һ�� 
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
                
                b[i] += j;  //��ԭ�ƶ� 
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



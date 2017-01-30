/*��ͷ���
Problem Description
���� 100 �����ӣ���Ȼ���� 200 ����ͷ��
�������ȡ��ͷ������ԣ���������ͷ��������������������γ����ɸ���Ȧ���������Ƿ�����һ�𣩡�
���ǵ������ǣ����������γɶ��ٸ���Ȧ�ĸ������
ע�⣺�����һ����������Ҫ��д��������ݡ�*///3
#include<iostream>  
#define N 100  
using namespace std;   
double dp[N+1][N+1] = {0};
  
int main(){  
    dp[1][1] = 1;  
    for(int i=2;i<=N;i++){  
        dp[i][1] = dp[i-1][1] * (2*i-2)/(2*i-1);  
        dp[i][i] = dp[i-1][i-1] / (2*i-1);  
    }  
      
    for(int i=3;i<=N;i++){  
        for(int j=2;j<i;j++){  
            dp[i][j] = dp[i-1][j-1]/(2*i-1) + dp[i-1][j] * (2*i-2) / (2*i-1);  
        }  
    }  
      
    int index = 0;  
    double maxR = 0;  
    for(int i=1;i<=N;i++){  
        if(dp[N][i]>maxR){  
            index = i;  
            maxR = dp[N][i];  
        }     
    }  
    cout<<index<<endl;  
    return 0;  
}
//��f[i][j]��ʾi�������j��Ȧ�ĸ��ʣ�c[i]��ʾi������2i���˵���Ե���������c[1]=1��c[i]=c[i-1]*(2*i-1)
//f[i][i]=1/c[i]��
//f[i][1]=f[i-1][1]*c[i-1]*(i-1)*2/c[i]��
//f[i][j]=(f[i-1][j]*c[i-1]*(i-1)*2+f[i-1][j-1]*c[i-1])/c[i]

/*绳头配对
Problem Description
今有 100 根绳子，当然会有 200 个绳头。
如果任意取绳头两两配对，把所有绳头都打结连接起来。最后会形成若干个绳圈（不考虑是否套在一起）。
我们的问题是：请计算最后将形成多少个绳圈的概率最大？
注意：结果是一个整数。不要填写多余的内容。*///3
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
//设f[i][j]表示i条绳结成j个圈的概率，c[i]表示i条绳的2i个端点配对的种数，有c[1]=1，c[i]=c[i-1]*(2*i-1)
//f[i][i]=1/c[i]，
//f[i][1]=f[i-1][1]*c[i-1]*(i-1)*2/c[i]，
//f[i][j]=(f[i-1][j]*c[i-1]*(i-1)*2+f[i-1][j-1]*c[i-1])/c[i]

#include<iostream>
#include<cstring>
using namespace std;
#define max 1001
int a[max+10];
int b[max+10];
char x[max+10];
char y[max+10];
int main()
{
    int i,j,k;
    int n;
    cin>>n;
    for(int p=1; p<=n; p++){
            cin >> x >> y;
        cout<<"Case "<<p<<":\n";
        cout<<x<<" + "<<y<<" = ";
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int xlen=strlen(x),ylen=strlen(y);
        j=0;
        for(i=xlen-1;i>=0;i--)
            a[j++]=x[i]-'0';
        k=0;
        for(i=ylen-1;i>=0;i--)
            b[k++]=y[i]-'0';
        for(i=0;i<max;i++)//进位
        {
            a[i]+=b[i];
            if(a[i]>9){
                a[i]-=10;
                a[i+1]++;
            }
        }
        bool flag=false;//此变量用于跳过多余的0 
        for(i=max;i>=0;i--)
        {
            if(flag)
                cout<<a[i];
            else if(a[i])//碰到第一个非0的值，就说明多余的0已经都跳
            {
                cout<<a[i];
                flag=true;
            }
        }
        if(!flag) //结果为0特殊处理 
       	 	cout<<"0";
        cout<<endl;    
        if(p<n)
			cout<<endl;
    }
    
}


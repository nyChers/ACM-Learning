/*高精度黄金分割数
Problem Description
黄金分割数0.61803... 是个无理数，这个常数十分重要，在许多工程问题中会出现。有时需要把这个数字求得很精确。
对于某些精密工程，常数的精度很重要。也许你听说过哈勃太空望远镜，它首次升空后就发现了一处人工加工错误，对那样一个庞然大物，其实只是镜面加工时有比头发丝还细许多倍的一处错误而已，却使它成了“近视眼”!!
言归正传，我们如何求得黄金分割数的尽可能精确的值呢？有许多方法。
比较简单的一种是用连分数：f(n)=1/(1+f(n-1)) abs(f(n)-f(n-1))<10e-100
（连分数的图见QQ群） 
这个连分数计算的“层数”越多，它的值越接近黄金分割数。
请你利用这一特性，求出黄金分割数的足够精确值，要求四舍五入到小数点后100位。
小数点后3位的值为：0.618
小数点后4位的值为：0.6180
小数点后5位的值为：0.61803
小数点后7位的值为：0.6180340
（注意尾部的0，不能忽略）
你的任务是：写出精确到小数点后100位精度的黄金分割值。
注意：尾数的四舍五入！ 尾数是0也要保留！
显然答案是一个小数，其小数点后有100位数字。
注意：不要提交解答过程，或其它辅助说明类的内容。*/
//黄金分割数与斐波拉契数列有关，就是连续两个数的商

#include<iostream>//WIKI给出的代码 
#include <stdio.h>
using namespace std;
int main (void)
{
    long b,c,d=0,e=0,f=100,i=0,j,N;
    cout<<"请输入黄金分割数位数\n";
    cin>>N,N=N*3/2+6;
    long *a=new long[N+1];
    while(i<=N)a[i++]=1;
    for(; --i>0; i==N-6?printf("\r0.61"):printf("%02ld",e+=(d+=b/f)/f),e=d%f,d=b%f,i-=2)
        for(j=i,b=0; j; b=b/c*(j--*2-1))a[j]=(b+=a[j]*f)%(c=j*10);
    delete []a;
    return 0;
}
//0.6180339887498948482045868343656381177203091798057628621354486227052604628189024497072072041893911375


/*#include <iostream>//这tm精度不够 
#define F 50
using namespace std; 
int main() {    
    unsigned long long int fib[1000], x, y;  
    int f = 0, i;  
    int a[105];  
    fib[0] = 0;  
    fib[1] = 1;  
      
    for(i = 2; i<=F; i++) {  
        fib[i] = fib[i-1] + fib[i-2];  
        f++;  
    }  
      
    x = fib[F-2];  
    y = fib[F-1];  
      
    for(i = 0; i < 101; i++) {  //模拟手除运算 
        a[i] = x / y;  
        x = (x % y) * 10;
        cout<<a[i];  
    }   
    return 0;  
}  */

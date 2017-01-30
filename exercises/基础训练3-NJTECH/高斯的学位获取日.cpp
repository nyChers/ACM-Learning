/*高斯学位获取日
Problem Description
大数学家高斯有个好习惯：无论如何都要记日记。
他的日记有个与众不同的地方，他从不注明年月日，而是用一个整数代替，比如：4210
后来人们知道，那个整数就是日期，它表示那一天是高斯出生后的第几天。这或许也是个好习惯，它时时刻刻提醒着主人：日子又过去一天，还有多少时光可以用于浪费呢？
高斯出生于：1777年4月30日。 
在高斯发现的一个重要定理的日记上标注着：5343，因此可算出那天是：1791年12月15日。
高斯获得博士学位的那天日记上标着：8113 
请你算出高斯获得博士学位的年月日。
提交答案的格式是：yyyy-mm-dd, 例如：1980-03-21
注意：只提交这个日期，不要写其它附加内容，比如：说明性的文字。*/
#include<iostream>  
#include<iomanip>  
using namespace std;  
int a[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};  
int b[2]={365,366};  
int check(int year) {  
    if(year%400==0||year%4==0&&year%100!=0)
		return 1;  
    else return 0;  
} 
int main() {  
    int year = 1777;  
    int month = 4;  
    int day = 30;  
    int total = 8113;  
    int num = 1;
	//将1777年的剩余天数减去    
    while(++month<=12)
		num += a[0][month-1];
    month=0;
	day=0;
	 
    while((num+=b[check(++year)])<=total);   
    num -= b[check(year)]; 
    while((num+=a[check(year)][++month])<=total);  
    num -= a[check(year)][month];  
    day = total - num;  
    cout<<year<<"-";  
    cout<<setw(2)<<setfill('0')<<month<<"-";  
    cout<<setw(2)<<setfill('0')<<day<<endl;   
}
//1799-07-16


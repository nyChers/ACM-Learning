/*炸弹爆炸日期
Problem Description
在X星系的广袤空间中漂浮着许多X星人造“炸弹”，用来作为宇宙中的路标。
每个炸弹都可以设定多少天之后爆炸。
比如：阿尔法炸弹2015年1月1日放置，定时为15天，则它在2015年1月16日爆炸。
有一个贝塔炸弹，2014年11月9日放置，定时为1000天，请你计算它爆炸的准确日期。
请填写该日期，格式为 yyyy-mm-dd 即4位年份2位月份2位日期。比如：2015-02-19
请严格按照格式书写。不能出现其它文字或符号。*/
#include <iostream>  
using namespace std;  
int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};  
bool check(int year) {  
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)  
        return true;  
    return false;  
}  
  
int main() {  
    int year = 2014;  
    int month,day;  
    int sum = 1000 - 52;
    int sum1;  
    while(true) {  
        if(check(year+1)) 
            sum1 = 366;  
        else  
            sum1 = 365;  
        year++;  
        if(sum < sum1)
            break;  
        else
            sum -= sum1;  
    }  
    if(check(year))  
        mon[2] = 29;  
    for(int i=1; i<=12; i++) {  
        if(sum > mon[i])  
            sum -= mon[i];  
        else {  
            month = i;  
            break;  
        }  
    }  
    day = sum;  
    cout<<year<<'-'<<month<<'-'<<day; 
    return 0;  
}
//2017-08-05

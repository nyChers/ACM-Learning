/*ը����ը����
Problem Description
��X��ϵ�Ĺ���ռ���Ư�������X�����조ը������������Ϊ�����е�·�ꡣ
ÿ��ը���������趨������֮��ը��
���磺������ը��2015��1��1�շ��ã���ʱΪ15�죬������2015��1��16�ձ�ը��
��һ������ը����2014��11��9�շ��ã���ʱΪ1000�죬�����������ը��׼ȷ���ڡ�
����д�����ڣ���ʽΪ yyyy-mm-dd ��4λ���2λ�·�2λ���ڡ����磺2015-02-19
���ϸ��ո�ʽ��д�����ܳ����������ֻ���š�*/
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

/*��˹ѧλ��ȡ��
Problem Description
����ѧ�Ҹ�˹�и���ϰ�ߣ�������ζ�Ҫ���ռǡ�
�����ռ��и����ڲ�ͬ�ĵط������Ӳ�ע�������գ�������һ���������棬���磺4210
��������֪�����Ǹ������������ڣ�����ʾ��һ���Ǹ�˹������ĵڼ��졣�����Ҳ�Ǹ���ϰ�ߣ���ʱʱ�̿����������ˣ������ֹ�ȥһ�죬���ж���ʱ����������˷��أ�
��˹�����ڣ�1777��4��30�ա� 
�ڸ�˹���ֵ�һ����Ҫ������ռ��ϱ�ע�ţ�5343����˿���������ǣ�1791��12��15�ա�
��˹��ò�ʿѧλ�������ռ��ϱ��ţ�8113 
���������˹��ò�ʿѧλ�������ա�
�ύ�𰸵ĸ�ʽ�ǣ�yyyy-mm-dd, ���磺1980-03-21
ע�⣺ֻ�ύ������ڣ���Ҫд�����������ݣ����磺˵���Ե����֡�*/
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
	//��1777���ʣ��������ȥ    
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


#include<iostream>
using namespace std;

int main()  
{  
    int y,m,d,days,F;  
	cin>>y>>m>>d;
	int months[13] = {0,31,0,31,30,31,30,31,31,30,31,30,31};
	if (y%400==0||(y%4==0&&y%100!=0))   
        months[2]=29;  
    else   
    	months[2]=28;
	for(int i=1; i<m;i++){
		days+=months[i];
	}
	days+=d;
    cout<<days<<endl;
    return 0;  
}  
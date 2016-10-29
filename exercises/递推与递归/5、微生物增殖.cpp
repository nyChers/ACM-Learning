#include<iostream>
using namespace std;

int f(int x,int y){
	for(int i=1; i<=120; i++){
		if(i%2==1)
			y-=x;
		if(y<=0)
			return 0;
		if(i%4==0)
			y*=2;
		if(i%6==0){
			x*=2;
		}	
	}
	return y;
}
int main(){
	int x1=10,y1=89;
	int x2=10,y2=90;
	cout<<f(x1,y1)<<endl;
	cout<<f(x2,y2)<<endl;
	return 0;
}
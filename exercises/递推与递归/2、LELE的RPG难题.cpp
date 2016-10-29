#include<iostream>
using namespace std;

//f(n)=f(n-1)+2f(n-2)
int colors(int n) 
{ 
	if(n==2) 
		return 6; 
	else if(n==3) 
		return 6; 
	else 
		return colors(n-1) + 2 * colors(n-2);
}  
int main(){
	int n;
	cin>>n;
	cout<<colors(n)<<endl;
}



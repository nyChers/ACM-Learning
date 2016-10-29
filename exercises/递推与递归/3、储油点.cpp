#include<iostream>

using namespace std;

void buildpoint(){
	double d=500,oil=500;
	int n=1;
	while(true){
		cout<<"距离A点 "<<1000 - d<<"km 储油"<<oil<<"L "<<endl;
		n++;
  		d = d + 500 / ( 2 * n - 1 );
  		if(d>=1000)
  			break;
  		oil = 500 * n;	
	}
	d -= 500 / ( 2 * n - 1 );
	oil = (1000-d) * (2 * n + 1) + oil;
	cout<<oil<<endl;
}
int main(){
	buildpoint();
	return 0;
}
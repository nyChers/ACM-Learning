#include<iostream>
using namespace std;

int i=0;
int fen(int n){
	if(n%5==4){
		i++;
		return fen(n-n/5);
	}else if(i==5)
		return n;
	else 
		return 0;		
}
int main() {
	int n=1000;
	while(true){
		i=0;
		int sum=fen(n);
		if(sum>1000)
			break;
		n++;
	}
	cout<<n<<endl;
	return 0;
}
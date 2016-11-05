#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
vector<int> bulb;
vector<int> a,b;
int n;
void change(int x){
	if(x==1)
		for(int i=0; i<n;i++)
			bulb[i] = bulb[i]==1 ? 0:1;
	if(x==2)
		for(int i=1; i<n; i+=2)
			bulb[i] = bulb[i]==1 ? 0:1;
	if(x==3)
		for(int i=0; i<n; i+=2)
			bulb[i] = bulb[i]==1 ? 0:1;	
	if(x==4)
		for(int i=0; i<n; i+=3)	
			bulb[i] = bulb[i]==1 ? 0:1;	
}
bool check(){
	for(int i=0; i<a.size(); i++){
		if(bulb[a[i]-1]==0)
			return false;
	}
	for(int i=0; i<b.size(); i++){
		if(bulb[b[i]-1]==1)
			return false;
	}
	return true;
}
void print(){
	for(int i=0; i<n; i++)
		cout<<bulb[i];
	cout<<endl;
}
int main(){  
	int c;
	cin>>n>>c;
	int temp;
	while(cin>>temp,temp!=-1){
		a.push_back(temp);
	}
	while(cin>>temp,temp!=-1){
		b.push_back(temp);
	}
	bulb.resize(n,1);
	while(c>4)
		c-=2;
	if(c==1 || c==3){
		if(check())
			print();
		for(int i=1; i<=4; i++){
			change(i);
			if(check())
				print();
			bulb.resize(n,1);
		}	
		if(c==3){
			for(int i=1; i<=2; i++)
				for(int j=i+1; j<=3; j++)
					for(int k=j+1; j<=4; k++){
						change(i);
						change(j);
						change(k);
						if(check())
							print();
						bulb.resize(n,1);
					} 
		}	
	}
	if(c==2 || c==4){
		if(check())
			print();
		for(int i=1; i<4; i++)
			for(int j=i+1; j<=4; j++){
					change(i);
					change(j);
					if(check())
						print();
					bulb.resize(n,1);					
			}
		if(c==4){
			for(int i=1; i<=4; i++)
				change(i);
			if(check())
				print();
			bulb.resize(n,1);
		}
	}

	return 0;
}  
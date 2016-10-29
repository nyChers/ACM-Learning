#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
	



int main() {
    int r,c,n;
	cin>>r>>c>>n;
	vector< vector<char> > grid(r,vector<char>(c));
	vector< vector<int> > bomb(r,vector<int>(c,0));
	

	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++){
			cin>>grid[i][j];
			if(grid[i][j]=='O')
				bomb[i][j]=1;
		}
	while(true){
		if(n==4)
			n=2;
		if(n-4>=2)
			n-=4;
		else
			break;
	}
	if(n==1)
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				cout<<grid[i][j];
			}
		cout<<endl;
	}
	if(n>=2){
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				grid[i][j]='O';
			}
		}
		if(n>=3){
			for(int i=0; i<r; i++){
				for(int j=0; j<c; j++){
					if(bomb[i][j]==1){
						grid[i][j]='.';
						if(i+1<r)
							grid[i+1][j]='.';
						if(i-1>=0)
							grid[i-1][j]='.';
						if(j+1<c)
							grid[i][j+1]='.';
						if(j-1>=0)
							grid[i][j-1]='.';
					}
				}
			}
			if(n==5){
				for(int i=0; i<r; i++)
					for(int j=0; j<c; j++){
						if(grid[i][j]=='O')
							bomb[i][j]=2;
					}
				for(int i=0; i<r; i++){
					for(int j=0; j<c; j++){
						grid[i][j]='O';
					}
				}
				for(int i=0; i<r; i++){
					for(int j=0; j<c; j++){
						if(bomb[i][j]==2){
							grid[i][j]='.';
							if(i+1<r)
								grid[i+1][j]='.';
							if(i-1>=0)
								grid[i-1][j]='.';
							if(j+1<c)
								grid[i][j+1]='.';
							if(j-1>=0)
								grid[i][j-1]='.';
						}
					}
				}
			}
		}
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				cout<<grid[i][j];
			}
			cout<<endl;
		}
	}
	
    return 0;
}


#include<iostream>
#include<vector>
using namespace std;

int main()  {  
    int m,n;
    cin>>m>>n;
    vector< vector<int> > grid(m,vector<int>(n,0));
    for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin>>grid[i][j];
	int x=0;
	int y=0;
	int dir=1;
	cout<<grid[0][0];
	while(true){
		if(dir==1){
			if(x+1<m && grid[x+1][y]!=0){
				cout<<" "<<grid[++x][y];	
				grid[x][y]=0;

			}
			else
				dir=2;
			continue;
		}
		if(dir==2){
			if(y+1<n && grid[x][y+1]!=0){
				cout<<" "<<grid[x][++y];	
				grid[x][y]=0;
			
			}
			else
				dir=3;
			continue;	
		} 
		if(dir==3){
			if(x-1>=0&& grid[x-1][y]!=0){
				cout<<" "<<grid[--x][y];	
				grid[x][y]=0;
			}
			else
				dir=4;
			continue;
		}
		if(dir==4){
			if(y-1>0 && grid[x][y-1]!=0){
				cout<<" "<<grid[x][--y];	
				grid[x][y]=0;
			}
			else
				dir=1;
			continue;
		}
		if(grid[x-1][y]==0 && grid[x+1][y]==0 && grid[x][y-1]==0 && grid[x][y+1]==0)
			break;		
	}
	return 0;	
}  
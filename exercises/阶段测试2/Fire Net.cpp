#include<iostream>
#include<algorithm>
using namespace std;

char grid[5][5]; //城市 
int n;
int max_blocks;
//判断改点是否符合放置blockhouse的条件 
bool check(int x, int y){ 
    for(int i=x-1;i>=0;i--){  
        if(grid[i][y]=='0')//判断该点的行 是否合法   
        	return false;  
        if(grid[i][y]=='X') 
        	break;  
    }  
    for(int i=y-1;i>=0;i--){  
        if(grid[x][i]=='0')//判断该点的了是否合法   
       	 	return false;  
        if(grid[x][i]=='X') 
        	break;  
    }  
    return true;  
}

void blockhouse(int num, int sum){//num为行乘（列-1）+现在的列 
	if(num == n*n){
		if(sum>max_blocks)
			max_blocks = sum;
		return;
	}
	int r = num / n;
	int c = num % n;
	if(grid[r][c]!='X'){
		if(check(r,c)){
			grid[r][c] = '0';
			blockhouse(num+1,sum+1);
			grid[r][c] = '.';
		}
	}
	blockhouse(num+1,sum);
}

int main(){

    while(cin>>n,n!=0){
	    for(int i=0; i<n; i++)
	    	for(int j=0; j<n; j++){
	    		cin>>grid[i][j];
			}
	    max_blocks = 0;
		blockhouse(0,0);	
		cout<<max_blocks<<endl;
	}

    return 0;
}
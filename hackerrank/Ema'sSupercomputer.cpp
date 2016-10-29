#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




int main() {
	int m,n;
	int c[225]={0};
	int post[225]={0};
	int num=0;
	cin>>n>>m;
	vector< vector<char> > grid(n,vector<char>(m));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			cin>>grid[i][j];
		}
		
		
	for(int i=1; i<n-1; i++){
		for(int j=1; j<m-1; j++){
			if(grid[i][j]=='G'){
				int cn = 1; 
            	int x = 0;
	            for(x=1; x<8; x++){
	                int flag = 1;
	                if(i-x <  0 || grid[i-x][j] != 'G') break;
	                if(i+x >= n || grid[i+x][j] != 'G') break;
	                if(j-x <  0 || grid[i][j-x] != 'G') break;
	                if(j+x >= m || grid[i][j+x] != 'G') break;
	                if(flag == 1) cn += 4; 
	
	                if(cn > 1){
	                    c[num] = cn; 
	                    post[num++]  = (i) * n + (j); 

	                }
	            }
	        }
		}
	}
	c[num] = 1;
	int max = 1;
	if(num==1){
		cout<<c[0]<<endl;
		return 0;
	}
		
	for(int i=0; i<num-1; i++){
		for(int j=i+1; j<=num; j++){
			if(c[i]*c[j]>max){
				int comp1[c[i]];
				int comp2[c[j]];
				
				int x=1,nx=1;
				comp1[0] = post[i];
				
				while(nx < c[i]){                    
	                comp1[nx++] = post[i] - (n * x);
	                comp1[nx++] = post[i] + (n * x);
	                comp1[nx++] = post[i] - x;
	                comp1[nx++] = post[i] + x;
	                x++; 
            	}
            	
            	x=1;nx=1;
            	comp2[0] = post[j];
            	while(nx < c[j]){                    
	                comp2[nx++] = post[j] - (n * x);
	                comp2[nx++] = post[j] + (n * x);
	                comp2[nx++] = post[j] - x;
	                comp2[nx++] = post[j] + x;
	                x++; 
            	}
				
				int flag = 1;                
	            for(int ni=0; ni<c[i]; ni++){
	                for(int nj=0; nj<c[j]; nj++){
	                    if(comp1[ni] == comp2[nj]){
	                        flag = 0;
	                        ni = c[i], nj = c[j];
	                    }                            
	                }
	            }
	            if(flag == 1) max = c[i] * c[j];
				
			}
		}
	}

	cout<<max<<endl;
    return 0;
}


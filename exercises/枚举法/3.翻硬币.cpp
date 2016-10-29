#include <iostream>

using namespace std;
int coin[10000][9];
int a[9];
int n;
void fanmian(){
	for(int i=0; i<9; i++){
		if(a[i]==1)
			for(int j=0; j<n; j++){
				if(coin[j][i]==0)
					coin[j][i]=1;
				else 
					coin[j][i]=0;
			}
	}
	
}
int main(){
	int x;
    cin>>n;  
    for(int i=0;i<n;i++)  
        for(int j=0;j<9;j++)  
        {  
            cin>>x;  
            coin[i][j]=x;  
        } 
	int max=0; 
    for(a[0]=0;a[0]<2;a[0]++) 
		for(a[1]=0;a[1]<2;a[1]++) 
			for(a[2]=0;a[2]<2;a[2]++)
		 		for(a[3]=0;a[3]<2;a[3]++) 
			 		for(a[4]=0;a[4]<2;a[4]++) 
				 		for(a[5]=0;a[5]<2;a[5]++) 
					 		for(a[6]=0;a[6]<2;a[6]++) 
						 		for(a[7]=0;a[7]<2;a[7]++) 
						 			for(a[8]=0;a[8]<2;a[8]++) {
						 				fanmian();
						 				int sum=0;
										for(int i=0; i<n; i++){
											int f=0;
											for(int j=0; j<9; j++){
												if(coin[i][j]==1)
													f++;
												
											}	
											if(f>=5)
												sum+=f;	
											else
												sum=sum+9-f;						 
										}
										if(sum>max)
											max=sum;
									 }
	
	cout<<max<<endl;
	return 0;
}

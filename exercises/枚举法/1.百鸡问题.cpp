#include <iostream>

using namespace std;

int main(){
    for(int i=0; i<34; i++)
    	for(int j=0; j<50; j++)
    		for(int k=0; k<300; k+=3){
    			if(i+j+k == 100 && 3*i+2*j+k/3 == 100)
    				cout<<i<<" "<<j<<" "<<k<<endl;
			}
	return 0;
}

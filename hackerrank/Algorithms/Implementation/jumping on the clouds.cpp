#include <iostream>

using namespace std;


int main(){
    int n;
    cin >> n;
    int *c = new int[n];
    for(int c_i = 0;c_i < n;c_i++){
       cin >> c[c_i];
    }
    
    int *p = c;
    int step = 0;
    int route = 0;
    int end = n-1;
    while(true){
    	if(*(p+2) == 0){
    		route+=2;
    		step++;
    		p+=2;
		}
		else if(*(p+1) == 0){
			route+=1;
			step++;
			p++;
		}
		if(route>=end)
			break;
	} 
	cout<<step<<endl;
    return 0;
}


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int d1;
    int m1;
    int y1;
    cin >> d1 >> m1 >> y1;
    int d2;
    int m2;
    int y2;
    int fine = 0;
    cin >> d2 >> m2 >> y2;
    
    if(y1<=y2) {
    	if(y1<y2)
    		fine = 0;
    	else {
	    	if(m1<=m2){
	    		if(m1<m2)
	    			fine = 0;
	    		else {
		    		fine = (d1-d2) * 15;
		    		if(fine<=0)
		    			fine = 0;		
				}
			}
			else {
				fine = (m1-m2) * 500;
			}
		} 
	}
	else {
		fine = 10000;
	}
	cout<<fine<<endl;
    return 0;
}

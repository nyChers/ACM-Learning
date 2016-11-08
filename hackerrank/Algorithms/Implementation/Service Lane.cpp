#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int t;
    cin >> n >> t;
    vector<int> width(n);
    for(int width_i = 0;width_i < n;width_i++){
       cin >> width[width_i];
    }
    
    vector<int> resu(t); 
    for(int a0 = 0; a0 < t; a0++){
        int i;
        int j;
        cin >> i >> j;
        resu[a0] = 3;
        for(int k=i; k<=j; k++){
        	if(width[k]<resu[a0])
        		resu[a0] = width[k];
		}	
    }
    for(int k=0; k<t; k++)
    	cout<<resu[k]<<endl;
    return 0;
}

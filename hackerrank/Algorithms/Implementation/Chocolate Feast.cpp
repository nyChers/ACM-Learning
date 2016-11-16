#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int c;
        int m;
        cin >> n >> c >> m;
        int cho = n/c;
        int wrapper = cho;
        while(wrapper/m){
        	int cho_add = wrapper / m;
	        wrapper = wrapper%m + cho_add;
  			cho += cho_add;
		}
		cout<<cho<<endl;    	
    }
    return 0;
}

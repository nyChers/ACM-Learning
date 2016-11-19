#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long b;
        long w;
        cin >> b >> w;
        long x;
        long y;
        long z;
        cin >> x >> y >> z;
        long sum;
        if(abs(x-y)>z) {
        	sum = min(x*(b+w)+w*z,y*(b+w)+b*z);
		}
		else {
			sum = x*b + y*w; 
		}
		cout<<sum<<endl;
    }
    return 0;
}

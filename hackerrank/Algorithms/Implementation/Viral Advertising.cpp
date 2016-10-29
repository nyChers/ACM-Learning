#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int people = 5;
    int people_like = 2;
    if(n==1)
    	cout<<people_like<<endl;
    else {
	    for(int i=2; i<=n; i++){
	    	people /= 2;
	    	people *= 3;	
	    	people_like += people/2;
		}
		cout<<people_like<<endl;
	}
    return 0;
}

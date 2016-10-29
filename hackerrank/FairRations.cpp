#include <iostream>

using namespace std;


int main(){
	int N;
	cin>>N;
    int loaves = 0;
	int carry = 0;
	while ( N-- ) {
	    int i;
	    cin >> i;
	    if ( (carry + i)%2 ) {
	        loaves += 2;
	        carry = 1;
	    } else
	        carry = 0;
	}
	if ( carry )
	    cout << "NO" << endl;
	else
	    cout << loaves << endl;
    
    return 0;
}


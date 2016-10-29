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
        cin >> n;
        int tree_height = 1;
		for(int i=0; i<=n; i++){
			if(i%2 == 1)
				tree_height *= 2;
			if(i%2 == 0 && i != 0)
				tree_height++;
		}
		cout<<tree_height<<endl;
    }
    return 0;
}

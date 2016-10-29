#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int s, t;
    cin >> s >> t;
    int a, b;
    cin >> a >> b;
    int m, n;
    cin >> m >> n;
    vector<int> apple(m);
    for(int apple_i = 0;apple_i < m;apple_i++){
       cin >> apple[apple_i];
    }
    vector<int> orange(n);
    for(int orange_i = 0;orange_i < n;orange_i++){
       cin >> orange[orange_i];
    }
    int apple_num = 0;
    int orange_num = 0;
    for(int i=0; i<m; i++){
    	if(apple[i] + a >= s && apple[i] + a <= t)
    		apple_num++;
	}
	for(int i=0; i<n; i++){
    	if(orange[i] + b >= s && orange[i] + b <= t)
    		orange_num++;
	}
	cout<<apple_num<<"\n"<<orange_num<<endl;
    return 0;
}

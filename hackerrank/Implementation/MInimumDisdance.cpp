#include <vector>
#include <iostream>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0;i < n;i++){
       cin >> A[i];
    }
    int m=n;
    for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++){
			if(A[i]==A[j])
				if(j-i<m)
					m=j-i;
		}
	if(m==n)
		m=-1;
	cout<<m<<endl;    
    return 0;
}


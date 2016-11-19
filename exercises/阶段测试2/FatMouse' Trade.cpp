#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm> 
using namespace std;

struct house{
	int j;
	double f;
//	house(int a, int b){
//		j = a;
//		f = b;
//	}
};
int cmp(house a, house b){
	return (a.j/a.f) > (b.j/b.f);
}
int main(){
	int N,M;
//	vector<house> h; 

	while(cin>>M>>N,M!=-1){
		house *h = new house[N];
//		int a,b;
		for(int i=0; i<N; i++){
			cin>>h[i].j>>h[i].f;
//			cin>>a>>b;
//			house temp(a,b);
//			h.push_back(temp);
		}
		sort(h,h+N,cmp);
		double sum = 0;
		for(int i=0; i<N; i++){
			if(M>=h[i].f){
				sum += h[i].j;		
				M -= h[i].f;		
			}				
			else{
				sum += M/h[i].f * h[i].j;
				break;
			}
		}
		cout<<fixed<<setprecision(3)<<sum<<endl;
	}
	return 0;
} 
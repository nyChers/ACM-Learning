#include<iostream>
#include<cmath>
#include <vector>
#define PI 3.14
using namespace std;

struct ball {
	int x;
	int y;
	int z;
	double r;
//	ball(){
//		x=0;y=0;z=0;
//	}
	ball(int a,int b, int c){
		x = a;
		y = b;
		z = c;
		r = 0.0;
	}
};
int main() {
	int n;
	cin>>n;
	int x1,x2,y1,y2,z1,z2;
	cin>>x1>>y1>>z1;
	cin>>x2>>y2>>z2;
	vector<ball> B;
	for(int i=0; i<n; i++){
		int a,b,c;
		cin>>a>>b>>c;
		ball x(a,b,c);
		B.push_back(x);
	} 
	int max_x,max_y,max_z;
	double max_r;
	double sum = 0;
	for(int i; i<n; i++){
		max_x = min(B[i].x-x1,x2-B[i].x);
		max_y = min(B[i].y-y1,y2-B[i].y);
		max_z = min(B[i].z-z1,z2-B[i].z);
		int t = min(max_x,max_y);
		max_r = min(t,max_z);
		for(int j=0; j<n; j++){
			if(j==i)
				continue;
			double temp_r = sqrt((B[i].x-B[j].x)*(B[i].x-B[j].x) + (B[i].y-B[j].y)*(B[i].y-B[j].y) +(B[i].z-B[j].z) *(B[i].z-B[j].z))-B[j].r;
			if(temp_r<max_r)
				max_r = temp_r;
		}
		B[i].r = max_r;
		sum += pow(max_r,3) * PI * 4/3.0;
	}
	double V = (x2-x1)*(y2-y1)*(z2-z1);
	double v2 = V-sum;
	cout<<int (v2+0.5)<<endl;
	return 0;
}
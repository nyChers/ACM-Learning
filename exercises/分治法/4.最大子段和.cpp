#include<iostream>
#include<cmath>

using namespace std;

int max_sub1(int a[], int left, int right) { //分治法 
	int s1,s2;
	if(left>=right)
		return a[left];
	int m = (left + right) / 2;		
	s1 = max_sub1(a, left, m);
	s2 = max_sub1(a, m + 1, right);
	
	int sm1 = 0;
	int temp = 0;
	for(int i=m; i>=left; i--){
		temp += a[i];
		if(temp>sm1)
			sm1 = temp;
	}
	int sm2 = 0; 
	temp = 0;
	for(int i=m+1; i<=right; i++){
		temp += a[i];
		if(temp>sm2)
			sm2 = temp;
	}
	int sum = sm1 + sm2;
	if(sum<s1)
		sum = s1;
	if(sum<s2)
		sum = s2;
	return sum;
} 
int max_sub2(int *v,int n) {//动态规划 

    int sum=0,b=0;
    int i;
    for (i=0;i<n;i++)
    {
        if(b>0)
            b+=v[i];
        else
            b=v[i];
        if(b>sum)
            sum=b;
    }
    return sum;
}
int main() {
	int n;
	cin>>n;
	int *a = new int [n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int m1 = max_sub1(a, 0, n-1);
	int m2 = max_sub2(a,n);
	cout<<m1<<" "<<m2<<endl;
	return 0;	
} 
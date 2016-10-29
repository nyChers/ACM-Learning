#include<iostream>
#include<cstring>
using namespace std;

int flag[10];
int temp[10];

bool check(int n){
	do{
		flag[n % 10]++;
	}while(n /= 10);
	if(flag[0] != 0) {
		return false;
	}
	for(int i = 1; i < 10; i++) {
		if(flag[i] > 1) {
			return false;
		}
	}
	return true;
}

bool c(){
	for(int i = 1; i < 10; i++) {
		if(flag[i] != 1) {
			return false;
		}
	}
	return true;
}

int main(){
	int num;
	int count = 0;
	cin>>num;
	int l,u,d;
	for(l = 1; l <= num; l++) {
		memset(flag, 0, sizeof(flag));
		if(!check(l)) {
			continue;
		}
		memcpy(temp, flag, sizeof(flag));
		for(d = 1; d < 100000; d++) {
			memcpy(flag, temp, sizeof(flag));
			u=(num - l) * d;
			if(!(check(u) && check(d))) 
				continue;
			if(c()) 
				count++;
		}
	}
	cout<<count<<endl;
	return 0;
}
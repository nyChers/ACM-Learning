/*还与年龄相关

Problem Description
某君从某年开始每年都举办一次生日party，并且每次都要吹熄与年龄相同根数的蜡烛。
现在算起来，他一共吹熄了236根蜡烛。
请问，他从多少岁开始过生日party的？
请填写他开始过生日party的年龄数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。*/

#include<iostream>
using namespace std;

int main() {
	int i;  
    int n;  
    int sum = 236;  
      
    for (i = 0; i < 100; i++) {  
        for (n = 0; n < 100; n++) {  
            if ((n + 1) * (2 * i + n) == 472)  
            	cout<<i<<endl;
        }  
    }  
      
    return 0;  
}
/*  
i + (i + 1) + (i + 2) +...+(i + n) =236  
   (n + 1)*i +n*(n+1)/2 =236  
   2*(n+1)*i + n*(n+1) =472  
   (2*i+n)*(n+1) = 472  
*/  
//26

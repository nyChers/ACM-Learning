/*39级台阶

Problem Description
小明刚刚看完电影《第39级台阶》，离开电影院的时候，他数了数礼堂前的台阶数，恰好是39级!
站在台阶前，他突然又想着一个问题：
如果我每一步只能迈上1个或2个台阶。先迈左脚，然后左右交替，最后一步是迈右脚，也就是说一共要走偶数步。那么，上完39级台阶，有多少种不同的上法呢？
请你利用计算机的优势，帮助小明寻找答案。
要求提交的是一个整数。
注意：不要提交解答过程，或其它的辅助说明文字。*/

#include <iostream>  
using namespace std;  
   
long step[40][2];  
//step[i][0]表示走到第i个台阶式最后一步迈的是左脚   
//step[i][1]表示走到第i个台阶式最后一步迈的是右脚   
   
int main() {  
    step[0][0] = 0;  
    step[1][1] = 0;  
    step[0][1] = 1;  
    step[1][0] = 1;  
    for(int i = 2; i <= 39; i++) {  
        step[i][0] = step[i - 1][1] + step[i - 2][1];  
        step[i][1] = step[i - 1][0] + step[i - 2][0];  
    }  
    cout << step[39][1];//最后一步迈的是右脚   
    return 0;  
}  
/*#include <iostream>  
using namespace std;    
    
long ans = 0;    
void dfs(int sum,int step)     
{    
    if(sum<0)   return ;    
    if(step%2 == 0 && sum == 0)  //如果走完台阶而且步数为偶数则算为一种走法   
    {    
        ans++;    
        return ;    
    }    
    for(int i = 1;i<=2;i++)  //下一步可有走一步或者两步   
        dfs(sum-i,step+1);    
}    
    
int main()    
{    
    dfs(39,0);    
    cout << ans ;  
    return 0;    
}*/  
//51167078

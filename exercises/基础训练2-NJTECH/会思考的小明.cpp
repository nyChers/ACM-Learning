/*会思考的小明
Problem Description
小明被劫持到X赌城，被迫与其他3人玩牌。
一副扑克牌（去掉大小王牌，共52张），均匀发给4个人，每个人13张。
这时，小明脑子里突然冒出一个问题：
如果不考虑花色，只考虑点数，也不考虑自己得到的牌的先后顺序，自己手里能拿到的初始牌型组合一共有多少种呢？
请填写该整数，不要填写任何多余的内容或说明文字。*/
#include <iostream>  
using namespace std;  
  
int ans = 0;  
void dfs(int cur,int sum)//cur为当前牌的点数，sum为手中总牌数 
{  
    if(sum>13) {  
        return;  
    }  
    if(cur==13) {  
        if(sum==13)  
            ans++;  
        return;  
    }  
    for(int i=0; i<=4; i++) {//i为当前点数牌的数量 
        dfs(cur+1,sum+i);  
    }  
}  
  
int main() {  
    dfs(0,0);  
   	cout<<ans; 
    return 0;  
}
//3598180


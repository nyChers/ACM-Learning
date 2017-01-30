/*组合样式数
Problem Description
小明有3颗红珊瑚，4颗白珊瑚，5颗黄玛瑙。
他想用它们串成一圈作为手链，送给女朋友。
现在小明想知道：如果考虑手链可以随意转动或翻转，一共可以有多少不同的组合样式呢？
请你提交该整数。不要填写任何多余的内容或说明性的文字。*/
#include <iostream>  
#include <algorithm>  
#include <string>  
#include <vector>  
using namespace std;  
  
int main() {  
    vector<string> v;//存已经找到的  
    int sum = 0;  
    string str = "aaabbbbccccc";  
    do {  
        vector<string>::iterator it;  
        for(it=v.begin(); it != v.end(); it++) {  
            //当寻找失败返回string::npos 值为4294967295  
            if((*it).find(str, 0) != string::npos)  
                break;  
        }  
        if( it != v.end() ) 
			continue;  
        string str2 = str + str;  //可以任意转动的缘故  
        v.push_back(str2);  
        reverse(str2.begin(), str2.end());  //可以任意翻转的缘故  
        v.push_back(str2);  
        sum ++;  
    }  
    while(next_permutation(str.begin(), str.end()));  
    cout << sum ;  
}
//1170
//这个解法不错0.0
//要多看看STL了 

/*删除字母

Problem Description
把abcd...s共19个字母组成的序列重复拼接106次，得到长度为2014的串。
接下来删除第1个字母（即开头的字母a），以及第3个，第5个等所有奇数位置的字母。得到的新串再进行删除奇数位置字母的动作。
如此下去，最后只剩下一个字母，请写出该字母。
答案是一个小写字母，不要填写任何多余的内容。*/
#include<iostream>
#include<string>
using namespace std;

int main() {
	string s="", s1="", s2="";  
	int i;  
    for(i=0; i<19; i++){  
        char a = (char)('a'+i);  
        s += a;  
    }  
    s1 = s;  
    for(i=0; i<105; i++)  
        s += s1;  
    while(s.length() != 1){  
        for(i=0; i<s.length(); i++){  
            if(i % 2 == 1){  
                s2 += s[i];  
            }                 
        }  
        s = s2;  
        s2 = "";  
    }  
    cout<<s<<endl;   
}
//q 

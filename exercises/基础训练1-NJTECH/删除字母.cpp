/*ɾ����ĸ

Problem Description
��abcd...s��19����ĸ��ɵ������ظ�ƴ��106�Σ��õ�����Ϊ2014�Ĵ���
������ɾ����1����ĸ������ͷ����ĸa�����Լ���3������5������������λ�õ���ĸ���õ����´��ٽ���ɾ������λ����ĸ�Ķ�����
�����ȥ�����ֻʣ��һ����ĸ����д������ĸ��
����һ��Сд��ĸ����Ҫ��д�κζ�������ݡ�*/
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

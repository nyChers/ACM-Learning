/*�����ʽ��
Problem Description
С����3�ź�ɺ����4�Ű�ɺ����5�Ż���觡�
���������Ǵ���һȦ��Ϊ�������͸�Ů���ѡ�
����С����֪�����������������������ת����ת��һ�������ж��ٲ�ͬ�������ʽ�أ�
�����ύ����������Ҫ��д�κζ�������ݻ�˵���Ե����֡�*/
#include <iostream>  
#include <algorithm>  
#include <string>  
#include <vector>  
using namespace std;  
  
int main() {  
    vector<string> v;//���Ѿ��ҵ���  
    int sum = 0;  
    string str = "aaabbbbccccc";  
    do {  
        vector<string>::iterator it;  
        for(it=v.begin(); it != v.end(); it++) {  
            //��Ѱ��ʧ�ܷ���string::npos ֵΪ4294967295  
            if((*it).find(str, 0) != string::npos)  
                break;  
        }  
        if( it != v.end() ) 
			continue;  
        string str2 = str + str;  //��������ת����Ե��  
        v.push_back(str2);  
        reverse(str2.begin(), str2.end());  //�������ⷭת��Ե��  
        v.push_back(str2);  
        sum ++;  
    }  
    while(next_permutation(str.begin(), str.end()));  
    cout << sum ;  
}
//1170
//����ⷨ����0.0
//Ҫ�࿴��STL�� 

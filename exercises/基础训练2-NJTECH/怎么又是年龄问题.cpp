/*��ô������������
Problem Description
С�������ı��һ��ȥ����Ӱ�����������ǵ����䡣
С��˵�����������ǵ������갡���ҳ�����ݵ���λ���ּ������պ����ҵ����䡣��ܵ�Ҳ����ˡ�
���������2014�꣨2014����⣩�����ң�С��˵������ָ�������ꡣ
���ƶϲ���д��С���ĳ�����ݡ�
����һ��4λ��������ͨ��������ύ�𰸣���Ҫ��д�κζ�������ݣ����磬����ܵĳ�����ݣ��������ǵ�����ȵȣ�*/
#include<iostream>
using namespace std;

int check(int y) {
	int sum = 0;
	while(y) {
		sum += y%10;
		y /= 10; 
	}
	return sum;
}
int main() {
	int y = 2014;
	int age = 0;
	int cnt = 0;
	while(true) {
		y--;
		age++;
		if(check(y)==age) {
			cout<<y<<endl;
			cnt++;
			if(cnt==2)
				break;
		}			
	}
}
//1988

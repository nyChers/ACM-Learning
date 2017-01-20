/*猜年龄
Problem Description
小明带两个妹妹参加元宵灯会。别人问她们多大了，她们调皮地说：“我们俩的年龄之积是年龄之和的6倍”。小明又补充说：“她们可不是双胞胎，年龄差肯定也不超过8岁啊。”
请你写出：小明的较小的妹妹的年龄。
注意： 只写一个人的年龄数字。不要书写任何多余的内容。*/
#include<iostream>
using namespace std;

int main() {
	int y1,y2;
	for(y1=1; y1<50; y1++) {
		for(y2=y1+1; y2<=y1+8; y2++) {
			if((y1+y2)*6==y1*y2)
				cout<<y1<<endl;
		}
	}
	return 0;
}
//10

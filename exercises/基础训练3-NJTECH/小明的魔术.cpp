/*小明的魔术
Problem Description
小明刚上小学，学会了第一个扑克牌“魔术”，到处给人表演。魔术的内容是这样的：
他手里握着一叠扑克牌：A，2，....J，Q，K 一共13张。他先自己精心设计它们的顺序，然后正面朝下拿着，开始表演。
只见他先从最下面拿一张放到最上面，再从最下面拿一张翻开放桌子上，是A；然后再从最下面拿一张放到最上面，再从最下面拿一张翻开放桌子上，是2；......如此循环直到手中只有一张牌，翻开放桌子上，刚好是K。
这时，桌上牌的顺序是：A,2,3,4,5,6,7,8,9,10,J,Q,K

请你计算一下，小明最开始的时候手里牌的顺序是怎样的。
把结果写出来，逗号分割，小明“魔术”开始时，最下面的那张牌输出为第一个数据。
考场不提供扑克牌，你只能用计算机模拟了，撕碎草稿纸模拟扑克属于作弊行为！另外，你有没有把录像倒着放过？很有趣的！回去试试！*/
#include<iostream>
using namespace std;  
int main() {   
	int first[13],n[13]={0},i=0,c=1;  
    char card[15]=" A23456789TJQK";  
    while(1) {     
        while(n[i]==1)  //找出第一个到没有翻过的牌  
          i=(i+1)%13;  
        i=(i+1)%13;     //跳过这张牌 (要放到上面，不翻)
        while(n[i]==1)  //继续找出下一个到没有翻过的牌  
          i=(i+1)%13;  
        n[i]=1;         //给这张牌做翻过的标记，这张牌的序号是i  
        first[i]=c++;   //第i张牌是C (第i张牌是第c个被翻的) 
        if(c==14) break;  
    }  
    for(i=0;i<=12;i++)  //将牌翻过来输出  
        if(first[i]==10) 
			cout<<"10,";  
        else  
            cout<<card[first[i]]<<',';  
    return 0;  
}  
//7,A,Q,2,8,3,J,4,9,5,K,6,10
/*#include <stdio.h>  
#include <queue>  
using namespace std;  
struct card {  
    char num; //num=牌上标的数字  
    int id; //id=第id张牌  
}member,first,second,in[13]; //队首=first,从前往后第二个牌=second,  
queue <card> q;  
char out[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};  
int main() {  
    int i,j;  
    member.num=-1;  
    for(i=0;i<13;i++) {  
        member.id=i;  
        q.push(member); //首先队列里推入13个-1，表示13个牌都是未知的  
    }  
    i=0,j=0;  
    while(!q.empty()) {//所有牌没清完，就一直循环  
        first=q.front();  
        q.pop();  
        q.push(first); //队首弹出，压入队尾  
        second=q.front(); //弹出第二张牌  
        q.pop();  
        second.num=out[i++];  
        in[second.id]=second;  
    }  
    for(i=0;i<13;i++) {  
        if(in[i].num=='T') printf("10");  
        else printf("%c",in[i].num);  
        if(i!=12)  
            printf(",");  
        else  
            printf("\n");  
    }  
    return 0;  
}//借鉴*/

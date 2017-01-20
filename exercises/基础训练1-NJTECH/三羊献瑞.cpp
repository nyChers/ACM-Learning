/*三羊献瑞

Problem Description
观察下面的加法算式：
_ 祥 瑞 生 辉
+ 三 羊 献 瑞
-------------------
三 羊 生 瑞 气

其中，相同的汉字代表相同的数字，不同的汉字代表不同的数字(注意：第一行前的下划线只是为了对齐，没有实际意义)。
请你填写“三羊献瑞”所代表的4位数字（答案唯一），不要填写任何多余内容。*/
#include<iostream>
using namespace std;

int check(int num1,int num2,int num3,int num4,int num5, int num6,int num7, int num8)  
{  
    int i,j;      
    int array[8];  
    array[0]=num1; array[1]=num2; array[2]=num3;  
    array[3]=num4; array[4]=num5; array[5]=num6;  
    array[6]=num7; array[7]=num8;  

    for(i=0;i<8;i++){  
        for(j=i+1;j<8;j++){  
            if(array[j]==array[i])  
                return 0;  
        }  
    }  
    return 1;  
}  
  
  
int main() {  
    int x,r,s,h,san,y,xian,q;  
    int number1, number2,number3;  
  
  
    for(x=1;x<10;x++){  
        for(r=0;r<10;r++){  
            for(s=0;s<10;s++){  
                for(h=0;h<10;h++){                     
                    for(san=1;san<10;san++){  
                        for(y=0;y<10;y++){  
                            for(xian=0;xian<10;xian++){                                 
                                for(q=0;q<10;q++){  
                                    number1=x*1000+r*100+s*10+h;  
                                    number2=san*1000+y*100+xian*10+r;  
                                    number3=san*10000+y*1000+s*100+r*10+q;  
  
                                    if(number1+number2==number3 && check(x,r,s,h,san,y,xian,q))  
                                        cout<<number2<<endl;  
                                }  
                            }  
                        }  
                    }  
                }  
            }  
        }  
    } 
    return 0;  
}  

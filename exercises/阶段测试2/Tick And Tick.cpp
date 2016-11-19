/****************************************************************************
*								  											*
*	秒钟的速度s=6°/s，分针是1/10°/s，时针是1/120°/s			  			*
*	所以相对速度s_m=59/10°/s，s_h=719/120°/s，m_h=120/11°/s		  		*
*	所以相差一度所需要的时间sm=10/59 s/°，sh=120/719 s/°，mh=120/11 s/°  *
*	他们差360°的周期为tsm=3600/59 s，tsh=43200/719 s，tmh=43200/11 s	  	*
*	需要相差的角度为n。                                                    	*
*	rsm>n → n*sm+k1*tsm < t < tsm-n*sm+k1*tsm;			 				 	*
*	rsh>n → n*sh+k2*tsh < t < tsh-n*sh+k2*tsh;		           				*
*	rmh>n → n*mh+k3*tmh < t < tmh-n*mh+k3*tmh;			  					*
*	三个条件都满足所占的总时间即为时针、分针、秒针相差角度大于n的总时间     *
*								  											*
****************************************************************************/
//思路：	1、求出两两指针的相对较速度。
//　　　	2、然后根据这个相对角速度求出两两之间的周期（即第一次重合到第二次重合所花的时间）。
//      	3、计算出符合角度要求的两指针第一次满足和第一次不满足的时间。
//        4、在三个时间段上加上各自的周期，再取他们的交集即可。
#include<iostream>
#include<iomanip> 
#include<algorithm>
using namespace std;

double max1(double a, double b, double c){
	return a>b ? (a>c ? a:c):(b>c ? b:c);
}

double min1(double a, double b, double c){
	return a<b ? (a<c ? a:c):(b<c ? b:c);
}
int main(){
	double d;
	double cycle_sm=3600./59.;
	double cycle_sh=43200./719.;
	double cycle_mh=43200./11.;
	//这三行是时针、分针、秒针两两相遇的周期
	double sum;
	double happys,happye;
	//开始happy和结束happy的时刻
	double sm=10./59.,sh=120./719.,mh=120./11.;//相差一度所需要的时间
	
	double d_sm,d_sh,d_mh;//表示相差d°及以上的时刻
	double not_d_sm,not_d_sh,not_d_mh;//和不再相差d°及以上的时刻

	while(cin>>d,d!=-1){
		sum=0;
		d_sm=sm*d; 
		not_d_sm=cycle_sm-d_sm;
		d_sh=sh*d; 
		not_d_sh=cycle_sh-d_sh;
		d_mh=mh*d; 
		not_d_mh=cycle_mh-d_mh;

		happys=max1(d_sm,d_sh,d_mh);
		happye=min1(not_d_sm,not_d_sh,not_d_mh);

		while(happys<=43200 && happye<=43200)//43200是时针针转一圈的秒数
		{
			happys=max1(d_sm, d_sh, d_mh);//两两之间最后一个满足相差d°及以上的条件视为开始happy时刻
			happye=min1(not_d_sm, not_d_sh, not_d_mh);//两两之间第一个不再满足相差d°及以上视为结束happy的时刻

			if(happys<happye)
				sum+=happye-happys;//如果end的时间比start的晚,由sum记录并累积

			if(happye==not_d_sm){
				d_sm+=cycle_sm;
				not_d_sm+=cycle_sm;
			}
			else if(happye==not_d_sh){
				d_sh+=cycle_sh;
				not_d_sh+=cycle_sh;
			}
			else if(happye==not_d_mh){
				d_mh+=cycle_mh;
				not_d_mh+=cycle_mh;
			}//happy时间end后最慢的指针要提前一个周期才能让比它快的再次追上
		}
		cout<<fixed<<setprecision(3)<<sum/43200*100<<endl;
	}
	return 0;
}	
//int main(){
//	double d;
//	
//	枚举离散的点，精度不够 
//	while(cin>>d, d!=-1){
//		double time = 0;
//		double h = 0, m = 0, s = 0;
//		for(int i=1; i<=43200; i++){
//			h += 1.0/120;
//			if(h>=360)
//				h -= 360;
//			m += 0.1;
//			if(m>=360)
//				m -= 360;
//			s += 6;
//			if(s>=360)
//				s -= 360;
//			double a = abs(h-s)>180 ? 360-abs(h-s):abs(h-s);
//			double b = abs(m-s)>180 ? 360-abs(m-s):abs(m-s);		
//			double c = abs(h-m)>180 ? 360-abs(h-m):abs(h-m);			
//			if(a>=d && b>=d && c>=d)
//				time++;
//		} 
//		cout<<fixed<<setprecision(3)<<time/432<<endl;
//	}
//}
//

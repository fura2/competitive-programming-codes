#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool is_leap(int y){
	if(y%400==0) return true;
	if(y%100==0) return false;
	return y%4==0;
}

int days(int y,int m){
	switch(m){
		case  1: return 31;
		case  2: return is_leap(y)?29:28;
		case  3: return 31;
		case  4: return 30;
		case  5: return 31;
		case  6: return 30;
		case  7: return 31;
		case  8: return 31;
		case  9: return 30;
		case 10: return 31;
		case 11: return 30;
		case 12: return 31;
	}
	return -1;
}

int main(){
	while(1){
		int y,m,d,hh,mm,ss;
		scanf("%d/%d/%d %d:%d:%d",&y,&m,&d,&hh,&mm,&ss);
		if(y==0) break;

		int t;
		{
			string s; cin>>s;
			t=stoi(s,nullptr,2);
		}

		// 直近の 1 月 1 日まで 1 日ずつ進める
		while(!(m==1 && d==1)){
			int T=24*60*60;
			if(t<T) break;
			t-=T;
			d++;
			if(d>days(y,m)) d=1, m++;
			if(m>12) m=1, y++;
		}

		// 1 年ずつ進める
		while(1){
			int T=(is_leap(y)?366:365)*24*60*60;
			if(t<T) break;
			t-=T;
			y++;
		}

		// 1 日ずつ進める
		while(1){
			int T=24*60*60;
			if(t<T) break;
			t-=T;
			d++;
			if(d>days(y,m)) d=1, m++;
			if(m>12) m=1, y++;
		}

		// 1 秒ずつ進める
		while(t>0){
			t--;
			ss++;
			if(ss>=60) ss=0, mm++;
			if(mm>=60) mm=0, hh++;
			if(hh>=24) hh=0, d++;
			if(d>days(y,m)) d=1, m++;
			if(m>12) m=1, y++;
		}

		printf("%d/%02d/%02d %02d:%02d:%02d\n",y,m,d,hh,mm,ss);
	}

	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool isleap(int y){ return y%400==0 || (y%100!=0 && y%4==0); }

int main(){
	const int D[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

	int y,m,d; scanf("%d/%d/%d",&y,&m,&d);
	rep(_,2){
		d++;
		if(d>(m==2&&isleap(y)?D[m]+1:D[m])) d=1, m++;
		if(m>12) m=1, y++;
	}
	printf("%d/%02d/%02d\n",y,m,d);

	return 0;
}

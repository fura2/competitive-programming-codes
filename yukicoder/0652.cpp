#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-7;

int main(){
	int h,m;
	double d; scanf("%d%d UTC%lf",&h,&m,&d);

	double h2=h+m/60.0+d-9;
	while(h2>=24-EPS) h2-=24;
	while(h2<-EPS) h2+=24;
	printf("%02d:%02d\n",int(h2),int((h2-int(h2))*60+0.5));

	return 0;
}

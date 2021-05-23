// subtask 1

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-9;

int ask(double x,double y){
	printf("? %.9f %.9f\n",x,y);
	fflush(stdout);
/*
static int cnt=0;
cnt++;
fprintf(stderr,"cnt = %d\n",cnt);
int x0=1000;
int y0=723;
int r=934;
return (x-x0)*(x-x0)+(y-y0)*(y-y0)<=r*r;
*/
	int res; scanf("%d",&res);
	return res;
}

int main(){
	int n; scanf("%d",&n);
	if(n!=1) return -1;

	int x0,y0;
	bool ok=false;
	for(int x=-2000;x<=2000;x+=100) if(!ok) for(int y=-2000;y<=2000;y+=100) if(!ok) {
		int res=ask(x,y);
		if(res==1){
			ok=true;
			x0=x;
			y0=y;
		}
	}
	assert(ok);

	auto f=[](int x,int y){
		double lo,hi;
		lo=-2001; hi=y;
		rep(_,25){
			double mi=(lo+hi)/2;
			if(ask(x,mi)==1) hi=mi;
			else             lo=mi;
		}
		double y1=hi;

		lo=y; hi=2001;
		rep(_,25){
			double mi=(lo+hi)/2;
			if(ask(x,mi)==1) lo=mi;
			else             hi=mi;
		}
		double y2=lo;

		return make_pair(y1,y2);
	};

	double d;
	{
		auto tmp=f(x0,y0);
		d=tmp.second-tmp.first;
	}
	double x_ans,y_ans;
	rep(i,2){
		for(int x=x0;;x+=(i==0?1:-1)){
			if(ask(x,y0)==0) break;
			auto tmp=f(x,y0);
			if(d>tmp.second-tmp.first+EPS) break;

			d=tmp.second-tmp.first;
			x_ans=x;
			y_ans=(tmp.first+tmp.second)/2;
		}
	}

	puts("!");
	printf("%.f %.f %.f\n",x_ans,y_ans,d/2);
	fflush(stdout);

	return 0;
}

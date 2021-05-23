#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-9;

class circle{
public:
	double x,y,r;
	circle(double x,double y,double r):x(x),y(y),r(r){}
};
vector<circle> ans;

int ask(double x,double y){
	printf("? %.9f %.9f\n",x,y);
	fflush(stdout);
	int res; scanf("%d",&res);
	for(auto C:ans) if((x-C.x)*(x-C.x)+(y-C.y)*(y-C.y)<C.r*C.r+EPS) res--;
	return res;
}

int main(){
	int n; scanf("%d",&n);

	double x0=-1e7,y0=-1e7;
	rep(_,n){
		bool ok=false;
		for(int y=-2000;y<=2000;y+=250) if(!ok) for(int x=-2000;x<=2000;x+=250) if(!ok) {
			if(y<y0 || (y==y0 && x<x0)) continue;
			int res=ask(x,y);
			if(res>0){
				ok=true;
				x0=x;
				y0=y;
			}
		}
		assert(ok);

		auto f=[](double x,double y){
			double lo=x-250,hi=x;
			rep(_,40){
				double mi=(lo+hi)/2;
				if(ask(mi,y)>0) hi=mi;
				else            lo=mi;
			}
			return hi;
		};

		double y1=y0-0.1;
		double y2=y0;
		double y3=y0+0.1;
		double x1=f(x0,y1);
		double x2=f(x0,y2);
		double x3=f(x0,y3);

		double xc=(y1-y2)*(x3*x3-x1*x1+y3*y3-y1*y1)-(y1-y3)*(x2*x2-x1*x1+y2*y2-y1*y1);
		xc/=2*(x1-x2)*(y1-y3)-2*(x1-x3)*(y1-y2);
		double yc=(x1-x3)*(x2*x2-x1*x1+y2*y2-y1*y1)-(x1-x2)*(x3*x3-x1*x1+y3*y3-y1*y1);
		yc/=2*(x1-x2)*(y1-y3)-2*(x1-x3)*(y1-y2);
		ans.emplace_back(xc,yc,hypot(x1-xc,y1-yc));
	}

	sort(ans.begin(),ans.end(),[](circle C1,circle C2){
		if(abs(C1.x-C2.x)>EPS) return C1.x<C2.x;
		if(abs(C1.y-C2.y)>EPS) return C1.y<C2.y;
		return false;
	});

	puts("!");
	rep(i,n) printf("%.f %.f %.f\n",ans[i].x,ans[i].y,ans[i].r);
	fflush(stdout);

	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using Real=double;

constexpr Real EPS=1e-8;
constexpr Real PI=acos(Real(-1));

int sgn(const Real& x){ return x>EPS?1:x<-EPS?-1:0; }

class point{
public:
	Real x,y;
	point(){}
	point(const Real& x,const Real& y):x(x),y(y){}
	point& operator+=(const point& p){ x+=p.x; y+=p.y; return *this; }
	point& operator-=(const point& p){ x-=p.x; y-=p.y; return *this; }
	point& operator*=(const Real& c){ x*=c; y*=c; return *this; }
	point& operator/=(const Real& c){ x/=c; y/=c; return *this; }
	point operator+(const point& p)const{ return point(*this)+=p; }
	point operator-(const point& p)const{ return point(*this)-=p; }
	point operator*(const Real& c)const{ return point(*this)*=c; }
	point operator/(const Real& c)const{ return point(*this)/=c; }
	point operator-()const{ return point(-x,-y); }
	bool operator==(const point& p)const{ return sgn(x-p.x)==0 && sgn(y-p.y)==0; }
	bool operator!=(const point& p)const{ return !((*this)==p); }

	friend point operator*(const Real& c,const point& p){ return p*c; }
};

Real angle(const point& v){ Real t=atan2(v.y,v.x); return t<0?t+2*PI:t; }

int main(){
	int n; scanf("%d",&n);
	vector<point> p(n);
	rep(i,n) scanf("%lf%lf",&p[i].x,&p[i].y);

	auto f=[](double t1,double t2){
		double d=abs(t1-t2);
		while(d>2*PI-EPS) d-=2*PI;
		return min(d,2*PI-d);
	};

	double ans=0;
	rep(i,n){
		vector<double> a;
		rep(j,n) if(i!=j) {
			a.emplace_back(angle(p[j]-p[i]));
			a.emplace_back(angle(p[j]-p[i])+2*PI);
		}
		sort(a.begin(),a.end());

		int k=1;
		rep(j,n-1){
			while(k+1<a.size()){
				double t1=f(a[j],a[k]);
				double t2=f(a[j],a[k+1]);
				if(abs(t1-PI)<abs(t2-PI)) break;
				k++;
			}
			ans=max(ans,f(a[j],a[k]));
		}
	}
	printf("%.9f\n",ans/PI*180);

	return 0;
}

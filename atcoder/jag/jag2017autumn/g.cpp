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

Real dot  (const point& p,const point& q){ return p.x*q.x+p.y*q.y; }
Real cross(const point& p,const point& q){ return p.x*q.y-p.y*q.x; }

Real abs (const point& p){ return sqrt(p.x*p.x+p.y*p.y); }
Real abs2(const point& p){ return p.x*p.x+p.y*p.y; }

point rot(const point& p,const Real& theta){
	return {p.x*cos(theta)-p.y*sin(theta),p.x*sin(theta)+p.y*cos(theta)};
}

Real arg(const point& v){ Real t=atan2(v.y,v.x); return t<0?t+2*PI:t; }

class line{
public:
	point a,b;
	line(){}
	line(const point& a,const point& b):a(a),b(b){}
	bool operator==(const line& L)const{
		return sgn(cross(b-a,L.b-L.a))==0 && sgn(cross(L.a-a,L.b-a))==0;
	}
};

class segment{
public:
	point a,b;
	segment(){}
	segment(const point& a,const point& b):a(a),b(b){}
	operator line()const{ return line(a,b); }
};

using polygon=vector<point>;

class circle{
public:
	point c;
	Real r;
	circle(){}
	circle(const point& c,const Real& r):c(c),r(r){}
};

Real dist(const point& a,const point& b){ return abs(a-b); }

Real dist(const segment &S,const point &p){
	if(sgn(dot(S.b-S.a,p-S.a))<=0) return dist(p,S.a);
	if(sgn(dot(S.a-S.b,p-S.b))<=0) return dist(p,S.b);
	return abs(cross(S.b-S.a,p-S.a))/dist(S.a,S.b);
}

inline int popcount(unsigned int x){
	x-=(x>>1)&0x55555555;
	x=(x&0x33333333)+((x>>2)&0x33333333);
	return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;
}

int main(){
	int n; scanf("%d",&n);
	vector<Real> r(n);
	vector<point> s(n),g(n);
	rep(i,n) scanf("%lf%lf%lf%lf%lf",&r[i],&s[i].x,&s[i].y,&g[i].x,&g[i].y);

	vector dp(1<<n,false);
	dp[0]=true;
	rep(S,1<<n) if(dp[S]) {
		rep(i,n) if(~S>>i&1 && !dp[S|1<<i]) {
			segment L(s[i],g[i]);

			bool ok=true;
			rep(j,n) if(j!=i) {
				if(S>>j&1){ // 移動済み
					if(sgn(dist(L,g[j])-(r[i]+r[j]))<0) ok=false;
				}
				else{
					if(sgn(dist(L,s[j])-(r[i]+r[j]))<0) ok=false;
				}
			}
			if(ok) dp[S|1<<i]=true;
		}
	}

	int ans=0;
	rep(S,1<<n) if(dp[S]) ans=max(ans,popcount(S));
	printf("%d\n",ans);

	return 0;
}

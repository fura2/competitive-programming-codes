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
	bool operator!=(const line& L)const{ return !((*this)==L); }
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

point proj(const point& p,const line& L){ return L.a+dot(p-L.a,L.b-L.a)/abs2(L.b-L.a)*(L.b-L.a); }

enum{CCW=1,CW=-1,ON=0};
int ccw(const point& a,const point& b,const point& c){
	int d=sgn(cross(b-a,c-a));
	return d>0?CCW:d<0?CW:ON;
}

bool intersect(const segment& S1,const segment& S2){
	if(sgn(min(S2.a.x,S2.b.x)-max(S1.a.x,S1.b.x))==1
	|| sgn(min(S2.a.y,S2.b.y)-max(S1.a.y,S1.b.y))==1
	|| sgn(min(S1.a.x,S1.b.x)-max(S2.a.x,S2.b.x))==1
	|| sgn(min(S1.a.y,S1.b.y)-max(S2.a.y,S2.b.y))==1){
		return false;
	}
	return ccw(S1.a,S1.b,S2.a)*ccw(S1.a,S1.b,S2.b)<=0
		&& ccw(S2.a,S2.b,S1.a)*ccw(S2.a,S2.b,S1.b)<=0;
}

int main(){
	int n; scanf("%d",&n);
	point p,q;
	scanf("%lf%lf%lf%lf",&p.x,&p.y,&q.x,&q.y);

	if(p==q){
		puts("1");
		return 0;
	}

	int ans=1;
	rep(i,n-1){
		point a,b;
		scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
		if(intersect(segment(p,q),segment(a,b))) ans++;
	}
	printf("%d\n",ans);

	return 0;
}

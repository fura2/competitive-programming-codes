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

Real dist(const point& a,const point& b){ return abs(a-b); }

Real dist(const segment &S,const point &p){
	if(sgn(dot(S.b-S.a,p-S.a))<=0) return dist(p,S.a);
	if(sgn(dot(S.a-S.b,p-S.b))<=0) return dist(p,S.b);
	return abs(cross(S.b-S.a,p-S.a))/dist(S.a,S.b);
}

bool cover(const polygon& F,const point& p){
	int n=F.size();
	bool res=false;
	rep(i,n){
		point v1=F[i]-p,v2=F[(i+1)%n]-p;
		if(v1.y>v2.y) swap(v1,v2);
		if(sgn(v1.y)<=0 && sgn(v2.y)==1 && sgn(cross(v1,v2))==1) res=!res;
		if(sgn(cross(v1,v2))==0 && sgn(dot(v1,v2))<=0) return true;
	}
	return res;
}

polygon convex_hull(vector<point> P){
	int n=P.size();
	if(n<=1) return P;

	sort(P.begin(),P.end(),[](const point& p,const point& q){
		return make_pair(p.x,p.y)<make_pair(q.x,q.y);
	});

	polygon CH;
	rep(_,2){
		int m=0;
		vector<point> half(n);
		for(const point& p:P){
			half[m++]=p;
			while(m>=3 && ccw(half[m-3],half[m-2],half[m-1])!=CCW){
				half[m-2]=half[m-1];
				m--;
			}
		}
		CH.insert(CH.end(),half.begin(),half.begin()+m-1);
		reverse(P.begin(),P.end());
	}
	return CH;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<circle> C(n);
	vector<polygon> R(m);
	rep(i,n) scanf("%lf%lf%lf",&C[i].c.x,&C[i].c.y,&C[i].r);
	rep(j,m){
		double x,y,w,h; scanf("%lf%lf%lf%lf",&x,&y,&w,&h);
		R[j].emplace_back( x , y );
		R[j].emplace_back(x+w, y );
		R[j].emplace_back(x+w,y+h);
		R[j].emplace_back( x ,y+h);
	}

	vector<point> P;
	rep(j,m){
		bool ok=false;
		rep(k,4){
			rep(i,n){
				if(sgn(C[i].r-dist(segment(R[j][k],R[j][(k+1)%4]),C[i].c))>=0){
					ok=true;
				}
				else if(cover(R[j],C[i].c)){
					ok=true;
				}
			}
		}
		if(ok){
			rep(k,4) P.emplace_back(R[j][k]);
		}
	}

	auto H=convex_hull(P);
	double ans=0;
	rep(i,H.size()) ans+=dist(H[i],H[(i+1)%H.size()]);
	printf("%.9f\n",ans);

	return 0;
}

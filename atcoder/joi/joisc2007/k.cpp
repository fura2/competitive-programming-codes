// Day 4: Lines

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

bool intersect(const line& L1,const line& L2){
	return sgn(cross(L1.b-L1.a,L2.b-L2.a))!=0
		|| sgn(cross(L1.b-L1.a,L2.a-L1.a))==0;
}

point get_intersect(const line& L1,const line& L2){
	Real c1=cross(L1.b-L1.a,L2.b-L2.a);
	Real c2=cross(L1.b-L1.a,L1.b-L2.a);
	if(sgn(c1)==0) return L1.a;
	return L2.a+c2/c1*(L2.b-L2.a);
}

int main(){
	int n; scanf("%d",&n);
	vector<line> L(n);
	rep(i,n){
		int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
		L[i]={point(a,b),point(c,d)};
	}

	rep(i,n){
		bool ok=true;
		rep(j,i) if(L[i]==L[j]) ok=false;
		if(!ok){
			L.erase(L.begin()+i);
			i--;
			n--;
		}
	}

	int V;
	{
		vector<point> P;
		rep(i,n) for(int j=i+1;j<n;j++) {
			if(intersect(L[i],L[j])){
				P.emplace_back(get_intersect(L[i],L[j]));
			}
		}
		sort(P.begin(),P.end(),[](const auto& p,const auto& q){
			if(sgn(p.x-q.x)!=0) return sgn(q.x-p.x)==1;
			return sgn(q.y-p.y)==1;
		});
		P.erase(unique(P.begin(),P.end()),P.end());
		V=P.size()+2*n;
	}

	int E=2*n;
	rep(i,n){
		vector<point> P;
		rep(j,n) if(i!=j && intersect(L[i],L[j])) {
			P.emplace_back(get_intersect(L[i],L[j]));
		}
		sort(P.begin(),P.end(),[](const auto& p,const auto& q){
			if(sgn(p.x-q.x)!=0) return sgn(q.x-p.x)==1;
			return sgn(q.y-p.y)==1;
		});
		P.erase(unique(P.begin(),P.end()),P.end());
		E+=1+P.size();
	}

	printf("%d\n",E-V+1);

	return 0;
}

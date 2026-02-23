#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using Real=long long;

constexpr Real EPS=0;

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

using polygon=vector<point>;

enum{CCW=1,CW=-1,ON=0};
int ccw(const point& a,const point& b,const point& c){
	int d=sgn(cross(b-a,c-a));
	return d>0?CCW:d<0?CW:ON;
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
	int n; scanf("%d",&n);
	vector<point> P(n);
	rep(i,n) scanf("%lld%lld",&P[i].x,&P[i].y);

	auto CH=convex_hull(P);
	int m=CH.size();

	lint bdry=0; // 凸包の周上にある格子点の個数
	lint area2=0;
	rep(i,m){
		point p=CH[i],q=CH[(i+1)%m];
		bdry+=gcd(abs(p.x-q.x),abs(p.y-q.y));
		area2+=cross(p,q);
	}
	lint in=(area2-bdry)/2+1; // 凸包の内部にある格子点の個数

	printf("%lld\n",in+bdry-n);

	return 0;
}

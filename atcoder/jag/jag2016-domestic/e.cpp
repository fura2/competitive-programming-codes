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

enum{CCW=1,CW=-1,ON=0};
int ccw(const point& a,const point& b,const point& c){
	int d=sgn(cross(b-a,c-a));
	return d>0?CCW:d<0?CW:ON;
}

Real dist(const point& a,const point& b){ return abs(a-b); }

bool intersect(const line& L1,const line& L2){
	return sgn(cross(L1.b-L1.a,L2.b-L2.a))!=0
		|| sgn(cross(L1.b-L1.a,L2.a-L1.a))==0;
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

point get_intersect(const line& L1,const line& L2){
	Real c1=cross(L1.b-L1.a,L2.b-L2.a);
	Real c2=cross(L1.b-L1.a,L1.b-L2.a);
	if(sgn(c1)==0) return L1.a;
	return L2.a+c2/c1*(L2.b-L2.a);
}

bool cover(const segment& S,const point& p){
	return sgn(cross(S.a-p,S.b-p))==0 && sgn(dot(S.a-p,S.b-p))<=0;
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

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<polygon> F(n);
	rep(i,n){
		int l; scanf("%d",&l);
		F[i].resize(l);
		rep(k,l) scanf("%lf%lf",&F[i][k].x,&F[i][k].y);
	}
	vector<point> P(m);
	rep(j,m) scanf("%lf%lf",&P[j].x,&P[j].y);

	vector<line> L; // F の頂点と P の点を結ぶ直線の全体
	rep(i,n) rep(k,F[i].size()) {
		rep(j,m){
			L.emplace_back(F[i][k],P[j]);
		}
	}

	int ans=0;
	rep(i1,L.size()) for(int i2=i1+1;i2<L.size();i2++) {
		if(!intersect(L[i1],L[i2])) continue;
		point p=get_intersect(L[i1],L[i2]);

		// p がどの F[i] の内部にもないことをチェック
		bool ok=true;
		rep(i,n){
			bool bdry=false;
			rep(j,F[i].size()){
				if(cover(segment(F[i][j],F[i][(j+1)%F[i].size()]),p)){
					bdry=true;
					break;
				}
			}
			if(!bdry && cover(F[i],p)){
				ok=false;
				break;
			}
		}
		if(!ok) continue;

		int cnt=0;
		rep(j,m){
			segment S(p,P[j]);

			bool ok=true;
			rep(i,n){
				vector<point> I={S.a,S.b}; // 線分 S と F[i] の境界との交点の全体 (および S の端点)
				rep(k,F[i].size()){
					segment T(F[i][k],F[i][(k+1)%F[i].size()]);
					if(intersect(S,T)){
						I.emplace_back(get_intersect(S,T));
					}
				}
				sort(I.begin(),I.end(),[&](const point& p1,const point& p2){
					return dist(p1,p)<dist(p2,p);
				});
				I.erase(unique(I.begin(),I.end()),I.end());

				rep(k,int(I.size())-1){
					if(cover(F[i],(I[k]+I[k+1])/2)){
						ok=false;
						break;
					}
				}
				if(!ok) break;
			}
			if(ok) cnt++;
		}
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);

	return 0;
}

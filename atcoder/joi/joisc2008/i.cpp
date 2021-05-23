// Day 3: Nightman

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
	G[v].emplace_back(u,wt);
}

template<class T>
vector<T> Dijkstra(const weighted_graph<T>& G,int s){
	constexpr T INF=numeric_limits<T>::max();
	int n=G.size();
	vector<T> d(n,INF); d[s]=0;
	priority_queue<pair<T,int>> Q; Q.emplace(0,s);
	while(!Q.empty()){
		T d0=-Q.top().first;
		int u=Q.top().second; Q.pop();
		if(d0>d[u]) continue;
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt){
				d[v]=d[u]+e.wt;
				Q.emplace(-d[v],v);
			}
		}
	}
	return d;
}

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

enum{CCW=1,CW=-1,ON=0};
int ccw(const point& a,const point& b,const point& c){
	int d=sgn(cross(b-a,c-a));
	return d>0?CCW:d<0?CW:ON;
}

Real dist(const point& a,const point& b){ return abs(a-b); }

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

point get_intersect(const segment& S1,const segment& S2){
	Real c1=cross(S1.b-S1.a,S2.b-S2.a);
	Real c2=cross(S1.b-S1.a,S1.b-S2.a);
	if(sgn(c1)==0){
		if(cover(S1,S2.a)) return S2.a;
		if(cover(S1,S2.b)) return S2.b;
		if(cover(S2,S1.a)) return S1.a;
		return S1.b;
	}
	return S2.a+c2/c1*(S2.b-S2.a);
}

int main(){
	int n,m,l; scanf("%d%d%d%*d%*d",&n,&m,&l);
	vector<point> P(n),Q(l);
	rep(i,n) cin>>P[i].x>>P[i].y;
	vector<polygon> F(m);
	rep(j,m){
		int t,l,b,r; scanf("%d%d%d%d",&l,&b,&r,&t);
		F[j].emplace_back(l,t);
		F[j].emplace_back(l,b);
		F[j].emplace_back(r,b);
		F[j].emplace_back(r,t);
	}
	rep(k,l) cin>>Q[k].x>>Q[k].y;

	auto check=[&](segment S){ // 線分 S 上を移動できるかどうか
		vector<point> I;
		rep(j,m) rep(k,4) {
			segment T(F[j][k],F[j][(k+1)%4]);
			if(intersect(S,T)){
				I.emplace_back(get_intersect(S,T));
			}
		}
		sort(I.begin(),I.end(),[](const auto& p,const auto& q){
			if(sgn(q.x-p.x)!=0) return sgn(q.x-p.x)==1;
			return sgn(q.y-p.y)==1;
		});
		I.erase(unique(I.begin(),I.end()),I.end());

		rep(i,int(I.size())-1){
			point c=(I[i]+I[i+1])/2;
			// c が多角形の内部 (境界を含まない) に含まれるかどうか
			rep(j,m) if(cover(F[j],c)) {
				bool ok=false;
				rep(k,4) if(cover(segment(F[j][k],F[j][(k+1)%4]),c)) ok=true;
				if(!ok) return false;
			}
		}
		return true;
	};

	int N=n+4*m+l;
	weighted_graph<double> G(N);
	rep(i,n){
		rep(j,m) rep(k,4) if(check(segment(P[i],F[j][k]))) {
			add_undirected_edge(G,i,n+j*4+k,dist(P[i],F[j][k]));
		}
		rep(k,l) if(check(segment(P[i],Q[k]))) {
			add_undirected_edge(G,i,n+4*m+k,dist(P[i],Q[k]));
		}
	}
	rep(j1,m) rep(k1,4) {
		for(int j2=j1;j2<m;j2++) rep(k2,4) {
			if(j1<j2 || (j1==j2 && k1<k2)){
				if(check(segment(F[j1][k1],F[j2][k2]))){
					add_undirected_edge(G,n+j1*4+k1,n+j2*4+k2,dist(F[j1][k1],F[j2][k2]));
				}
			}
		}
		rep(k,l) if(check(segment(F[j1][k1],Q[k]))) {
			add_undirected_edge(G,n+j1*4+k1,n+4*m+k,dist(F[j1][k1],Q[k]));
		}
	}

	double ans=0;
	rep(k,l){
		auto d=Dijkstra(G,n+4*m+k);
		ans+=*min_element(d.begin(),d.begin()+n)*2;
	}
	printf("%.3f\n",ans);

	return 0;
}

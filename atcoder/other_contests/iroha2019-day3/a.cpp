#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class mint{
	static const int MOD=9973;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint& operator+=(const mint& m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint& operator-=(const mint& m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint& operator*=(const mint& m){ x=1LL*x*m.x%MOD; return *this; }
	mint& operator/=(const mint& m){ return *this*=inverse(m); }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }
	mint operator/(const mint& m)const{ return mint(*this)/=m; }
	mint operator-()const{ return mint(-x); }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint operator+(long long x,const mint& m){ return mint(x)+m; }
mint operator-(long long x,const mint& m){ return mint(x)-m; }
mint operator*(long long x,const mint& m){ return mint(x)*m; }
mint operator/(long long x,const mint& m){ return mint(x)/m; }

inline int popcount(unsigned int x){
	x-=(x>>1)&0x55555555;
	x=(x&0x33333333)+((x>>2)&0x33333333);
	return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;
}

int main(){
	int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z;

	string res1="zzzzzzzz";
	rep(S,1<<8) if(popcount(S)==j) {
		string tmp;
		rep(_,8) if(S>>_&1) tmp+="dagabaji"[_];
		res1=min(res1,tmp);
	}

	vector<lint> A;
	for(lint _=k;A.size()<m;_+=59){
		if(_%61==l) A.emplace_back(_);
	}
	lint res2=A.back();
	lint res3;
	for(lint _:{6LL,28LL,496LL,8128LL,33550336LL,8589869056LL,137438691328LL}){
		if(abs(_-res2)>=n){
			res3=_;
			break;
		}
	}

	cout<<a-b<<'\n';
	cout<<c+d<<'\n';
	cout<<max(f-e+1,0)<<'\n';
	cout<<(g+h+i)/3+1<<'\n';
	cout<<res1<<'\n';
	cout<<min(res2,res3)<<'\n';
	cout<<max(res2,res3)<<'\n';
	cout<<mint(o+p+q)*(r+s+t)*(u+v+w)*(x+y+z)<<'\n';

	return 0;
}

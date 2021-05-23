#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=1e9+7;
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

int f(int a,int b,int c){
	if(a==1 && b==1 && c==1) return 0;
	if(b==0 && c==0) return 0;
	return 1;
}

int n,a[2000],b[2000];

bool vis[2000][2][2];
mint memo[2000][2][2];

mint dfs(int i){
	if(i==n) return 1;

	if(vis[i][b[i-1]][b[i-2]]) return memo[i][b[i-1]][b[i-2]];
	vis[i][b[i-1]][b[i-2]]=true;

	mint res=0;
	rep(d,2){
		b[i]=d;
		if(f(b[i-2],b[i-1],b[i])==a[i-1]){
			bool ok=true;
			if(i==n-1){
				if(f(b[n-2],b[n-1],b[0])!=a[n-1]) ok=false;
				if(f(b[n-1],b[ 0 ],b[1])!=a[ 0 ]) ok=false;
			}
			if(ok) res+=dfs(i+1);
		}
	}
	return memo[i][b[i-1]][b[i-2]]=res;
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);

	mint ans=0;
	rep(S,1<<3){
		rep(i,3) b[i]=S>>i&1;
		if(a[1]!=f(b[0],b[1],b[2])) continue;

		rep(i,n) rep(j,2) rep(k,2) vis[i][j][k]=false;
		ans+=dfs(3);
	}
	cout<<ans<<'\n';

	return 0;
}

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
	mint& operator*=(const mint& m){ x=(long long)x*m.x%MOD; return *this; }
	mint& operator/=(const mint& m){ return *this*=inverse(m); }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }
	mint operator/(const mint& m)const{ return mint(*this)/=m; }
	mint operator-()const{ return -x; }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=t; return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint operator+(long long x,const mint& m){ return mint(x)+m; }
mint operator-(long long x,const mint& m){ return mint(x)-m; }
mint operator*(long long x,const mint& m){ return mint(x)*m; }
mint operator/(long long x,const mint& m){ return mint(x)/m; }

int h,w;
string B[24];

int f[1<<24];

bool vis[121393][2][25][25];
mint memo[121393][2][25][25];

mint dfs(int S,bool b,int i,int j){
	if(vis[f[S]][b][i][j]) return memo[f[S]][b][i][j];
	vis[f[S]][b][i][j]=true;
	mint& res=memo[f[S]][b][i][j];

	if(i==h) return res=1;
	if(j==w) return res=dfs(S,false,i+1,0);

	// (i, j) に置かない
	res=dfs(S&~(1<<j),S>>j&1,i,j+1);
	// (i, j) に置く
	if(B[i][j]=='.' && !b
	&& ~S>>j&1
	&& (j== 0  || ~S>>(j-1)&1)
	&& (j==w-1 || ~S>>(j+1)&1)){
		res+=dfs(S|(1<<j),S>>j&1,i,j+1);
	}
	return res;
}

int main(){
	cin>>h>>w;
	rep(i,h) cin>>B[i];

	int idx=0;
	rep(S,1<<w){
		bool ok=true;
		rep(j,w-1) if(S>>j&1 && S>>(j+1)&1) {
			ok=false;
			break;
		}
		if(ok) f[S]=idx++;
	}

	cout<<dfs(0,0,0,false)<<'\n';

	return 0;
}

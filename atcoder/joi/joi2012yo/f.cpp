#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=1e4;
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

int mod;
string s;
bool vis[502][2][500][10][3];
mint memo[502][2][500][10][3];

// up = 0: pre より大きくする, 1: 小さくする, 2: どちらでも
mint dfs(int i,bool smaller,int m,int pre,int up){
	if(vis[i][smaller][m][pre][up]) return memo[i][smaller][m][pre][up];
	vis[i][smaller][m][pre][up]=true;

	mint& res=memo[i][smaller][m][pre][up];
	if(i==s.length()){
		return res=(m==0?1:0);
	}

	if(up==2){ // leading zero
		res+=dfs(i+1,true,0,0,2);
	}

	int d_min=(up==0?pre+1:up==2?1:0);
	int d_max=(up==1?pre-1:9);
	for(int d=d_min;d<=d_max;d++){
		if(!smaller && d>s[i]-'0') continue;

		if(up!=2 || (up==2 && i+1==s.length())){
			res+=dfs(i+1,smaller||d<s[i]-'0',(10*m+d)%mod,d,up==0?1:0);
		}
		else{
			res+=dfs(i+1,smaller||d<s[i]-'0',(10*m+d)%mod,d,0);
			res+=dfs(i+1,smaller||d<s[i]-'0',(10*m+d)%mod,d,1);
		}
	}

	return res;
}

int main(){
	string a,b; cin>>a>>b>>mod;

	mint ans;
	s=b;
	rep(i,b.length()+1) rep(smaller,2) rep(m,mod) rep(pre,10) rep(up,3) {
		vis[i][smaller][m][pre][up]=false;
		memo[i][smaller][m][pre][up]=0;
	}
	ans+=dfs(0,false,0,0,2);
	s=a;
	rep(i,a.length()+1) rep(smaller,2) rep(m,mod) rep(pre,10) rep(up,3) {
		vis[i][smaller][m][pre][up]=false;
		memo[i][smaller][m][pre][up]=0;
	}
	ans-=dfs(0,false,0,0,2);

	bool ok=true;
	{
		int m=0;
		rep(i,a.length()) m=(10*m+a[i]-'0')%mod;
		if(m!=0) ok=false;
		rep(i,int(a.length())-1) if(a[i]==a[i+1]) ok=false;
		rep(i,int(a.length())-2){
			if(a[i]<a[i+1] && a[i+1]<a[i+2]) ok=false;
			if(a[i]>a[i+1] && a[i+1]>a[i+2]) ok=false;
		}
	}
	if(ok) ans+=1;

	cout<<ans<<'\n';

	return 0;
}

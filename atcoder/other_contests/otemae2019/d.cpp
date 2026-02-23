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

mint operator+(long long y,const mint& m){ return m+y; }
mint operator*(long long y,const mint& m){ return m*y; }

int n,m;
string s[1000];

bool memo1[1000][1001][15];
mint memo2[1000][1001][15];

mint dfs(int i,int j,int mod){
	if(i==n) return j==m?1:0;

	if(memo1[i][j][mod]) return memo2[i][j][mod];
	memo1[i][j][mod]=true;

	mint res=0;
	rep(d,10) if(!(i==0 && d==0)) {
		int mod2=(mod*10+d)%15;
		if(mod2==0){
			if(j<m && s[j]=="FizzBuzz") res+=dfs(i+1,j+1,mod2);
		}
		else if(mod2%3==0){
			if(j<m && s[j]=="Fizz") res+=dfs(i+1,j+1,mod2);
		}
		else if(mod2%5==0){
			if(j<m && s[j]=="Buzz") res+=dfs(i+1,j+1,mod2);
		}
		else{
			res+=dfs(i+1,j,mod2);
		}
	}
	return memo2[i][j][mod]=res;
}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,m) cin>>s[i];

	cout<<dfs(0,0,0)<<'\n';

	return 0;
}

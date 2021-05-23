#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=1e9+7;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint &operator+=(const mint &m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint &operator-=(const mint &m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint &operator*=(const mint &m){ x=1LL*x*m.x%MOD; return *this; }
	mint &operator/=(const mint &m){ return *this*=m.inverse(); }
	mint operator+(const mint &m)const{ return mint(*this)+=m; }
	mint operator-(const mint &m)const{ return mint(*this)-=m; }
	mint operator*(const mint &m)const{ return mint(*this)*=m; }
	mint operator/(const mint &m)const{ return mint(*this)/=m; }

	friend ostream &operator<<(ostream &os,const mint &m){ return os<<m.x; }

	mint inverse()const{
		int a=x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}
};

vector<int> tmp;
void partition(int a,int mx,vector<vector<int>> &P){
	if(a==0){
		P.emplace_back(tmp);
		return;
	}
	for(int i=mx;i>0;i--){
		tmp.emplace_back(i);
		if(a-i>=0) partition(a-i,i,P);
		tmp.pop_back();
	}
}

mint fact[301],finv[301];

mint multi(const vector<int> &a){
	mint res=1;
	int sum=0;
	for(int x:a) res*=finv[x], sum+=x;
	return res*fact[sum];
}

mint binom(int n,int r){ return n-r<0?0:multi({r,n-r}); }

int main(){
	fact[0]=finv[0]=1;
	rep(i,300){
		fact[i+1]=fact[i]*(i+1);
		finv[i+1]=finv[i]/(i+1);
	}

	// dp[i][j] := ( i 種類目の文字まで挿入して, 同じ文字が隣り合う箇所が j 箇所あるような文字列の個数 )
	mint dp[27][300];
	dp[0][0]=1;
	int len=0;
	rep(i,26){
		int a; cin>>a;
		vector<vector<int>> P;
		partition(a,a,P);

		for(auto p:P){
			int m=p.size(),cons=0;
			vector<int> hist(a);
			for(int x:p){
				cons+=x-1;
				hist[x-1]++;
			}
			rep(j,len+1) rep(k,min(j,m)+1) {
				dp[i+1][j-k+cons]+=dp[i][j]*binom(j,k)*binom(len+1-j,m-k)*multi(hist);
			}
		}

		len+=a;
	}

	cout<<dp[26][0]<<endl;

	return 0;
}

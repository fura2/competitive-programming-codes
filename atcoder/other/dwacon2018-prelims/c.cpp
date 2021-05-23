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

mint solve(int total,vector<int> v){
	int n=v.size();
	int mx=*max_element(v.begin(),v.end());
	vector memo2(mx+1,vector(total+1,mint(0)));
	vector vis2(mx+1,vector(total+1,false));

	auto dfs2=[&](auto&& dfs2,int len,int k){
		if(vis2[len][k]) return memo2[len][k];
		vis2[len][k]=true;

		mint& res=memo2[len][k];
		if(len==0){
			return res=(k==0?1:0);
		}

		res=dfs2(dfs2,len-1,k);
		if(k>=len){
			res+=dfs2(dfs2,len,k-len);
		}
		return res;
	};

	vector memo1(n+1,vector(total+1,mint(0)));
	vector vis1(n+1,vector(total+1,false));

	auto dfs1=[&](auto&& dfs1,int i,int k){
		if(vis1[i][k]) return memo1[i][k];
		vis1[i][k]=true;

		mint& res=memo1[i][k];
		if(i==n){
			return res=(k==0?1:0);
		}

		res=0;
		rep(j,k+1){
			res+=dfs1(dfs1,i+1,k-j)*dfs2(dfs2,v[i],j);
		}
		return res;
	};

	return dfs1(dfs1,0,total);
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n),b(m);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,m) scanf("%d",&b[i]);

	auto f=[](vector<int> x){
		vector<int> v;
		int pre=0;
		for(int i=1;i<=x.size();i++) if(i==x.size() || x[i]!=x[pre]) {
			v.emplace_back(i-pre);
			pre=i;
		}
		return v;
	};

	cout<<solve(accumulate(a.begin(),a.end(),0),f(b))
		 *solve(accumulate(b.begin(),b.end(),0),f(a))<<'\n';

	return 0;
}

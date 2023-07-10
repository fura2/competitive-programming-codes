#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class mint{
	static const int MOD=998244353;
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

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> x(m),y(m),c(m);
	map<pair<int,int>,int> C;
	rep(i,m){
		scanf("%d%d%d",&y[i],&x[i],&c[i]); y[i]--; x[i]--;
		if(C.count({y[i],x[i]})>0){
			if(C[{y[i],x[i]}]!=c[i]) return puts("0"),0;
		}
		else{
			C[{y[i],x[i]}]=c[i];
			if(abs(x[i]-y[i])>2) C[{x[i],y[i]}]=c[i];
		}
	}

	lint cnt=(n-3LL)*(n-2);
	for(auto p:C){
		int y,x; tie(y,x)=p.first;
		if(abs(x-y)>2) cnt--;
	}
	cnt/=2;

	// dp[i][c] = 対角線から距離 2 以内のマスについて, 対角線上のマスの色を左上から右下にかけて決めていくとき,
	//            マス (i, i) まで決めて, その色が c であるような場合の数
	mint dp[100001][2];
	if(C.count({0,0})>0) dp[0][C[{0,0}]]=1;
	else                 dp[0][0]=dp[0][1]=1;
	for(int i=1;i<n;i++){
		int c0=-1,c1=-1,c2=-1,c3=-1,c4=-1;
		if(C.count({i,i})>0)   c0=C[{i,i}];
		if(C.count({i-1,i})>0) c1=C[{i-1,i}];
		if(C.count({i,i-1})>0) c2=C[{i,i-1}];
		if(i==1) c3=0;
		else if(C.count({i-2,i})>0) c3=C[{i-2,i}];
		if(i==1) c4=0;
		else if(C.count({i,i-2})>0) c4=C[{i,i-2}];

		rep(j0,2) if(c0==-1 || c0==j0) {
			rep(j1,2) if(c1==-1 || c1==j1) {
				rep(j2,2) if(c2==-1 || c2==j2) {
					rep(j3,2) if(c3==-1 || c3==j3) {
						int j4=((j0+j1+j2)%2==0?j3:1-j3);
						if(i==1 || c4==-1 || c4==j4){
							dp[i][j0]+=dp[i-1][(j0+j1+j2)%2];
						}
					}
				}
			}
		}
	}
	cout<<(dp[n-1][0]+dp[n-1][1])*pow(mint(2),cnt)<<'\n';

	return 0;
}

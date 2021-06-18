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

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	auto is_in_grid=[&](int x,int y){
		return 0<=x && x<h && 0<=y && y<w;
	};

	mint half=mint(1)/2;

	mint dp[600][300][300];
	dp[0][0][0]=1;
	rep(i,h+w-2){
		rep(j,h){
			int x1=j,y1=i-j;
			if(!is_in_grid(x1,y1)) continue;

			rep(k,h){
				int x2=k,y2=i-k;
				if(!is_in_grid(x2,y2)) continue;

				for(int d1:{0,3}){
					int xx1=x1+dx[d1],yy1=y1+dy[d1];
					if(!is_in_grid(xx1,yy1)) continue;

					for(int d2:{0,3}){
						int xx2=x2+dx[d2],yy2=y2+dy[d2];
						if(!is_in_grid(xx2,yy2) || B[xx1][yy1]!=B[xx2][yy2]) continue;

						mint p;
						if(x1==h-1 || y1==w-1) p=1;
						else                   p=half;

						int i2=i+1,j2=xx1,k2=xx2;
						dp[i2][j2][k2]+=dp[i][j][k]*p;
					}
				}
			}
		}
	}
	cout<<dp[h+w-2][h-1][h-1]*pow(mint(2),h+w)<<'\n';

	return 0;
}

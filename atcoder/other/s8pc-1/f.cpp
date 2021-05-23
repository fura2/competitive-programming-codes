#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=1e4;
class mint{
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

string a,b;
int c,d;

int n,ten[100];

bool vis[41][50][721][2][2];
mint memo[41][50][721][2][2];

mint dfs(int i,int x,int y,bool larger,bool smaller){ // 何桁目, mod c, 桁和, a より大きいか, b より小さいか
	mint& res=memo[i][x][y][larger][smaller];
	if(vis[i][x][y][larger][smaller]) return res;
	vis[i][x][y][larger][smaller]=true;

	if(i==n/2){
		if(x!=0 || y<d) return res=0;
		if(larger && smaller) return res=1;
		bool ok=true;
		if(!larger){
			rep(i,n/2){
				if(a[n/2-i-1]<a[n/2+i]){
					ok=false;
					break;
				}
				else if(a[n/2-i-1]>a[n/2+i]){
					break;
				}
			}
		}
		if(!smaller){
			rep(i,n/2){
				if(b[n/2-i-1]>b[n/2+i]){
					ok=false;
					break;
				}
				else if(b[n/2-i-1]<b[n/2+i]){
					break;
				}
			}
		}
		return res=ok;
	}

	res=0;
	rep(j,10){
		if(!larger  && j<a[i]-'0') continue;
		if(!smaller && j>b[i]-'0') continue;
		if(y+2*j<=d){
			res+=dfs(i+1,(x+j*ten[n-i-1]+j*ten[i])%c,y+2*j,larger||j>a[i]-'0',smaller||j<b[i]-'0');
		}
	}
	return res;
}

int main(){
	cin>>a>>b>>c>>d;
	n=a.length();

	ten[0]=1%c;
	rep(i,n-1) ten[i+1]=ten[i]*10%c;

	cout<<dfs(0,0,0,false,false)<<'\n';

	return 0;
}

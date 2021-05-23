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

int main(){
	int h,w; scanf("%d%d",&h,&w);
	vector B(h,vector(w,0));
	set<pair<int,int>> Z;
	vector<int> zrow(h),zcol(w);
	rep(i,h) rep(j,w) {
		scanf("%d",&B[i][j]);
		if(B[i][j]==0){
			B[i][j]=1;
			Z.emplace(i,j);
			zrow[i]++;
			zcol[j]++;
		}
	}

	mint prod=1;
	vector<mint> R(h,1),C(w,1);
	rep(i,h) rep(j,w) {
		prod*=B[i][j];
		R[i]*=B[i][j];
		C[j]*=B[i][j];
	}

	int q; scanf("%d",&q);
	rep(_,q){
		int i,j; scanf("%d%d",&i,&j); i--; j--;

		if(zrow[i]+zcol[j]-int(Z.count({i,j}))==Z.size()){
			printf("%d\n",(prod/(R[i]*C[j])*B[i][j]).to_int());
		}
		else{
			puts("0");
		}
	}

	return 0;
}

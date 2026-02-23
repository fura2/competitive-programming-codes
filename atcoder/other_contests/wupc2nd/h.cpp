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

template<class T> struct interval{
	T l,r;
	interval(){}
	interval(const T& l,const T& r):l(l),r(r){}
	bool operator<(const interval& I)const{ return make_tuple(l,r)<make_tuple(I.l,I.r); }
};

int main(){
	int L,n; scanf("%d%d",&L,&n);
	vector<interval<int>> I(n);
	rep(i,n) scanf("%d%d",&I[i].l,&I[i].r), I[i].l--;

	vector<int> X={L};
	rep(i,n){
		X.emplace_back(I[i].l);
		X.emplace_back(I[i].r);
	}
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());

	rep(i,n){
		I[i].l=lower_bound(X.begin(),X.end(),I[i].l)-X.begin();
		I[i].r=lower_bound(X.begin(),X.end(),I[i].r)-X.begin();
	}
	L=lower_bound(X.begin(),X.end(),L)-X.begin();

	sort(I.begin(),I.end());

	// dp[i][j] = ([0, i) を 2 個以上の区間で, [i, j) を 1 個の区間で,
	//             [j, L) を 0 個の区間で覆うような場合の数)
	vector dp(L+1,vector(L+1,mint(0)));
	dp[0][0]=1;
	for(auto J:I){
		auto next=dp;
		for(int i=J.l;i<=L;i++){
			for(int j=i;j<=L;j++){
				next[max(min(J.r,j),i)][max(J.r,j)]+=dp[i][j];
			}
		}
		dp=next;
	}
	cout<<dp[L][L]<<'\n';

	return 0;
}

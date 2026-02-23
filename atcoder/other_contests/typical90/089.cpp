#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(int n=0){ build(n); }
	Fenwick_tree(const vector<G>& a){ build(a); }
	void build(int n){
		a.assign(n,G{});
	}
	void build(const vector<G>& a){
		this->a=a;
		for(int i=1;i<=a.size();i++) if(i+(i&-i)<=a.size()) (this->a)[i+(i&-i)-1]+=(this->a)[i-1];
	}
	void add(int i,const G& val){
		for(i++;i<=a.size();i+=i&-i) a[i-1]+=val;
	}
	G sum(int l,int r)const{
		if(l==0){
			G res{};
			for(;r>0;r-=r&-r) res+=a[r-1];
			return res;
		}
		return sum(0,r)-sum(0,l);
	}
	int lower_bound(G val)const{
		if(!(G{}<val)) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<val) val-=a[x+k-1], x+=k;
		return x;
	}
	int upper_bound(G val)const{
		if(val<G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && !(val<a[x+k-1])) val-=a[x+k-1], x+=k;
		return x;
	}
};

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

int main(){
	int n;
	lint k; cin>>n>>k;
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	auto X=a;
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	rep(i,n) a[i]=lower_bound(X.begin(),X.end(),a[i])-X.begin();
	int m=X.size();

	vector<int> pos(n); // pos[l] = maximum r s.t. (inversion number of a[l,r)) <= k
	{
		Fenwick_tree<int> F(m);
		lint cnt=0;
		for(int l=0,r=0;l<n;l++){
			while(r<n){
				int val=F.sum(a[r]+1,m);
				if(cnt+val>k) break;
				cnt+=val;
				F.add(a[r],1);
				r++;
			}
			pos[l]=r;
			cnt-=F.sum(0,a[l]);
			F.add(a[l],-1);
		}
	}

	// naive O(n^2) DP
	/*
	vector<mint> dp(n+1);
	dp[n]=1;
	for(int i=n-1;i>=0;i--){
		for(int j=i+1;j<=pos[i];j++){
			dp[i]+=dp[j];
		}
	}
	cout<<dp[0]<<'\n';
	*/
	vector<mint> dp(n+2);
	dp[n]=1;
	for(int i=n-1;i>=0;i--){
		dp[i]=2*dp[i+1]-dp[pos[i]+1];
	}
	cout<<dp[0]-dp[1]<<'\n';

	return 0;
}

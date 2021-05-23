#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int MOD;
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

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

int main(){
	int n,q; scanf("%d%d%d",&n,&q,&MOD);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	static vector<int> Pos[1000001];
	rep(x,n) Pos[a[x]].emplace_back(x);

	static vector<mint> power[1000001]; // power[a][k] = a^k
	rep(x,n){
		if(power[a[x]].empty()) power[a[x]].emplace_back(1);
		power[a[x]].emplace_back(power[a[x]].back()*a[x]);
	}

	const int L=sqrt(n)/2+1; // length of a bucket
	int m=n/L; // number of buckets

	static mint hash[700][700];
	{
		static int freq[1000001];
		rep(i,m){
			mint h=0;
			for(int x=i*L;x<n;x++){
				freq[a[x]]++;
				h+=power[a[x]][freq[a[x]]];
				if(x%L==L-1) hash[i][(x+1)/L]=h;
			}
			for(int x=i*L;x<n;x++){
				freq[a[x]]=0; // reset
			}
		}
	}

	vector<vector<int>::iterator> a_pos(n); // a_pos[x] = Pos[a[x]] における x の位置 (定数倍高速化のために前計算)
	rep(x,n) a_pos[x]=lower_bound(Pos[a[x]].begin(),Pos[a[x]].end(),x);

	rep(_,q){
		int l,r; scanf("%d%d",&l,&r); l--;
		int i=(l+L-1)/L,j=r/L;

		mint res;
		if(j-i==-1){
			for(int x=l;x<r;x++){
				int k=a_pos[x]-lower_bound(Pos[a[x]].begin(),Pos[a[x]].end(),l)+1;
				res+=power[a[x]][k];
			}
		}
		else{
			res=hash[i][j];
			for(int x=l;x<i*L;x++){
				int k=lower_bound(Pos[a[x]].begin(),Pos[a[x]].end(),j*L)-a_pos[x];
				res+=power[a[x]][k];
			}
			for(int x=j*L;x<r;x++){
				int k=a_pos[x]-lower_bound(Pos[a[x]].begin(),Pos[a[x]].end(),l)+1;
				res+=power[a[x]][k];
			}
		}
		printf("%d\n",res.to_int());
	}

	return 0;
}

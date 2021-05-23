#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }

template<class T>
class sparse_table{
	vector<vector<T>> st;
	vector<int> h;
public:
	sparse_table(const vector<T>& a){
		int n=a.size();
		h.assign(n+1,0);
		for(int i=2;i<=n;i++) h[i]=h[i>>1]+1;
		st.resize(h[n]+1);
		st[0]=a;
		for(int i=1;i<h[n]+1;i++){
			st[i].resize(n-(1<<i)+1);
			rep(j,n-(1<<i)+1) st[i][j]=gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
	T query(int l,int r)const{
		int i=h[r-l];
		return gcd(st[i][l],st[i][r-(1<<i)]);
	}
};

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	sparse_table<lint> ST(a);

	lint ans=0;
	rep(i,n) if(ST.query(i,n)==1) {
		if(a[i]==1){
			ans+=n-i;
			continue;
		}

		int lo=i+1,hi=n;
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			if(ST.query(i,mi)==1) hi=mi;
			else                  lo=mi;
		}
		ans+=n-hi+1;
	}
	printf("%lld\n",ans);

	return 0;
}

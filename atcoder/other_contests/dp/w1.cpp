// O(n^2 log n) solution (TLE)

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(int n):a(n){}
	void add(int i,G val){
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
		if(val<=G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<val) val-=a[x+k-1], x+=k;
		return x;
	}
	int upper_bound(G val)const{
		if(val<G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<=val) val-=a[x+k-1], x+=k;
		return x;
	}
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> l(m),r(m),val(m);
	rep(i,m) scanf("%d%d%d",&l[i],&r[i],&val[i]), l[i]--;

	vector<vector<int>> L(n),R(n+1);
	rep(i,m){
		L[l[i]].emplace_back(i);
		R[r[i]].emplace_back(i);
	}

	Fenwick_tree<lint> F(n);

	lint dp[200000]; // dp[x] = (文字列を x 文字目まで決めて, x 文字目を 1 にしたときの最大スコア)
	rep(x,n){
		for(int idx:R[x]){
			F.add(l[idx],-val[idx]);
		}
		for(int idx:L[x]){
			F.add(l[idx],val[idx]);
		}

		dp[x]=F.sum(0,n);
		rep(y,x){
			dp[x]=max(dp[x],dp[y]+F.sum(y+1,n));
		}
	}

rep(x,n) printf("dp[%d] = %lld\n",x,dp[x]);
	printf("%lld\n",max(*max_element(dp,dp+n),0LL));

	return 0;
}

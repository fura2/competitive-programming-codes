#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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
			rep(j,n-(1<<i)+1) st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
	T query(int l,int r)const{
		int i=h[r-l];
		return min(st[i][l],st[i][r-(1<<i)]);
	}
};

int main(){
	lint n,k,d; scanf("%lld%lld%lld",&n,&k,&d);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	if(n<1+(k-1)*d) return puts("-1"),0;

	map<int,vector<int>> f;
	rep(i,n) f[a[i]].emplace_back(i);

	sparse_table<int> ST(a);

	int pre=-d;
	rep(i,k){
		int mn=ST.query(pre+d,n-(k-1-i)*d);
		const auto& v=f[mn];
		int idx=*lower_bound(v.begin(),v.end(),pre+d);
		printf("%d%c",a[idx],i<k-1?' ':'\n');
		pre=idx;
	}

	return 0;
}

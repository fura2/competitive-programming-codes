#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
			rep(j,n-(1<<i)+1) st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
	T query(int l,int r)const{
		int i=h[r-l];
		return max(st[i][l],st[i][r-(1<<i)]);
	}
};

int main(){
	int n; scanf("%d",&n);
	vector<int> l(n),r(n),sum(1e5+2);
	rep(i,n){
		scanf("%d%d",&l[i],&r[i]);
		sum[l[i]]++;
		sum[r[i]]--;
	}
	rep(x,1e5) sum[x+1]+=sum[x];

	sparse_table<int> ST(sum);

	int ans=n;
	rep(i,n){
		ans=min(ans,max({ST.query(0,l[i]),ST.query(l[i],r[i])-1,ST.query(r[i],1e5+1)}));
	}
	printf("%d\n",ans);

	return 0;
}

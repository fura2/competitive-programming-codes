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
	while(1){
		int n,k; scanf("%d%d",&n,&k);
		if(n==-1 && k==-1) break;

		vector<lint> a(n);
		rep(i,n) scanf("%lld",&a[i]);

		bool ok=true;
		sparse_table<lint> ST(a);
		rep(i,n-k-1) if(a[i]>ST.query(i+k+1,n)) {
			ok=false;
		}
		puts(ok?"Yes":"No");
	}

	return 0;
}

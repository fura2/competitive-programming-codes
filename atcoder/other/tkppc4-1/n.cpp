#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const int INF=1<<29;

vector<long long> prime_factors(long long a){
	vector<long long> res;
	if(a%2==0){
		do a/=2; while(a%2==0);
		res.emplace_back(2);
	}
	for(long long p=3;p*p<=a;p+=2) if(a%p==0) {
		do a/=p; while(a%p==0);
		res.emplace_back(p);
	}
	if(a>1) res.emplace_back(a);
	sort(res.begin(),res.end());
	return res;
}

int main(){
	int n,d; scanf("%d%d",&n,&d);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	auto P=prime_factors(d);
	int m=P.size();
	vector<int> D(m);
	{
		int tmp=d;
		rep(j,m) while(tmp%P[j]==0) D[j]++, tmp/=P[j];
	}
	vector<vector<int>> A(n,vector<int>(m));
	rep(i,n){
		int tmp=a[i];
		rep(j,m) while(tmp%P[j]==0) A[i][j]++, tmp/=P[j];
	}

	vector<int> pos(n,INF);
	vector<int> mul(m);
	for(int l=0,r=0;l<n;l++){
		while(1){
			bool ok=(l<r);
			rep(j,m) if(mul[j]<D[j]) ok=false;
			if(ok) pos[l]=r;
			if(ok || r==n) break;

			rep(j,m) mul[j]+=A[r][j];
			r++;
		}

		rep(j,m) mul[j]-=A[l][j];
	}

	map<int,vector<int>> f;
	int sum=0;
	rep(i,n+1){
		f[sum].emplace_back(i);
		if(i<n) sum=(sum+a[i])%d;
	}

	lint ans=0;
	for(auto q:f){
		const auto& v=q.second;
		rep(i,v.size()) if(v[i]<n) {
			ans+=v.end()-lower_bound(v.begin(),v.end(),pos[v[i]]);
		}
	}
	printf("%lld\n",ans);

	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; cin>>n>>k;
	vector<int> a(n),b(n);
	rep(i,n) cin>>a[i]>>b[i];

	priority_queue<pair<long long,int>> Q;
	rep(i,n){
		Q.emplace(-a[i],i);
	}

	long long ans=0;
	rep(_,k){
		auto x=Q.top(); Q.pop();
		long long t=-x.first;
		int i=x.second;
		ans+=t;
		Q.emplace(-(t+b[i]),i);
	}
	cout<<ans<<endl;

	return 0;
}

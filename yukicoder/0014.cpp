#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

vector<int> divisors(int a){
	vector<int> res;
	for(int i=1;i*i<=a;i++) if(a%i==0) {
		res.emplace_back(i);
		if(i*i<a) res.emplace_back(a/i);
	}
	sort(res.begin(),res.end());
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> D[10001];
	multiset<int> S[10001];
	rep(i,n){
		if(D[a[i]].empty()) D[a[i]]=divisors(a[i]);
		for(auto d:D[a[i]]) S[d].emplace(a[i]);
	}

	vector<int> ans(n);
	int next=a[0];
	rep(i,n){
		ans[i]=next;
		for(auto d:D[next]) S[d].erase(S[d].find(next));

		int tmp=INF;
		for(auto d:D[next]) if(!S[d].empty()) {
			tie(tmp,next)=min(make_pair(tmp,next),make_pair(*S[d].begin()/d,*S[d].begin()));
		}
	}

	rep(i,n) printf("%d%c",ans[i],i<n-1?' ':'\n');

	return 0;
}

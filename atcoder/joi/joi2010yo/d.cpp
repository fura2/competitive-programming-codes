#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; cin>>n>>k;
	vector<string> s(n);
	rep(i,n) cin>>s[i];

	set<string> ans;
	rep(S,1<<n){
		vector<int> I;
		rep(i,n) if(S>>i&1) I.emplace_back(i);
		if(I.size()!=k) continue;

		vector<int> p(k);
		iota(p.begin(),p.end(),0);
		do{
			string t;
			rep(i,k) t+=s[I[p[i]]];
			ans.emplace(t);
		}while(next_permutation(p.begin(),p.end()));
	}
	cout<<ans.size()<<'\n';

	return 0;
}

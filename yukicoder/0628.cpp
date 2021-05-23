#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	map<string,int> f;
	rep(i,n){
		scanf("%*d");
		int m,p; scanf("%d%d",&m,&p);
		rep(j,m){
			string s; cin>>s;
			f[s]+=p;
		}
	}

	vector<pair<int,string>> v;
	for(auto p:f) v.emplace_back(-p.second,p.first);
	sort(v.begin(),v.end());

	rep(i,min(int(v.size()),10)){
		cout<<v[i].second<<' '<<-v[i].first<<'\n';
	}

	return 0;
}

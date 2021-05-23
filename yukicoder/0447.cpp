#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<int> star(n);
	rep(i,n) cin>>star[i];

	map<string,pair<int,int>> sum;
	vector<map<string,int>> score(n);
	vector<int> cnt(n,1);
	int q; cin>>q;
	rep(t,q){
		string s;
		char c; cin>>s>>c;
		int id=c-'A';
		score[id][s]=50*star[id]+50*star[id]/(0.8+0.2*cnt[id]);
		sum[s].first+=score[id][s];
		sum[s].second=t;
		cnt[id]++;
	}

	map<pair<int,int>,string> f;
	for(auto p:sum) f[{-p.second.first,p.second.second}]=p.first;

	int i=0;
	for(auto p:f){
		cout<<i+1<<' '<<p.second;
		rep(i,n) cout<<' '<<score[i][p.second];
		cout<<' '<<sum[p.second].first<<'\n';
		i++;
	}

	return 0;
}

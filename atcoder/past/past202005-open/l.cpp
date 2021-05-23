#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<vector<int>> a(n);
	rep(i,n){
		int k; scanf("%d",&k);
		a[i].resize(k);
		rep(j,k) scanf("%d",&a[i][j]);
	}

	set<pair<int,int>,greater<pair<int,int>>> S1,S2;
	rep(i,n){
		S1.emplace(a[i][0],i);
		if(a[i].size()>=2) S2.emplace(a[i][1],i);
	}

	vector<int> idx(n);

	int m; scanf("%d",&m);
	rep(_,m){
		int t; scanf("%d",&t);
		if(t==2 && !S2.empty() && (S1.begin()->first)<(S2.begin()->first)){
			auto p=*S2.begin();
			int i=p.second;
			printf("%d\n",p.first);
			S2.erase({a[i][idx[i]+1],i});
			if(idx[i]+2<a[i].size()){
				S2.emplace(a[i][idx[i]+2],i);
			}
			swap(a[i][idx[i]],a[i][idx[i]+1]);
			idx[i]++;
		}
		else{
			auto p=*S1.begin();
			int i=p.second;
			printf("%d\n",p.first);
			S1.erase({a[i][idx[i]],i});
			if(idx[i]+1<a[i].size()){
				S1.emplace(a[i][idx[i]+1],i);
				S2.erase({a[i][idx[i]+1],i});
			}
			if(idx[i]+2<a[i].size()){
				S2.emplace(a[i][idx[i]+2],i);
			}
			idx[i]++;
		}
	}

	return 0;
}

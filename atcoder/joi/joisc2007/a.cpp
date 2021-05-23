// Day 1: Score

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<pair<int,int>> p(n);
	rep(i,n) scanf("%d",&p[i].first), p[i].second=i;

	sort(p.rbegin(),p.rend());

	vector<int> res(n);
	rep(i,n){
		if(i==0 || p[i-1].first>p[i].first) res[i]=i+1;
		else res[i]=res[i-1];
	}
	rep(i,n) p[i].first=res[i];

	sort(p.begin(),p.end(),[](pair<int,int> a,pair<int,int> b){ return a.second<b.second; });

	rep(i,n) printf("%d\n",p[i].first);

	return 0;
}

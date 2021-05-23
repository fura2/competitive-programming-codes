#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int solve1(vector<int> a){
	int n=a.size();

	int res=0,pre=0;
	for(int i=1;i<=n;i++){
		if(i==n || a[i-1]+1!=a[i]){
			res=max(res,i-pre);
			pre=i;
		}
	}
	return res;
}

int solve2(vector<int> a){
	int n=a.size();

	vector<pair<int,int>> p;
	int pre=0;
	for(int i=1;i<=n;i++){
		if(i==n || a[i-1]+1!=a[i]){
			p.emplace_back(a[pre],a[i-1]);
			pre=i;
		}
	}

	int res=0;
	for(auto [l,r]:p) res=max(res,r-l+1);
	if(p.size()>=2){
		rep(i,p.size()-1) if(p[i].second+2==p[i+1].first) {
			res=max(res,p[i+1].second-p[i].first+1);
		}
	}
	return res;
}

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(k);
	rep(i,k) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	int ans;
	if(a[0]!=0){
		ans=solve1(a);
	}
	else{
		a.erase(a.begin());
		ans=solve2(a);
	}
	printf("%d\n",ans);

	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	int ans=n;
	rep(t,n){
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
		rep(i,n) Q.emplace(a[i],0);
		rep(i,n){
			auto p=Q.top(); Q.pop();
			Q.emplace(p.first+b[(i+t)%n]/2,p.second+1);
		}

		int res=0;
		while(!Q.empty()) res=max(res,Q.top().second), Q.pop();
		ans=min(ans,res);
	}
	printf("%d\n",ans);

	return 0;
}

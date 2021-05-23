#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=INF;
	set<int> L={a[0]},R(a.begin()+1,a.end());
	for(int i=1;i<n-1;i++){
		R.erase(a[i]);

		auto itl=L.lower_bound(a[i]);
		auto itr=R.lower_bound(a[i]);
		if(itl!=L.end()   && itr!=R.end()  ) ans=min(ans,a[i]+*itl+*itr);
		if(itl!=L.begin() && itr!=R.begin()) ans=min(ans,a[i]+*L.begin()+*R.begin());

		L.emplace(a[i]);
	}
	printf("%d\n",ans<INF?ans:-1);

	return 0;
}

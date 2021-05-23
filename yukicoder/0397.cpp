#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<pair<int,int>> ans;
	rep(i,n){
		int k=i;
		for(int j=i+1;j<n;j++) if(a[j]<a[k]) k=j;
		if(k!=i){
			swap(a[i],a[k]);
			ans.emplace_back(i,k);
		}
	}

	printf("%lu\n",ans.size());
	for(auto p:ans) printf("%d %d\n",p.first,p.second);
	fflush(stdout);

	return 0;
}

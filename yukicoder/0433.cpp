#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<vector<tuple<int,int,int>>> a(11);
	rep(i,n){
		int x,p,u; scanf("%d%d%d",&x,&p,&u); u--;
		a[x].emplace_back(u,p,i);
	}

	vector<int> cnt(100000);
	for(int x=10;x>=0;x--){
		sort(a[x].begin(),a[x].end(),[](auto p,auto q){
			return get<1>(p)<get<1>(q);
		});
		for(auto& t:a[x]) get<0>(t)=cnt[get<0>(t)]++;
		sort(a[x].begin(),a[x].end());
		for(auto t:a[x]) if(k>0) {
			printf("%d\n",get<2>(t));
			k--;
		}
	}

	return 0;
}

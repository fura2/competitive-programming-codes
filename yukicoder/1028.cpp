#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<pair<int,int>> P[1000];
	rep(i,n) rep(j,n) {
		int a; scanf("%d",&a); a--;
		P[a].emplace_back(i,j);
	}

	auto calc=[&](int a,int i){
		int cost=0;
		for(const auto& p:P[a]) cost+=max(abs(p.first-i),p.second);
		return cost;
	};

	int ans=0;
	rep(a,n){
		int lo=0,hi=n;
		while(hi-lo>2){
			int mi1=(2*lo+hi)/3;
			int mi2=(lo+2*hi)/3;

			int cost1=calc(a,mi1);
			int cost2=calc(a,mi2);
			if(cost1<=cost2) hi=mi2;
			else             lo=mi1;
		}
		int res=INF;
		for(int i=lo;i<hi;i++) res=min(res,calc(a,i));
		ans+=res;
	}
	printf("%d\n",ans);

	return 0;
}

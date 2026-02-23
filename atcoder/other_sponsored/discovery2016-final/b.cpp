#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x; scanf("%d%d",&n,&x);
	vector<pair<int,int>> p(n);
	rep(i,n) scanf("%d",&p[i].first);
	rep(i,n) scanf("%d",&p[i].second);

	sort(p.begin(),p.end());

	auto check=[&](int th){
		int sum=0;
		priority_queue<int,vector<int>,greater<>> Q;
		for(auto [t,a]:p){
			if(Q.size()<min(t,th)){
				sum+=a;
				Q.emplace(a);
			}
			else{
				if(Q.top()<a){
				sum-=Q.top();
					sum+=a;
					Q.pop();
					Q.emplace(a);
				}
			}
			if(sum>=x) return true;
		}
		return false;
	};

	if(!check(1e5)){
		puts("-1");
	}
	else{
		int lo=0,hi=1e5;
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			if(check(mi)) hi=mi;
			else          lo=mi;
		}
		printf("%d\n",hi);
	}

	return 0;
}

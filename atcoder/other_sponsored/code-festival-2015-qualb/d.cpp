#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);

	set<pair<lint,lint>> S;
	S.emplace(-1,0);
	rep(i,n){
		lint x0,len; scanf("%lld%lld",&x0,&len);

		auto it=--S.lower_bound(make_pair(x0,-1));
		if(it->second<x0){
			++it;
		}
		else{
			x0=it->first;
			len+=it->second-it->first;
			it=S.erase(it);
		}

		lint x=x0;
		while(1){
			if(it==S.end() || it->first-x>=len){
				printf("%lld\n",x+len-1);
				if(it==S.end() || it->first-x>len){
					S.emplace(x0,x+len);
				}
				else{
					int r=it->second;
					S.erase(it);
					S.emplace(x0,r);
				}
				break;
			}

			len-=it->first-x;
			x=it->second;
			it=S.erase(it);
		}
	}

	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	set<int> S;
	rep(i,n){
		int a; scanf("%d",&a);
		if(S.count(a)==0) S.emplace(a);
		else              S.erase(a);
	}

	rep(_,q){
		int l,r,x; scanf("%d%d%d",&l,&r,&x);

		int res=0,cnt=0;
		auto it=S.lower_bound(l);
		while(it!=S.end() && *it<=r){
			res^=*it;
			cnt++;
			it=S.erase(it);
		}
		printf("%d\n",res);

		if(cnt%2==1){
			if(S.count(x)==0) S.emplace(x);
			else              S.erase(x);
		}
	}

	return 0;
}

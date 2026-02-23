#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,c; scanf("%d%d",&n,&c);
	multiset<int> S;
	rep(i,n){
		int a; scanf("%d",&a);
		S.emplace(a);
	}

	int ans=0;
	while(!S.empty()){
		int a=*S.rbegin();
		S.erase(--S.end());
		ans++;

		if(S.empty()) break;

		auto it=S.upper_bound(c-a-1);
		if(it!=S.begin()){
			--it;
			int b=*it;
			S.erase(it);
		}
	}
	printf("%d\n",ans);

	return 0;
}

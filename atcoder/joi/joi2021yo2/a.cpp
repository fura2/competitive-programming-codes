#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,x;
	string s; cin>>n>>x>>s;
	s='X'+s+'X';

	set<int> S;
	rep(i,n+2) if(s[i]!='.') S.emplace(i);

	lint ans=0;
	int dir=0;
	while(S.size()>2){
		set<int>::iterator it;
		if(dir==0){
			it=S.upper_bound(x);
		}
		else{
			it=prev(S.lower_bound(x));
		}
		ans+=abs(x-*it);
		x=*it;
		if(x!=0 && x!=n+1) S.erase(it);
		dir=1-dir;
	}
	printf("%lld\n",ans);

	return 0;
}

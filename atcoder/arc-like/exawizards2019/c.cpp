#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,q;
	string s; cin>>n>>q>>s;
	vector<char> c(q),dir(q);
	rep(i,q) cin>>c[i]>>dir[i];

	auto simulate=[&](int x){
		rep(i,q+1){
			if(x==-1) return -1;
			if(x== n) return  1;
			if(i<q && s[x]==c[i]) x+=(dir[i]=='L'?-1:1);
		}
		return 0;
	};

	int ans=n,lo=-1,hi=n;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		if(simulate(mi)==-1) lo=mi;
		else                 hi=mi;
	}
	ans-=lo+1;

	lo=-1; hi=n;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		if(simulate(mi)==1) hi=mi;
		else                lo=mi;
	}
	ans-=n-hi;

	cout<<ans<<'\n';

	return 0;
}

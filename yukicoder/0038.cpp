#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int kr,kb;
	string s; cin>>kr>>kb>>s;

	vector<int> r,b;
	rep(i,30){
		if(s[i]=='R') r.emplace_back(i);
		if(s[i]=='B') b.emplace_back(i);
	}

	int ans=0;
	rep(R,1<<10) rep(B,1<<10) {
		bool del[30]={};
		rep(i,10){
			if(R>>i&1) del[r[i]]=true;
			if(B>>i&1) del[b[i]]=true;
		}

		int len=0;
		char t[31]={};
		rep(i,30) if(!del[i]) t[len++]=s[i];

		bool ok=true;
		rep(i,len){
			if(i+kr<len && t[i]=='R' && t[i+kr]=='R') ok=false;
			if(i+kb<len && t[i]=='B' && t[i+kb]=='B') ok=false;
		}
		if(ok) ans=max(ans,len);
	}
	cout<<ans<<'\n';

	return 0;
}

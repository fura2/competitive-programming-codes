#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k;
	string s; cin>>n>>k>>s;

	vector nxt(n+1,vector(26,n));
	for(int i=n-1;i>=0;i--){
		rep(c,26) nxt[i][c]=min(nxt[i][c],nxt[i+1][c]);
		nxt[i][s[i]-'a']=i;
	}

	string ans;
	int pos=0;
	rep(i,k){
		for(char c='a';c<='z';c++){
			int p=nxt[pos][c-'a'];
			if(n-p>=k-i){
				ans+=c;
				pos=p+1;
				break;
			}
		}
	}
	cout<<ans<<'\n';

	return 0;
}

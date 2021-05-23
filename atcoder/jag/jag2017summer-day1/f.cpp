#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	vector<vector<int>> next(n+1,vector<int>(26,n+1));
	vector<vector<int>> prev(n+1,vector<int>(26, -1));
	for(int i=n-1;i>=0;i--){
		rep(c,26) next[i][c]=next[i+1][c];
		next[i][s[i]-'a']=i+1;
	}
	rep(i,n){
		rep(c,26) prev[i+1][c]=prev[i][c];
		prev[i+1][s[i]-'a']=i;
	}

	int q; cin>>q;
	rep(_,q){
		string t; cin>>t;
		int m=t.length();

		int r=0;
		rep(i,m) if(r<=n) r=next[r][t[i]-'a'];
		if(r>n){
			puts("-1");
			continue;
		}
		int l=r;
		rep(i,m) l=prev[l][t[m-1-i]-'a'];
		printf("%d %d\n",l+1,r);
	}

	return 0;
}

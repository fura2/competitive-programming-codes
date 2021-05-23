#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	bool A[26][26]={};
	rep(i,n){
		string s,t; cin>>s>>t;
		while(!s.empty() && !t.empty() && s[0]==t[0]){
			s=s.substr(1);
			t=t.substr(1);
		}
		if(!s.empty() && t.empty()){
			puts("-1");
			return 0;
		}
		if(!s.empty() && !t.empty()){
			A[s[0]-'a'][t[0]-'a']=true;
		}
	}

	int deg[26]={};
	rep(u,26) rep(v,26) if(A[u][v]) deg[v]++;

	int ans[26];
	bool used[26]={};
	rep(i,26){
		int u=-1;
		rep(v,26) if(!used[v] && deg[v]==0) {
			u=v;
			break;
		}
		if(u==-1){
			puts("-1");
			return 0;
		}

		used[u]=true;
		rep(v,26) if(A[u][v]) deg[v]--;
		ans[i]=u;
	}

	rep(u,26) putchar('a'+ans[u]);
	puts("");

	return 0;
}

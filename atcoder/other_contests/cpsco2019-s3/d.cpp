#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	vector<bool> vis(n-2);
	queue<int> Q;
	rep(i,n-2) if(s[i]=='R' && s[i+1]=='G' && s[i+2]=='B') {
		vis[i]=true;
		Q.emplace(i);
		s[i]=s[i+1]=s[i+2]='*';
	}

	while(!Q.empty()){
		int i=Q.front(); Q.pop();
		for(int d=-2;d<=2;d++) if(0<=i+d && i+d+3<=n && !vis[i+d]) {
			int cnt=0;
			if(s[i+d+0]=='R' || s[i+d+0]=='*') cnt++;
			if(s[i+d+1]=='G' || s[i+d+1]=='*') cnt++;
			if(s[i+d+2]=='B' || s[i+d+2]=='*') cnt++;
			if(cnt==3){
				vis[i+d]=true;
				Q.emplace(i+d);
				s[i+d]=s[i+d+1]=s[i+d+2]='*';
			}
		}
	}

	cout<<(count(s.begin(),s.end(),'*')==n?"Yes":"No")<<'\n';

	return 0;
}

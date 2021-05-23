#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,q; cin>>n>>q;

	vector d(1594323,INF);
	queue<int> Q;
	rep(i,n+1) for(int j=i;j<=n;j++) {
		int u=0;
		rep(x,n){
			if     (x<i) u=3*u;
			else if(x<j) u=3*u+1;
			else         u=3*u+2;
		}
		d[u]=0;
		Q.emplace(u);
	}
	while(!Q.empty()){
		int u=Q.front(); Q.pop();

		vector<int> a(n);
		{
			int tmp=u;
			rep(i,n){
				a[n-i-1]=tmp%3;
				tmp/=3;
			}
		}

		rep(i,n){
			reverse(a.begin(),a.begin()+i+1);
			int v=0;
			rep(j,n) v=3*v+a[j];
			if(d[v]==INF){
				d[v]=d[u]+1;
				Q.emplace(v);
			}
			reverse(a.begin(),a.begin()+i+1);
		}
	}

	rep(_,q){
		string s; cin>>s;
		int u=0;
		rep(i,n){
			if     (s[i]=='A') u=3*u;
			else if(s[i]=='B') u=3*u+1;
			else               u=3*u+2;
		}
		cout<<d[u]<<'\n';
	}

	return 0;
}

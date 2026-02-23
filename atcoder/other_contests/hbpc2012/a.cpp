#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int m,n; scanf("%d%d",&m,&n);

	const int OFS=300;
	int mn[601];
	rep(d,601) mn[d]=INF;
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b);
		mn[b-a+OFS]=min(mn[b-a+OFS],a);
	}

	int d[10301];
	rep(u,n+301) d[u]=INF;
	d[1]=1;
	queue<int> Q; Q.emplace(1);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int v=max(u-300,0);v<=u+300;v++) if(d[v]==INF && mn[v-u+OFS]<=u) {
			d[v]=d[u]+1;
			Q.emplace(v);
		}
	}
	printf("%d\n",d[n]<INF?d[n]:-1);

	return 0;
}

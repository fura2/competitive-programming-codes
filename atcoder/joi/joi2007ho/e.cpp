#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,p[100],q[100],l[100],r[100];

int dfs(int u){
	if(u==-1) return 1;
	int w1=dfs(l[u]);
	int w2=dfs(r[u]);
	int L=lcm(p[u]*w1,q[u]*w2);
	return L/p[u]+L/q[u];
}

int main(){
	scanf("%d",&n);
	rep(u,n) scanf("%d%d%d%d",&p[u],&q[u],&l[u],&r[u]), l[u]--, r[u]--;

	bool root[100]={};
	rep(u,n) root[u]=true;
	rep(u,n){
		if(l[u]!=-1) root[l[u]]=false;
		if(r[u]!=-1) root[r[u]]=false;
	}

	int r=find(root,root+n,true)-root;
	printf("%d\n",dfs(r));

	return 0;
}

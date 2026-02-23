#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

class lowest_common_ancestor{
	vector<int> dep;
	vector<vector<int>> par;
	const graph& T;

	void dfs(int u,int p,int d){
		dep[u]=d;
		par[0][u]=p;
		for(int v:T[u]) if(v!=p) dfs(v,u,d+1);
	}

public:
	lowest_common_ancestor(const graph& T,int root):T(T){
		int n=T.size(),h;
		for(h=1;(1<<h)<n;h++);

		dep.assign(n,0);
		par.assign(h,vector<int>(n,-1));

		dfs(root,-1,0);
		rep(i,h-1) rep(u,n) if(par[i][u]!=-1) par[i+1][u]=par[i][par[i][u]];
	}

	int lca(int u,int v)const{
		int h=par.size();

		if(dep[u]>dep[v]) swap(u,v);
		rep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];
		if(u==v) return u;

		for(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u], v=par[i][v];
		return par[0][u];
	}

	int dist(int u,int v)const{ return dep[u]+dep[v]-2*dep[lca(u,v)]; }
};

class segment_tree_dual{
	int n;
	vector<vector<int>> data;

	void push(int l,int r,int a,int b,int u,int val){
		if(l<=a && b<=r){
			data[u].emplace_back(val);
			return;
		}
		int c=(a+b+1)/2;
		if(l<c && a<r) push(l,r,a,c,2*u  ,val);
		if(l<b && c<r) push(l,r,c,b,2*u+1,val);
	}

	void pop(int l,int r,int a,int b,int u){
		if(l<=a && b<=r){
			data[u].pop_back();
			return;
		}
		int c=(a+b+1)/2;
		if(l<c && a<r) pop(l,r,a,c,2*u  );
		if(l<b && c<r) pop(l,r,c,b,2*u+1);
	}

public:
	segment_tree_dual(int N){
		for(n=1;n<N;n*=2);
		data.assign(2*n,{});
	}

	void push(int l,int r,int val){ push(l,r,0,n,1,val); }
	void pop (int l,int r){ pop(l,r,0,n,1); }

	int get(int u){
		for(u+=n;;u/=2) if(!data[u].empty()) return data[u].back();
	}
};

enum{LEFT,RIGHT,QUERY};
struct state{
	int type; // LEFT or RIGHT or QUERY
	int id,x;
	state(int t,int i,int x):type(t),id(i),x(x){}
	bool operator<(const state& S)const{ return x<S.x; }
};

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n+1),y(n+1),r(n+1);
	rep(i,n){
		int xx,yy; scanf("%d%d%d",&xx,&yy,&r[i]);
		x[i]=xx-yy;
		y[i]=xx+yy;
	}
	r[n]=1e9;

	int q; scanf("%d",&q);
	vector<int> xq(2*q),yq(2*q);
	rep(i,2*q){
		int xx,yy; scanf("%d%d",&xx,&yy);
		xq[i]=xx-yy;
		yq[i]=xx+yy;
	}

	// coordinate compression
	vector<int> Y;
	rep(i,n+1){
		Y.emplace_back(y[i]-r[i]);
		Y.emplace_back(y[i]+r[i]);
	}
	rep(i,2*q){
		Y.emplace_back(yq[i]);
	}
	sort(Y.begin(),Y.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());

	vector<int> par(n+1);   // par[i] = 正方形 i の親となる正方形の番号
	vector<int> pos(2*q); // pos[i] = 点 (xq[i], yq[i]) を含む最も深い正方形の番号
	segment_tree_dual ST(Y.size()); // y 軸に射影した区間の集合を管理する segment tree

	// plane sweep
	vector<state> Ev;
	rep(i,n+1){
		Ev.emplace_back(LEFT ,i,x[i]-r[i]);
		Ev.emplace_back(RIGHT,i,x[i]+r[i]);
	}
	rep(i,2*q){
		Ev.emplace_back(QUERY,i,xq[i]);
	}
	sort(Ev.begin(),Ev.end());
	for(state S:Ev){
		int id=S.id;
		if(S.type==LEFT){
			int y1=lower_bound(Y.begin(),Y.end(),y[id]-r[id])-Y.begin();
			int y2=lower_bound(Y.begin(),Y.end(),y[id]+r[id])-Y.begin();
			if(id!=n) par[id]=ST.get(y1);
			ST.push(y1,y2,id);
		}
		else if(S.type==RIGHT){
			int y1=lower_bound(Y.begin(),Y.end(),y[id]-r[id])-Y.begin();
			int y2=lower_bound(Y.begin(),Y.end(),y[id]+r[id])-Y.begin();
			ST.pop(y1,y2);
		}
		else{ // S.type==QUERY
			int y1=lower_bound(Y.begin(),Y.end(),yq[id])-Y.begin();
			pos[id]=ST.get(y1);
		}
	}

	graph T(n+1);
	rep(i,n){
		T[par[i]].emplace_back(i);
		T[i].emplace_back(par[i]);
	}
	lowest_common_ancestor LCA(T,n);
	rep(i,q){
		printf("%d\n",LCA.dist(pos[2*i],pos[2*i+1]));
	}

	return 0;
}

// Day 2: Salt

#include <bits/stdc++.h>
#include "grader.h"
#include "salt.h"

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n):n(n),p(n,-1){}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
};

vector<vector<int> > T;
bool del_v[1000],del_e[1000][1000];

int par[1000],sz[1000]; // par[u] = u の親, sz[u] = u を根とする部分木の頂点数

int dfs(int u,int p){
	sz[u]=1;
	par[u]=p;
	rep(i,T[u].size()){
		int v=T[u][i];
		if(v!=p && !del_e[u][v]){
			sz[u]+=dfs(v,u);
		}
	}
	return sz[u];
}

void play(int n,int E[][2]){
	T.resize(n);
	rep(i,n-1){
		E[i][0]--;
		E[i][1]--;
		int u=E[i][0],v=E[i][1];
		T[u].push_back(v);
		T[v].push_back(u);
	}

	while(1){
		int u_ans=-1,v_ans=-1;
		if(count(del_v,del_v+n,false)%2==0){ // 残りの頂点が偶数個のときは, 任意の辺を削除
			rep(i,n-1){
				int u=E[i][0],v=E[i][1];
				if(!del_e[u][v]){
					u_ans=min(u,v);
					v_ans=max(u,v);
					break;
				}
			}
		}
		else{ // 残りの頂点数が奇数個のときは, 適切な頂点を削除
			union_find U(n);
			rep(i,n-1){
				int u=E[i][0],v=E[i][1];
				if(!del_e[u][v]) U.unite(u,v);
			}
			int n_even=0; // 頂点数が偶数の連結成分の個数
			rep(u,n) if(!del_v[u] && U.find(u)==u && U.size(u)%2==0) n_even++;

			rep(u,n) if(!del_v[u] && U.find(u)==u) dfs(u,-1);

			rep(u,n) if(!del_v[u]) {
				int cnt=n_even;
				if(U.size(u)%2==0) cnt--;
				rep(i,T[u].size()){
					int v=T[u][i];
					if(!del_e[u][v]){
						int k; // u を取り除いたときの v を含む部分木の頂点数
						if(v==par[u]) k=U.size(u)-sz[u];
						else          k=sz[v];
						if(k%2==0) cnt++;
					}
				}
				if(cnt%2==0){
					u_ans=v_ans=u;
					break;
				}
			}
		}

		int ru,rv;
		turn(u_ans+1,v_ans+1,&ru,&rv);
		ru--;
		rv--;
		if(ru==-1) return;

		if(u_ans==v_ans){
			del_v[u_ans]=true;
			rep(i,T[u_ans].size()) del_e[u_ans][T[u_ans][i]]=del_e[T[u_ans][i]][u_ans]=true;
		}
		else{
			del_e[u_ans][v_ans]=del_e[v_ans][u_ans]=true;
		}
		if(ru==rv){
			del_v[ru]=true;
			rep(i,T[ru].size()) del_e[ru][T[ru][i]]=del_e[T[ru][i]][ru]=true;
		}
		else{
			del_e[ru][rv]=del_e[rv][ru]=true;
		}
	}
}

// Original Code (C++14), Compilation Error...
/*
#include <bits/stdc++.h>
#include "grader.h"
#include "salt.h"

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n):n(n),p(n,-1){}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
};

graph T;
bool del_v[1000],del_e[1000][1000];

int par[1000],sz[1000]; // par[u] = u の親, sz[u] = u を根とする部分木の頂点数

int dfs(int u,int p){
	sz[u]=1;
	par[u]=p;
	for(int v:T[u]) if(v!=p && !del_e[u][v]) {
		sz[u]+=dfs(v,u);
	}
	return sz[u];
}

void play(int n,int E[][2]){
	T.resize(n);
	rep(i,n-1){
		E[i][0]--;
		E[i][1]--;
		int u=E[i][0],v=E[i][1];
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}

	while(1){
		int u_ans=-1,v_ans=-1;
		if(count(del_v,del_v+n,false)%2==0){ // 残りの頂点が偶数個のときは, 任意の辺を削除
			rep(i,n-1){
				int u=E[i][0],v=E[i][1];
				if(!del_e[u][v]){
					u_ans=min(u,v);
					v_ans=max(u,v);
					break;
				}
			}
		}
		else{ // 残りの頂点数が奇数個のときは, 適切な頂点を削除
			union_find U(n);
			rep(i,n-1){
				int u=E[i][0],v=E[i][1];
				if(!del_e[u][v]) U.unite(u,v);
			}
			int n_even=0; // 頂点数が偶数の連結成分の個数
			rep(u,n) if(!del_v[u] && U.find(u)==u && U.size(u)%2==0) n_even++;

			rep(u,n) if(!del_v[u] && U.find(u)==u) dfs(u,-1);

			rep(u,n) if(!del_v[u]) {
				int cnt=n_even;
				if(U.size(u)%2==0) cnt--;
				for(int v:T[u]) if(!del_e[u][v]) {
					int k; // u を取り除いたときの v を含む部分木の頂点数
					if(v==par[u]) k=U.size(u)-sz[u];
					else          k=sz[v];
					if(k%2==0) cnt++;
				}
				if(cnt%2==0){
					u_ans=v_ans=u;
					break;
				}
			}
		}

		int ru,rv;
		turn(u_ans+1,v_ans+1,&ru,&rv);
		ru--;
		rv--;
		if(ru==-1) return;

		auto update=[](int u,int v){
			if(u==v){
				del_v[u]=true;
				for(int w:T[u]) del_e[u][w]=del_e[w][u]=true;
			}
			else{
				del_e[u][v]=del_e[v][u]=true;
			}
		};
		update(u_ans,v_ans);
		update(ru,rv);
	}
}
*/

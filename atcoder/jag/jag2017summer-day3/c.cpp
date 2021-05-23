#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

int main(){
	int n; scanf("%d",&n);
	int m=2*n*(n-1);
	graph G(n*n);
	vector<int> a(m),b(m);
	rep(i,m){
		scanf("%d%d",&a[i],&b[i]); a[i]--; b[i]--;
		add_undirected_edge(G,a[i],b[i]);
	}

	vector<int> deg(n*n);
	rep(i,m){
		deg[a[i]]++;
		deg[b[i]]++;
	}

	// u0 から出発して右と下に伸びるパスをそれぞれ求める
	auto calc=[&](int u0)->pair<vector<int>,vector<int>>{
		vector<vector<int>> res;
		for(int u1:G[u0]) if(2<=deg[u1] && deg[u1]<=3) {
			vector<int> seq={u0,u1};
			int u=u1,pre=u0;
			while(deg[u]==3){
				for(int v:G[u]) if(v!=pre && 2<=deg[v] && deg[v]<=3) {
					seq.emplace_back(v);
					pre=u;
					u=v;
					break;
				}
			}
			res.emplace_back(seq);
		}
		return {res[0],res[1]};
	};

	vector ans(n,vector(n,-1));
	int u0=find(deg.begin(),deg.end(),2)-deg.begin();
	rep(i,n-1){
		auto [seq1,seq2]=calc(u0);
		assert(seq1.size()==n-i && seq2.size()==n-i);

		if(i>0){
			bool sw=true;
			for(int v:G[seq1.back()]) if(v==ans[i-1][n-1]) sw=false;
			if(sw) swap(seq1,seq2);
		}

		rep(j,n-i){
			ans[i][i+j]=seq1[j];
			ans[i+j][i]=seq2[j];
		}

		for(int j=1;j<n-i;j++){
			int u=seq1[j];
			for(int v:G[u]) if(j==n-i-1 || v!=seq1[j+1]) {
				deg[u]--;
				deg[v]--;
			}
			u=seq2[j];
			for(int v:G[u]) if(j==n-i-1 || v!=seq2[j+1]) {
				deg[u]--;
				deg[v]--;
			}
		}

		if(i<n-2){
			u0=-1;
			rep(u,n*n) if(deg[u]==2) {
				int cnt=0;
				for(int v:G[u]) if(v==seq1[1] || v==seq2[1]) cnt++;
				if(cnt==2) u0=u;
			}
			assert(u0!=-1);
		}
	}

	vector used(n*n,false);
	rep(i,n) rep(j,n) if(i<n-1 || j<n-1) used[ans[i][j]]=true;
	rep(i,n) rep(j,n) if(!used[i*n+j])  ans[n-1][n-1]=i*n+j;

	rep(i,n) rep(j,n) printf("%d%c",ans[i][j]+1,j<n-1?' ':'\n');

	return 0;
}

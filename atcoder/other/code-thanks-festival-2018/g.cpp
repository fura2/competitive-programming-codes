#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<vector<int>> cycles(const vector<int>& f){
	int n=f.size();
	vector<vector<int>> res;
	vector<int> color(n,-1);
	rep(u,n) if(color[u]==-1) {
		int v=u;
		do{ color[v]=u; v=f[v]; }while(color[v]==-1);
		if(color[v]==u){
			vector<int> C;
			int w=v;
			do{ C.emplace_back(v); v=f[v]; }while(v!=w);
			res.emplace_back(C);
		}
	}
	return res;
}

const int INF=1<<29;

vector<int> calc(vector<int> f){
	int n=f.size();

	if(n==1) return {-INF,f[0]+1};

	static int dp[5000][5001][2];
	rep(i,n) rep(j,n+1) rep(k,2) dp[i][j][k]=-INF;
	// choose f[0]
	dp[0][1][0]=f[0]+1;
	for(int i=1;i<n-1;i++){ // edge (f[i], f[i+1])
		rep(j,i+1){
			// choose f[i]
			dp[i][j+1][0]=max(dp[i][j+1][0],dp[i-1][j][0]+(f[i]+1));
			dp[i][ j ][0]=max(dp[i][ j ][0],dp[i-1][j][1]+(f[i]+1));
			// choose f[i+1]
			dp[i][j+1][1]=max(dp[i][j+1][1],dp[i-1][j][0]+(f[i+1]+1));
			dp[i][j+1][1]=max(dp[i][j+1][1],dp[i-1][j][1]+(f[i+1]+1));
		}
	}
	// edge (f[n-1], f[0])
	rep(j,n+1){
		if(j<n) dp[n-1][j+1][0]=max(dp[n-1][j+1][0],dp[n-2][j][0]+(f[n-1]+1));
		dp[n-1][j][0]=max(dp[n-1][j][0],dp[n-2][j][1]+(f[n-1]+1));
		dp[n-1][j][0]=max(dp[n-1][j][0],dp[n-2][j][0]+(f[0]+1));
		dp[n-1][j][0]=max(dp[n-1][j][0],dp[n-2][j][1]+(f[0]+1));
	}

	vector<int> res1(n+1);
	rep(j,n+1) res1[j]=dp[n-1][j][0];

	rep(i,n) rep(j,n+1) rep(k,2) dp[i][j][k]=-INF;
	// choose f[1]
	dp[0][1][1]=f[1]+1;
	for(int i=1;i<n-1;i++){ // edge (f[i], f[i+1])
		rep(j,i+1){
			// choose f[i]
			dp[i][j+1][0]=max(dp[i][j+1][0],dp[i-1][j][0]+(f[i]+1));
			dp[i][ j ][0]=max(dp[i][ j ][0],dp[i-1][j][1]+(f[i]+1));
			// choose f[i+1]
			dp[i][j+1][1]=max(dp[i][j+1][1],dp[i-1][j][0]+(f[i+1]+1));
			dp[i][j+1][1]=max(dp[i][j+1][1],dp[i-1][j][1]+(f[i+1]+1));
		}
	}
	// edge (f[n-1], f[0])
	rep(j,n+1){
		if(j<n) dp[n-1][j+1][0]=max(dp[n-1][j+1][0],dp[n-2][j][0]+(f[n-1]+1));
		dp[n-1][j][0]=max(dp[n-1][j][0],dp[n-2][j][1]+(f[n-1]+1));
		if(j<n) dp[n-1][j+1][0]=max(dp[n-1][j+1][0],dp[n-2][j][0]+(f[0]+1));
		if(j<n) dp[n-1][j+1][0]=max(dp[n-1][j+1][0],dp[n-2][j][1]+(f[0]+1));
	}

	vector<int> res2(n+1);
	rep(j,n+1) res2[j]=dp[n-1][j][0];

	vector<int> res(n+1);
	rep(j,n+1) res[j]=max(res1[j],res2[j]);
	return res;
}

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;
	rep(i,n) scanf("%d",&b[i]), b[i]--;

	vector<int> f(n);
	rep(i,n) f[a[i]]=b[i];

	auto C=cycles(f);

	vector dp(C.size()+1,vector(n+1,-INF));
	dp[0][0]=0;
	int len=0;
	rep(i,C.size()){
		int u0=C[i][0];
		vector<int> g={u0};
		for(int u=f[u0];u!=u0;u=f[u]){
			g.emplace_back(u);
		}
		auto tmp=calc(g);

		rep(j1,len+1) rep(j2,C[i].size()+1) {
			dp[i+1][j1+j2]=max(dp[i+1][j1+j2],dp[i][j1]+tmp[j2]);
		}
		len+=C[i].size();
	}

	int ans=-INF;
	for(int j=k;j<=n;j++) ans=max(ans,dp[C.size()][j]);
	printf("%d\n",ans);

	return 0;
}

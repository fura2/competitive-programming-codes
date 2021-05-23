#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

vector<vector<int>> find_cycles(const vector<int>& f){
	int n=f.size();
	vector<vector<int>> Res;
	vector<int> color(n,-1);
	rep(u,n) if(color[u]==-1) {
		int v=u;
		do{ color[v]=u; v=f[v]; }while(color[v]==-1);
		if(color[v]==u){
			vector<int> C;
			int w=v;
			do{ C.emplace_back(v); v=f[v]; }while(v!=w);
			Res.emplace_back(C);
		}
	}
	return Res;
}

int main(){
	int n;
	lint k; scanf("%d%lld",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;

	lint cnt=0;
	for(auto C:find_cycles(a)) cnt+=C.size()-1;

	puts(cnt<=k&&(k-cnt)%2==0?"YES":"NO");

	return 0;
}

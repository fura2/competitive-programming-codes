#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<pair<int,int>> E(m);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		E[i]={u,v};
	}

	vector<bitset<120>> ans;
	rep(S,1<<(n-1)){
		bitset<120> tmp;
		rep(i,m){
			int u,v; tie(u,v)=E[i];
			if((S>>u&1)!=(S>>v&1)) tmp.set(i,1);
		}

		for(auto it=ans.begin();it!=ans.end();){
			if(((*it)&tmp)==*it){
				it=ans.erase(it);
			}
			else ++it;
		}

		bool larger=true;
		for(auto it=ans.begin();it!=ans.end();){
			if(((*it)&tmp)==tmp){
				larger=false;
				break;
			}
			else ++it;
		}
		if(larger) ans.emplace_back(tmp);
	}

	printf("%ld\n",ans.size());

	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,n; cin>>h>>w>>n;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector<int> p(n);
	rep(i,n) cin>>p[i];

	vector id(w,vector<int>());
	rep(i,n){
		rep(dx,3) id[p[i]+dx].emplace_back(i);
	}

	vector ans(n,vector<string>(3,"..."));
	vector<int> cnt(n);
	rep(x,w){
		int len=0;
		rep(y,h) if(B[y][x]=='#') { len=h-y; break; }

		sort(id[x].begin(),id[x].end(),[&](int i,int j){
			return make_pair(cnt[i],p[i])<make_pair(cnt[j],p[j]);
		});

		rep(_,3){
			for(int i:id[x]){
				if(len==0) break;

				int dx=x-p[i];
				int dy;
				for(dy=2;dy>=0;dy--) if(ans[i][dy][dx]=='.') break;
				if(dy>=0){
					cnt[i]++;
					ans[i][dy][dx]='#';
					len--;
				}
			}
		}
	}

	rep(i,n) rep(dy,3) cout<<ans[i][dy]<<'\n';

	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	rep(i,k){
		int x; scanf("%d%*d",&x); x--;
		swap(p[x],p[x+1]);
	}
	vector<int> g(n);
	rep(i,n) scanf("%d",&g[i]), g[i]--;

	vector<int> ans;
	rep(i,n){
		int t=find(g.begin(),g.end(),i)-g.begin();
		int j=find(p.begin(),p.end(),t)-p.begin();
		if(i<=j){
			for(int k=j-1;k>=i;k--){
				swap(p[k],p[k+1]);
				ans.emplace_back(k);
			}
		}
		else{
			for(int k=j;k<i;k++){
				swap(p[k],p[k+1]);
				ans.emplace_back(k);
			}
		}
	}

	printf("%lu\n",ans.size());
	for(int x:ans) printf("%d %d\n",x+1,x+2);

	return 0;
}

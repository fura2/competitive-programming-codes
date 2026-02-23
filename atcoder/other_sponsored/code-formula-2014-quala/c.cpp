#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector a(n,vector(k,0));
	rep(i,n) rep(j,k) scanf("%d",&a[i][j]);

	int cnt=0;
	vector<bool> pass(1000000);
	rep(t,n){
		vector<int> res;
		rep(j,k) rep(i,t+1) {
			if(!pass[a[i][j]] && cnt+j*(n-1-t)<k){
				pass[a[i][j]]=true;
				cnt++;
				res.emplace_back(a[i][j]);
			}
		}
		sort(res.begin(),res.end());

		rep(i,res.size()) printf("%d%s",res[i],i+1<res.size()?" ":"");
		puts("");
	}


	return 0;
}

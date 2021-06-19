#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=0,cnt=0;
	map<int,int> f;
	for(int l=0,r=0;l<n;l++){
		while(r<n){
			if(f[a[r]]==0){
				if(cnt==k) break;
				cnt++;
			}
			++f[a[r]];
			r++;
		}
		if(cnt<=k) ans=max(ans,r-l);
		--f[a[l]];
		if(f[a[l]]==0) cnt--;
	}
	printf("%d\n",ans);

	return 0;
}

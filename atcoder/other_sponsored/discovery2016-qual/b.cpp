#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(2*n);
	rep(i,n) scanf("%d",&a[i]), a[n+i]=a[i];

	vector<int> nxt1(n),nxt2(n);
	map<int,int> f;
	for(int i=2*n-1;i>=n;i--) f[a[i]]=i;
	for(int i=n-1;i>=0;i--){
		nxt1[i]=f[a[i]];
		auto it=f.upper_bound(a[i]);
		if(it!=f.end()){
			nxt2[i]=it->second;
		}
		f[a[i]]=i;
	}

	int ans=1;
	int x=min_element(a.begin(),a.end())-a.begin();
	vector<bool> vis(n);
	rep(_,n-1){
		vis[x]=true;
		if(!vis[nxt1[x]%n]){
			if(nxt1[x]>=n) ans++;
			x=nxt1[x]%n;
		}
		else{
			if(nxt2[x]>=n) ans++;
			x=nxt2[x]%n;
		}
	}
	if(n>=2 && x==0) ans--;
	printf("%d\n",ans);

	return 0;
}

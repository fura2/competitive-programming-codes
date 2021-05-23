#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,w; scanf("%d%d",&n,&w);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);
	a.emplace_back(w+1);

	int ans=0,sum=0,dup=0;
	map<int,int> f;
	for(int l=0,r=-1;l<n;){
		while(sum<=w && dup==0){
			r++;
			sum+=a[r];
			++f[a[r]];
			if(f[a[r]]==2) dup++;
		}

		ans=max(ans,r-l);

		sum-=a[l];
		--f[a[l]];
		if(f[a[l]]==1) dup--;
		l++;
	}
	printf("%d\n",ans);

	return 0;
}

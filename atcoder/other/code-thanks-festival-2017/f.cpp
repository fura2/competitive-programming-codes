#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=1000000007;

int main(){
	int n,tar; scanf("%d%d",&n,&tar);
	vector<int> a(n+1);
	rep(i,n) scanf("%d",&a[i]);
	a[n]=tar;

	int rank=0;
	rep(j,17){
		int idx=-1;
		for(int i=rank;i<n;i++) if(a[i]>>j&1) { idx=i; break; }
		if(idx==-1) continue;

		swap(a[idx],a[rank]);
		for(int i=rank+1;i<n+1;i++) if(a[i]>>j&1) a[i]^=a[rank];
		rank++;
	}

	if(a[n]!=0) return puts("0"),0;

	int ans=1;
	rep(i,n-rank) ans=ans*2%MOD;
	printf("%d\n",ans);

	return 0;
}

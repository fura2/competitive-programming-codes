#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> b(n-23);
	{
		int sum=0;
		rep(i,23) sum+=a[i];
		for(int i=23;i<n;i++){
			sum+=a[i];
			b[i-23]=sum;
			sum-=a[i-23];
		}
	}

	int ans=*max_element(b.begin(),b.end());

	int q; scanf("%d",&q);
	rep(_,q){
		int t,v; scanf("%d%d",&t,&v); t--;
		for(int i=max(t-23,0);i<min(t+1,n-23);i++){
			b[i]+=v-a[t];
			ans=max(ans,b[i]);
		}
		a[t]=v;
		printf("%d\n",ans);
	}

	return 0;
}

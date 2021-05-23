#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	lint sum[2][200001]={};
	rep(dir,2){
		auto tmp=a;

		vector<int> right(n);
		rep(i,n) right[i]=i;

		for(int i=n-2;i>=0;i--){
			sum[dir][i]=sum[dir][i+1];
			int pos=i;
			while(pos<n-1 && a[pos]>a[pos+1]){
				int r=right[pos+1];
				while(a[pos]>a[pos+1]){
					sum[dir][i]+=2*(r-pos);
					a[pos+1]*=4;
					if(pos+1<r) a[r]*=4;
				}
				pos=r;
			}
			right[i]=pos;
		}

		a=tmp;
		reverse(a.begin(),a.end());
	}

	lint ans=INF;
	rep(i,n+1) ans=min(ans,sum[0][i]+sum[1][n-i]+i);
	printf("%lld\n",ans);

	return 0;
}

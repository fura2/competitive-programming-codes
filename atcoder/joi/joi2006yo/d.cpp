#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n;
	lint m; cin>>n>>m;
	int pos[15];
	rep(i,3){
		int k; cin>>k;
		rep(j,k){
			int a; scanf("%d",&a); a--;
			pos[a]=i;
		}
	}

	lint f[16]={}; // f[i] = (i 個重なったコップを A から B に移動させるコスト)
	rep(i,n) f[i+1]=3*f[i]+1;

	lint ans=INF;
	rep(t,2){
		lint cnt=0;
		int x=(t==0?0:2);
		rep(i,n){
			int d=abs(pos[i]-x);
			if(d==1){
				cnt+=2*f[n-i-1]+1;
				if     (x==0) x=2;
				else if(x==1) x=2-pos[i];
				else          x=0;
			}
			else if(d==2){
				cnt+=4*f[n-i-1]+2;
			}
		}
		ans=min(ans,cnt);
	}
	printf("%lld\n",ans<=m?ans:-1);

	return 0;
}

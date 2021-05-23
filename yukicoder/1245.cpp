#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);
	string s; cin>>s;

	lint sum[30][2]={};
	rep(d,30){
		sum[d][0]=0;
		int x;
		rep(j,2){
			x=j;
			rep(i,n){
				if(s[i]=='0'){ // and
					if(x==1 && (a[i]>>d&1)==0) sum[d][j]+=1LL<<d, x=0;
				}
				else{ // or
					if(x==0 && (a[i]>>d&1)==1) sum[d][j]+=1LL<<d, x=1;
				}
			}
		}
	}

	rep(_,q){
		int t; scanf("%d",&t);

		lint ans=0;
		rep(d,30) ans+=sum[d][t>>d&1];
		printf("%lld\n",ans);
	}

	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int total=accumulate(a.begin(),a.end(),0);
	vector<int> sum(n),cnt(n);
	vector know(n,vector(n,false));
	rep(i,n){
		sum[i]+=a[i];
		cnt[i]=1;
		know[i][i]=true;
	}

	int q; scanf("%d",&q);
	rep(_,q){
		int t,b,c; scanf("%d%d%d",&t,&b,&c); b--; c--;
		if(t==0){
			sum[b]+=a[c];
			cnt[b]++;
			know[b][c]=true;
		}
		else{
			if(know[b][c]){
				printf("%d %d\n",a[c],a[c]);
			}
			else{
				printf("%d %d\n",max((total-sum[b])-100*(n-cnt[b]-1),0),min(total-sum[b],100));
			}
		}
	}

	return 0;
}

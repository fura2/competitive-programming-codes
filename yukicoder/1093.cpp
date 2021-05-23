#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> S;
	int sum=0;
	rep(i,k-1) sum+=a[i];
	for(int i=k-1;i<n;i++){
		sum+=a[i];
		S.emplace_back(sum);
		sum-=a[i-k+1];
	}
	sort(S.begin(),S.end());

	int q; scanf("%d",&q);
	rep(_,q){
		int x; scanf("%d",&x);
		printf("%ld\n",upper_bound(S.begin(),S.end(),x)-S.begin());
	}

	return 0;
}

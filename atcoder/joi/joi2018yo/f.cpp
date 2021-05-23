#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k;
	lint l; scanf("%d%d%lld",&n,&k,&l);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int lo=1,hi=n+1;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		// 答えが mi 以上かどうかを判定
		vector<int> b(n);
		rep(i,n) b[i]=(a[i]<mi);
		lint res=0; // b の連続部分列であって, 和が K 以上であるものの個数
		for(int l=0,r=0,cnt=0;l<n;){
			while(r<n && cnt<k){
				cnt+=b[r];
				r++;
			}
			if(cnt==k) res+=n-r+1;
			cnt-=b[l];
			l++;
		}

		if(res<l) lo=mi;
		else      hi=mi;
	}
	printf("%d\n",lo);

	return 0;
}

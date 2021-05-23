#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int lo=0,hi=n+1;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		bool ok=false;
		int dup=0;
		static int cnt[1000001];
		rep(i,mi){
			cnt[a[i]]++;
			if(cnt[a[i]]==2) dup++;
		}
		for(int i=mi;i<=n;i++){
			if(dup==0) ok=true;
			if(i<n){
				cnt[a[i]]++;
				if(cnt[a[i]]==2) dup++;
				cnt[a[i-mi]]--;
				if(cnt[a[i-mi]]==1) dup--;
			}
		}

		if(ok) lo=mi;
		else   hi=mi;

		rep(i,n) cnt[a[i]]=0;
	}
	printf("%d\n",lo);

	return 0;
}

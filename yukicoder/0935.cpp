#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	string s; cin>>n>>s;
	vector<lint> a(n);
	rep(i,n) cin>>a[i];

	int q; cin>>q;
	rep(_,q){
		int pw; cin>>pw;

		int ans=0,cnt=0,r=0;
		lint sum=0;
		rep(l,n){
			while(r<n && sum+a[r]<=pw){
				sum+=a[r];
				if(s[r]=='E') cnt++;
				r++;
			}
			ans=max(ans,cnt);
			sum-=a[l];
			if(s[l]=='E') cnt--;
		}
		printf("%d\n",ans);
	}

	return 0;
}

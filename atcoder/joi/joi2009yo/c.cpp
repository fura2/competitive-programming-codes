#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int go(const vector<int>& a,int i0){
	int n=a.size();
	int l=i0,r=i0,del=0;
	while(0<=l && r<n){
		if(a[l]!=a[r]) break;

		int c=a[l],l0=l,r0=r;
		while(l>0 && a[l-1]==c) l--;
		while(r<n-1 && a[r+1]==c) r++;

		int num=(r-r0+1)+(l0-l+1);
		if(l0==i0) num--;
		if(num<4) break;

		del+=num;
		l--;
		r++;
	}
	return n-del;
}

int main(){
	int n; cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i], a[i]--;

	int ans=n;
	rep(i,n) rep(j,3) if(a[i]!=j) {
		int tmp=a[i];
		a[i]=j;
		ans=min(ans,go(a,i));
		a[i]=tmp;
	}
	cout<<ans<<endl;

	return 0;
}

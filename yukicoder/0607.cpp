#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(t,m){
		rep(i,n){
			int d; scanf("%d",&d);
			a[i]+=d;
		}

		int l=0,sum=0;
		rep(r,n+1){
			while(l<r && sum>777) sum-=a[l], l++;
			if(sum==777) return puts("YES"),0;
			if(r<n) sum+=a[r];
		}
	}
	puts("NO");

	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	rep(_,3){
		int a[6];
		rep(i,6) cin>>a[i];
		int t0=3600*a[0]+60*a[1]+a[2];
		int t1=3600*a[3]+60*a[4]+a[5];
		cout<<(t1-t0)/3600<<' '<<(t1-t0)/60%60<<' '<<(t1-t0)%60<<'\n';
	}
	return 0;
}

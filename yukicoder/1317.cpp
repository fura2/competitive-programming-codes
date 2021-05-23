#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	int a[6],b[6];
	string s;
	rep(i,6) cin>>a[i];
	rep(i,6) cin>>b[i];
	cin>>s;

	map<string,int> f;
	f["AC"]=0;
	f["WA"]=1;
	f["TLE"]=2;
	f["MLE"]=3;
	f["OLE"]=4;
	f["RE"]=5;

	if(a[f[s]]>0){
		puts("No");
		return;
	}
	for(int i=1;i<6;i++) if(i!=f[s] && b[i]>0) {
		puts("No");
		return;
	}
	puts(a[0]>=b[0]?"Yes":"No");
}

int main(){
	int t; scanf("%d",&t); rep(_,t) solve();
	return 0;
}
